#include<stdio.h>

int main(){
  int n,b,f,r,v;
  int x[4][3][10]={{0}};
  int i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d %d %d",&b,&f,&r,&v);
    x[b][f][r]=v;
    }
  for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      for(k=0;k<10;k++){
        printf(" %d",x[i][j][k]);
      }
      printf("\n");
    }
    if(i<3){
      printf("####################\n")
    }
  }

  return 0;
}