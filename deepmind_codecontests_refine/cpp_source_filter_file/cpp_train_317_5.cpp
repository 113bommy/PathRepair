#include<cstdio>
int main(void){
int w;
int h;
for(;;){
scanf("%d %d",&w,&h);
if(w==0&&h==0) break;

else{
for(int i=0;i<w;i++){
for(int j=0;j<h;j++){
if((i+j)%2==0)printf("#");
else printf(".");
}
printf("\n");
}
printf("\n");
}
}
return 0;