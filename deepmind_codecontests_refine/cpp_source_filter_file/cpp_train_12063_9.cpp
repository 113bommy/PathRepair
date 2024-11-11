#include <cstdio>
int main(){
 int d,n,a,b; 
 while(true){
  d=0;
  if (scanf("%d %d",&a,&b)==0) break;
  n=a+b;
  while(n>0) { d++, n/=10 };
  printf("%d\n",d);
  return 0;
};