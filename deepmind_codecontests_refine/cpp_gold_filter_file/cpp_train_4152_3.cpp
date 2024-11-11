#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	double x,y,sum=0;
	double x1,x2,y1,y2,x3,y3,s,a,b,c;
	scanf("%lf,%lf",&x1,&y1);
	scanf("%lf,%lf",&x2,&y2);
	while(scanf("%lf,%lf",&x3,&y3)!=EOF){
		a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
		c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		s=(a+b+c)/2;
		sum+=sqrt(s*(s-a)*(s-b)*(s-c));
		x2=x3;y2=y3;
		
	}
	printf("%.6lf\n",sum);
	return 0;
}
	