#include<stdio.h>
#include<math.h>
int main(void)
{
	double x,h,S,y,l;
	while(1){
	scanf("%lf %lf",&x,&h);
	if(x==0 && h==0){
		break;
	}
	y=x*x;
	l=sqrt(h*h+(x/2)*(x/2))*x*2;
	S=y+l;
	printf("%f\n",S);
	}
	return 0;