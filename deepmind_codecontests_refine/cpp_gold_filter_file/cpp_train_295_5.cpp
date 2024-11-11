#include <cstdio>

int main(){
  int a,b,c,n=0,m=0;
  while(~scanf("%d,%d,%d",&a,&b,&c)){
    if(a*a+b*b==c*c) n++;
    if(a==b) m++;
  }
  printf("%d\n%d\n",n,m);
}