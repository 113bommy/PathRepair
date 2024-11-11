#include<stdio.h>

int n,w[101],s[101];

int min(int x,int y){return x>=y?y:x;}

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&w[i]);
    s[i]=s[i-1]+w[i];
  }
  for(int i=0;i<=n-1;i++)if(s[i]*2>=s[n-1]){
    printf("%d",min(s[i]*2-s[n-1],s[n-1]-s[i-1]*2));
    break;
  }
  return 0;
}