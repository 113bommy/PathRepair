#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
	int num;
	cin>>num;
	for(int i=0;i<n;i++){
		double a,b,c,d,e,f;
		double x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
	
		a=x1-x2;
		b=y1-y2;
		c=x2-x3;
		d=y2-y3;
		e=(x2*x2+y2*y2)-(x1*x1+y1*y1);
		f=(x3*x3+y3*y3)-(x2*x2+y2*y2);
		double l=(e*d-f*b)/(a*d-c*b);
		double m=(c*e-a*f)/(c*b-a*d);
		double n=-1*x1*x1-(y1*y1)-l*x1-m*y1;
	
		double x=-1*l/2.0;
		double y=-1*m/2.0;
		double r=sqrt(l*l+m*m-4*n)/2.0;
		printf("%.3f %.3f %3f\n",x,y,r);
	}
}