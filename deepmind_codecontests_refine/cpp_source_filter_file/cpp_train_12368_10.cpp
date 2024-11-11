#include<stdio.h>
int main(void){
  double w,h,x,y;
  scanf("%lf %lf %lf %lf",&w,&h,&x,&y);
  double q=w*h/2;
  if(x=w/2&&y=h/2){
    printf("%lf 1",q);
  }
  else{
    printf("%lf 0",q);
  }
}