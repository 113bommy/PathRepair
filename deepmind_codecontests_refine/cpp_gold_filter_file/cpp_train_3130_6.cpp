#include <stdio.h>

int main(){
  int n,i,j;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(j=1;j<n;j++){
    printf("%d ",a[(n-j)]);
  }
  printf("%d\n",a[0]);
  return 0;
}