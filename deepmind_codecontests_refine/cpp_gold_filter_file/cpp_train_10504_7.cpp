#include <stdio.h>
int main(){
  int l,a,b,c,d,p,i;
  scanf("%d %d %d %d %d",&l,&a,&b,&c,&d);
  for(i = 1 ; a > c || b > d ; i++){
    a = a-c;
    b = b-d;
  }
  p = l - i;
  printf("%d\n",p);
  return 0;
}