#include <stdio.h>
int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  printf("%d\n",(9<a || 9<b) ? -1 : a*b);
}