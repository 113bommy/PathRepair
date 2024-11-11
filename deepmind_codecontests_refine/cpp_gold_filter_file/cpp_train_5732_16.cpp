#include<stdio.h>

int main(void){
  long a,b;

  scanf("%ld%ld",&a,&b);
  printf("%ld %ld %lf",a/b,a%b,(double)a/b);
  return 0;
}