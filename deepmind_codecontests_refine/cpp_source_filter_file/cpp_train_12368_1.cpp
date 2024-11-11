#include<stdio.h>
int main()
{
	double w,h,x,y;
	scanf("%lf %lf %lf %lf",&w,&h,&x,&y);
	max=(w*h)/2;
	printf("%lf",max);
	if(2*x==w&&2*y==h)
	printf(" 1");
	else printf(" 0");
}