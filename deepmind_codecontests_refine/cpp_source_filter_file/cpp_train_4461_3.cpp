#include <cstdio>

int main(){

  int N[3],t;
  scanf("%d %d %d",&N[0],$N[1],&N[2]);
  if(N[0]==N[1])t=2;
  else if(N[1]==N[2])t=1;
  else t=0;
  printf("%d\n",N[t]);
}