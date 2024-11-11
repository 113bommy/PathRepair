#include<stdio.h>
int main(){
  int n,t;
  int a;
  int i;
  scanf("%d%d",&n,&t);
  int ans=0;
  for(i=0;i<n;i++){
    scanf("%d",&a);
    ans+=(a>=t);
  }
  
  printf("%d\n",ans);
}
