#include<cstdio>
#include<cstring>
int main(){
 int a,j,b[10];
 while(1){
  scanf("%d",&a);
 if(a==0) return 0;
 memset(b,0,sizeof(int)*10);
 for(int i=0;i<a;i++){
  scanf("%d",&j);
  b[j]++;
 }
 for(int i=0;i<10;i++){
  if(s==0){
  printf("-\n");
 continue; 
 }
  for(int s=0;s<b[j];s++){
    printf("*");
  }
  printf("\n");
 }
 }
}