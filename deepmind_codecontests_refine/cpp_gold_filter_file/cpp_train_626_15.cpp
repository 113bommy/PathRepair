#include <stdio.h>
int main(){

 int a,b,c,i,r=0;

 scanf("%d %d %d",&a,&b,&c);

 for(i=a;i<=b;i++) if(c%i==0) r++;

 printf("%d\n",r);

 return 0;

}