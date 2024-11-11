#include <stdio.h>

int main(){
 int a,b;
 while(scanf("%d %d ",&a,&b)){
  a+=b;
  b=0;
  while(a>0){
  b++;
  a/=10
  }
  printf("%d\n",b?b:1);
 }



 return 0;
}