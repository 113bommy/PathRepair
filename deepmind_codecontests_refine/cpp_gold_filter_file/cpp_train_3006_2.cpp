#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
long n,i;
double x1,y1,x2,y2,x3,y3,x,y,r,a1,b1,c1,a2,b2,c2;
cin>>n;
for(i=0;i<n;i++){
cin>>x1>>y1>>x2>>y2>>x3>>y3;
a1=(x2-x1)*2;
b1=(y2-y1)*2;
c1=x1*x1-x2*x2+y1*y1-y2*y2;
a2=(x3-x1)*2;
b2=(y3-y1)*2;
c2=x1*x1-x3*x3+y1*y1-y3*y3;
x=(b1*c2-b2*c1)/(a1*b2-a2*b1);
y=(c1*a2-c2*a1)/(a1*b2-a2*b1);
r=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
printf("%.3f %.3f %.3f\n",x,y,r);
}
return 0;
}