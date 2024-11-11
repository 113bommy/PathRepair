#include<stdio.h>
char a,b;
int main(){
	scanf("%c %c",&a,&b);
  	printf("%c",a>b?'>':(a==b?'=':'<'));
    return 0;
}
