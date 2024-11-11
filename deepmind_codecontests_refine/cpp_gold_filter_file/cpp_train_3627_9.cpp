#include <stdio.h>
int main(){
int N;
scanf("%d",&N);
if((N-(N%10))/10==9||N%10==9){
printf("Yes\n");
return 0;}
printf("No\n");
return 0;}