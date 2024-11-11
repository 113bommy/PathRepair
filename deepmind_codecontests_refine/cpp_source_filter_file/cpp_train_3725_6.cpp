#include<cstdio>
#include<cmath>
int a,b,h,m;
double szj,fzj,j;
int main()
{
	scanf("%d%d%d%d",a,b,h,m);
	szj=(h*60+m)*0.5;
	fzj=6*m;
	j=abs(szj-fzj);
	if(j>180)j=360-j;
	printf("%20f",sqrt(a*a+b*b-2*cos(j*M_PIE/180)*a*b));
	return 0;
}