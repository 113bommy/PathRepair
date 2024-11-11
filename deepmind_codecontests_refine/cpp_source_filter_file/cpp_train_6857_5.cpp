#include<stdio.h>
int main()
{
int d;
int sum=0;
while(scanf("%d",&d)!=0){
sum=0;
for(int i=d;i<=600-d;i+=d){
sum+=i*i*d;
}
printf("%d",&sum)}
return 0;
}