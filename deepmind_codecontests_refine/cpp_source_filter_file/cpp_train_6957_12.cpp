#include<stdio.h>
int main(){
int a,b,x,i,t=1;
  scanf("%d  %d",&a,&b);
  for(i=0;t<=b;i++){
  t*=10;
  }
  x=a*t+10
  for(i=1;i<=350;i++){
    if(i*i==x)break;
    }
  if(i==350)printf("No");
  else printf("Yes");
  return 0;
}
