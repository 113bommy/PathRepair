#include<stdio.h>
char a,b;
int main(){
	scanf("%c",&a,&b);
  	printf("%d",a>b?'>':(a==b?'=':'<');
    return 0;
}