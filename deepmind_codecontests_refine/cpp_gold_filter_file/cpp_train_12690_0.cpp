#include<stdio.h>
int main(int i){
int a,sum=0;
for(;i<6;i++){
scanf("%d",&a);
sum += a<40?40:a;
}
printf("%d\n",sum/5);
return 0;
}