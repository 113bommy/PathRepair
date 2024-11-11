#include<stdio.h>
int main(void){
int b,r,g,c,s,t;

while(scanf("%d%d%d%d%d%d",&b,&r,&g,&c,&s,&t),b+r+g+c+s+t){
point=100;
point+=(b*6+r*4)*15+g*7+c*2+s*3;
point-=(b*5+r*3)*2+(t-b*5-r*3)*3;
printf("%d\n",point);
}
return 0;}