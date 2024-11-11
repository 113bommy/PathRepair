#include<cstdio>
using namespace std;
int main(){
 int w,h;

 while(1){
  scanf("%d %d",&h,&w);
  if(w==0 && h==0){
   return 0;
  }
  for(int i=0;i<h;i++){
   for(int j=0;j<w;j++){
    if(i==0 || i==(h-1) || j==0 || j==(w-1)){
     printf(".");
    }else if{
     printf("#");
    }
   }
   printf("\n");
  }
  printf("\n");
 }
}
