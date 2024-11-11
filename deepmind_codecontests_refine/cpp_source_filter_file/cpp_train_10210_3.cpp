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
    printf("#");
    }
   printf("\n");
 }
 printf("\n");
}
