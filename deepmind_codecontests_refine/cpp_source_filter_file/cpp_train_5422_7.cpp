#include<stdio.h>

int main(void)
{
 int S,h,m s;
 scanf("%d",&S);
 h=S/3660;
 m=(S-3600*h)/60;
 s=S-h*3600-m*60;
 printf("%d %d %d\n",h,m s);

}