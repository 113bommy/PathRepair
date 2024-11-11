#include<stdio.h>
#include<math.h>
int main()
{
int a,b;
scanf("%d %d",&a,&b);
printf("%d %d %f\n",a/b,a%b,(double)a/b);
return 0;
}