#include <stdio.h>
int main(void){
  int H,W,h,w,a;
  scanf("%d%d%d%d",&H,&W,&h,&w);
  a=(H-h)*(W-w);
  printf("%d",a);
  return 0;
}