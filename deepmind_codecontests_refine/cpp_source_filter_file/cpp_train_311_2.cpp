#include<stdio.h>

int main(void)
{
int i,j,a,b;

while(1){
scanf("%d %d",&a,&b);
if(a==0&&b==0){
break;
}
for(i=1;i<a=;i++){
for(j=1;j<=b;j++){
if((i+j)%2==0){
printf("#");
}
else{
printf(".");
}
}
printf("\n");
}
printf("\n");
}
return 0;
}