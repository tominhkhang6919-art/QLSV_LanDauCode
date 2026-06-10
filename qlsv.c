#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <ctype.h> 

typedef struct{
	int day, month, year;
}birthday;

typedef struct{
	float exam1, exam2, exam3;
	float average; 
	int drl;
	char evaluate [200]; 
}mark;  

typedef struct{
	char full_name [70];
	char home_town [50];
	char major_class [50];
	char cohort [20]; 
	char ID [20]; 
}ifm;

typedef struct{
	birthday date;
	mark score;
	ifm information; 
}sinhvien;

void list_sv(sinhvien sv[], int quantity){
	int i;
	for(i = 0; i< quantity; i++){
		printf("=====Nhap Thong Tin Sinh Vien %d=====\n", i+1); 
		
		printf("Nhap day du Ho va Ten: ");
		fgets(sv[i].information.full_name, 70, stdin); 
		sv[i].information.full_name[strcspn(sv[i].information.full_name, "\n")] = '\0'; 
		
		printf("Ngay, thang, nam sinh: ");
		scanf("%d %d %d", &sv[i].date.day, &sv[i].date.month, &sv[i].date.year);
		getchar(); 
		
		printf("Dia chi lien lac (Que quan): ");
		fgets(sv[i].information.home_town, 50, stdin);
		sv[i].information.home_town[strcspn(sv[i].information.home_town, "\n")] = '\0';
		
		printf("Thong tin Nganh va Lop: ");
		fgets(sv[i].information.major_class, 50, stdin);
		sv[i].information.major_class[strcspn(sv[i].information.major_class, "\n")] = '\0';
		
		printf("Nhap Mssv: ");
		fgets(sv[i].information.ID, 20, stdin);
		sv[i].information.ID[strcspn(sv[i].information.ID, "\n")] = '\0';
		
		printf("Nhap khoa hoc: ");
		fgets(sv[i].information.cohort, 20,stdin);
		sv[i].information.cohort[strcspn(sv[i].information.cohort, "\n")] = '\0';
	} 
} 

void list_result(sinhvien sv[], int quantity){
	int i;
	for(i = 0; i< quantity; i++){
		printf("=====Nhap Ket Qua cua SV %d=====\n", i +1);
		printf("Nhap diem 3 bai ktra: ");
		scanf("%f %f %f", &sv[i].score.exam1, &sv[i].score.exam2, &sv[i].score.exam3);
		
		sv[i].score.average = ( sv[i].score.exam1 + sv[i].score.exam2 + sv[i].score.exam3 ) / 3;
		
		printf("Diem ren luyen: ");
		scanf("%d",&sv[i].score.drl);
		getchar();
		 
		printf("Ghi danh gia: ");
		fgets(sv[i].score.evaluate, 200, stdin);
		sv[i].score.evaluate[strcspn(sv[i].score.evaluate, "\n")] = '\0';
	} 
}

void output_list_sv(sinhvien sv[], int quantity){
	int i;
	for(i = 0; i< quantity; i++){
		printf("\n======THONG TIN SINH VIEN %d======\n", i+1); 
		printf("Ho va Ten: %s\n", sv[i].information.full_name);
		printf("Ngay, thang, nam sinh: %02d-%02d-%04d\n", sv[i].date.day, sv[i].date.month, sv[i].date.year); 
		printf("Que quan: %s\n",sv[i].information.home_town);
		printf("Nganh hoc: %s\n",sv[i].information.major_class);
		printf("Ma so sinh vien: %s\n",sv[i].information.ID);
		printf("Khoa hoc: %s\n", sv[i].information.cohort); 
		
		printf("*****KET QUA CUA SINH VIEN %d*****\n", i+1); 
		printf("Diem so 3 mon va drl cua sv\n");
		printf("Mon 1: %.2f\t Mon2: %.2f\t Mon 3: %.2f\n", sv[i].score.exam1, sv[i].score.exam2, sv[i].score.exam3); 
		
		printf("Diem trung binh: %.2f\t DRL: %d \n", sv[i].score.average, sv[i].score.drl);
		
		if(sv[i].score.average >= 9 && sv[i].score.drl >= 90) printf("Xep loai: Xuat sac\n");
		else if(sv[i].score.average >= 8 && sv[i].score.drl >= 80) printf("Xep loai: Gioi\n");
		else if(sv[i].score.average >= 6.5 && sv[i].score.drl >= 70) printf("Xep loai: Kha\n");
		else if(sv[i].score.average >= 5 && sv[i].score.drl >= 60) printf("Xep loai: Trung binh\n");
		else printf("Xep loai: Khong dat\n");
		  
		printf("Danh gia cua giang vien: %s",sv[i].score.evaluate);	
	} 
	printf("\n"); 
} 

void to_lower(char *str, char *result){
	int i;
	for(i = 0; str[i]; i++){
		result[i] = tolower(str[i]); 
	} 
	result[i] = '\0'; 
} 

void find(sinhvien sv[], int quantity){
	char ten[70];
	printf("Nhap ten can tim: ");
	getchar();
	fgets(ten, 70, stdin);
	ten[strcspn(ten, "\n")]	= '\0';
	
	if(strlen(ten) < 3){
        printf("Vui long nhap it nhat 3 ky tu!\n");
        return;
    }
	
	int found = 0;
	int i;
	char ten_lower[70], sv_lower[70];
	to_lower(ten, ten_lower); 
	
	for(i = 0; i< quantity; i++){
		to_lower(sv[i].information.full_name, sv_lower); 
		if(strstr(sv_lower, ten_lower) != NULL){
			output_list_sv(&sv[i],1);
			found = 1; 
		} 
	} 
	
	if(found == 0){
		printf("Khong tim thay sinh vien!\n"); 
	} 
}

void Menu(){
	printf("====== MENU ======\n");
	printf("1. Nhap danh sach thong tin sinh vien\n");
	printf("2. Xuat danh sach thong tin sinh vien\n");
	printf("3. Tim ten sinh vien\n");
	printf("0. Thoat\n");
	printf("===================\n");
	printf("Chon chuc nang: "); 
} 

int main(){
	int quantity = 0;
	sinhvien *sv = NULL; 
	int choice;
	
	do {
		Menu();
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				if (sv != NULL) free(sv); 
				
				printf("Nhap so sinh vien can sap xep: ");
				scanf("%d", &quantity);
				getchar();
	
				if(quantity <= 0){
					printf("Khong hop le!\n");
					break; 
				} 
	
				sv= (sinhvien *)malloc(quantity *sizeof(sinhvien));
	
				if(sv == NULL){
					printf("Khong du bo nho!\n");
					break; 
				} 
	
				list_sv(sv, quantity);
				list_result(sv, quantity);
				printf("Da xong!\n");
				break; 

			
			case 2:
				if(sv == NULL) printf("Chua có du lieu!\n"); 
				else output_list_sv(sv, quantity);
				break;
			
			case 3:
				if(sv == NULL) printf("Chua co du lieu!\n");
				else find(sv, quantity); 
				break; 
			
			case 0:
				printf("Thoat chuong trinh!\n");
				break;
					
			default:
				printf("Chon sai, hay chon lai!\n"); 
		}
	} while(choice != 0); 
				 
	if (sv != NULL) free(sv); 
	return 0;
} 