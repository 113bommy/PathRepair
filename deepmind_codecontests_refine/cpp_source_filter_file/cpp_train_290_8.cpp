#include<stdio.h>

int main(void){
	int n;
	scanf("%d",&n);
	int a[n];
	int sum = 0;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		sum += a[i];
	
	}
	printf("%d",a[i]-n);
	return 0;
}