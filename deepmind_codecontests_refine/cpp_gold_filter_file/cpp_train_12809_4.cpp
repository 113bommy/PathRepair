#include <stdio.h>

int main(void){
 int x;
 int y=0;
 while(1){
  scanf("%d", &x);
  if(x == 0)break;
   printf("Case %d: %d\n", ++y, x);
 }
 return 0;
}

