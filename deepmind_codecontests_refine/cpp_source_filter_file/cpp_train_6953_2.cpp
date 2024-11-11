#include<stdio.h>
	int main(){
		int a;
		scanf("%d",&a);
		
		for (int i =1 ;i<=9 ; i++){
			for(int j=1;j<=9;j++){
				if(i*j==a){
					puts("Yes");
					return 0;
				}
			}
		}

	puts("No")	
}