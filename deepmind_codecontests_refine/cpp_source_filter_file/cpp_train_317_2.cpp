#include<stdio.h>

int n,m;

void proc(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%c",((i+j)%2==0)?'#:'.');
    }
    printf("\n");
  }
  printf("\n");
}

int main(){
  while(true){
    scanf("%d%d",&n,&m);
    if(!n&&!m)return 0;
    proc();
  }
}