#include <stdio.h>
#include<math.h>
#include <string.h>
#include <ctype.h>

int main(){
double x,h,c,a;
while(1){
scanf("%lf%lf",&x,&h);
if(x==0&&h==0)break;
c=4*h*h+x*x;
c=sqrt(c);
a=x*c+x*x;
printf("%f\n",a);




return 0;
}