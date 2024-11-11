#include<cstdio>
main(){
 int a,b,c,i=0;
 scanf("%d%d%d",&a,&b,&c);
 for(;a<b;a++){
  if(!c%a)i++
 }
 printf("%d\n",i);
}