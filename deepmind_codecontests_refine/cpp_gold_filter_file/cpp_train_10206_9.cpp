#include <cstdio>
int main(){
 int H,W;
 while(1){
  scanf("%d %d",&H,&W);
  if(!W&&!H){break;}
  for(int i=0;i<H;i++){
   for(int j=0;j<W;j++){
    putchar('#');
   }
   putchar('\n');
  }
 putchar('\n');
 }
}