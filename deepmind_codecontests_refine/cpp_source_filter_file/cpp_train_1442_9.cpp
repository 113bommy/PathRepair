#include<bits\stdc++.h>
int main(){
 int a,b,c;
 scanf("%d %d %d",&a,&b,&c);
int sum=a*100+10*b+c;
if(sum%4==0)
printf("YES\n");
else
printf("NO\n");
}