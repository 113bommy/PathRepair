#include<stdio.h>

int main(){
int s=0,x;
for(inti=0;i<5;i++)
{scanf("%d",&x);if(x<40)x=40;s+=x;}

printf("%d\n",x/5);
return 0;
}