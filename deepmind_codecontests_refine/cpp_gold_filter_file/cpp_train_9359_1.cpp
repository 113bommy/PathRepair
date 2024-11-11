#include<stdio.h>

int main(){

int w,h,n;

while(1){
scanf("%d %d",&h,&w);if(w==0&&h==0)break;

if((w*h)%2==0)printf("yes\n");
else printf("no\n");
}
return 0;
}