#include <stdio.h>
int main(){
 int n;
 int debt=100000;
 scanf("%d",&n);
 while(n--){
   debt += debt*0.05;
   if(debt%1000!=0){
     debt -= debt%1000;
     debt += 1000;
   }
 }
 printf("%d\n",debt);
 return 0;
}