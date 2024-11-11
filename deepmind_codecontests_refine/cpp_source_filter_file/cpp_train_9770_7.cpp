#include<stdio.h>
int main(void)
{
	int a,b;
	scanf("%d %d",&a,&b);
	a=a+b;
	if(a>9)	printf("error\n");
	else    printf("%d",a);
	retrn 0;
}