#include<stdio.h>

int main(){
  int N,M,X,Y,temp,i;
  scanf("%d%d%d%d",&N,&M,&X,&Y);
  for(i=0;i<N;i++){
    scanf("%d",&temp);
    if(temp>X)X = temp;
  }
  for(i=0;i<M;i++){
    scanf("%d",&temp);
    if(temp<Y)Y = temp;
  }
  puts(Y>X?"No War":"War");
  return 0;
}
