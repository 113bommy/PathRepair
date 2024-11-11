#include<stdio.h>
int main()
{
int d;
int sum=0;
while(scanf("%d",&d)!=EOF){
sum=0;
for(int i=d;i<=600-d;i+=d){
sum+=i*i*d;
}
printf("%d\n",sum);}
return 0;
}