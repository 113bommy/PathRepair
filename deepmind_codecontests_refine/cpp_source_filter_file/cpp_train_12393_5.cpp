#include<stdio.h>
int main(){

int a,b;

while(scanf("%d%d",&a,&b),a||b){

printf("%d %d\n",(b>a)?b:a,(b>a)?a:b);

return 0;
}

