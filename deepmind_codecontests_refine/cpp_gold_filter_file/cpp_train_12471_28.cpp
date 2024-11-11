#include<stdio.h>
int main(){
  int A,B,C;
  scanf("%ld %ld",&A,&B);
  C=A-2*B;
  if(C<=0){
    C=0;
  }
  printf("%d\n",C);
}
  
