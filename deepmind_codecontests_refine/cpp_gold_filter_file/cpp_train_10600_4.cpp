#include<stdio.h>
int c,i=0;
int a[10000];
int main(){
scanf("%d",&c);
for(int k=0;k<c;k++){
scanf("%d",&a[k]);
for(int j=0;a[k]%2==0;i++)a[k]=a[k]/2;
}
printf("%d",i);
return 0;
}
