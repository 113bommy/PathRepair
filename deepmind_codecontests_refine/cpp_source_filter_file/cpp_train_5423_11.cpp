#include<stdio.h>
int main()
{
int ti;
int h,m,s;
scanf("%d",&ti);
s=ti%60;
ti=ti/60;
m=ti%60;
h=ti/60;
printf("%d:%d:%d\n",h,m,s)
return 0;
}