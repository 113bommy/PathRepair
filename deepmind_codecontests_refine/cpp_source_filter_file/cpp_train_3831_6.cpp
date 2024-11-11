#include<stdio.h>

int main(void)
{
  char S[6];
  scanf("%s",&S);
  if(S[1]==S){
    printf("Cloudy");
  }else if(S[1]==C){
    printf("Rainy");
  }else{
    printf("Sunny");
  }
  return 0;
}