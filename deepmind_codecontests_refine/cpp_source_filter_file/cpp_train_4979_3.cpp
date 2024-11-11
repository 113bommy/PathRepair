#include<stdio.h>

int main(void)
{

	int a,b;
	
	scanf("%d %d",&a,&b);
	
	if(a*b==15)
	{
		printf("*");
	}
	else if(a+b==15)
	{
		printf("+")
	}
	{
		printf("x")
	}
	
	return 0;

}