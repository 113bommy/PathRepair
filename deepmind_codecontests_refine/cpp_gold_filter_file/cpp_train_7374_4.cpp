#include <stdio.h>
int main(){
int N,l,r,s=0,i;
scanf("%d",&N);
for(i=0;i<N;i++){
scanf("%d %d",&l,&r);
s+=r-l+1;}
printf("%d",s);
return 0;}