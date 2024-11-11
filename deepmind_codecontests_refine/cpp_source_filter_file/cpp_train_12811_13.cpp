#include<stdio.h>
main(){
  int i,n;
  i = 1;
  while (true){
    scanf("%d",&n);
    if(n==0) break;
    printf("Case %d: %d\n",i,n);
    i++
  }
}