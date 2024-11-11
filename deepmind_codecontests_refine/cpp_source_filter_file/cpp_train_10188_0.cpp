#include<cstdio>
#define MN 20005
int n,a[MN],i;
int main(){
  scanf("%d",&n);
  for(i=0,x;i<n;i++)scanf("%d",&x),a[x]=i+1;
  for(i=1;i<=n;i++)printf("%d%c",a[i]+i*MN,i<n?' ':'\n');
  for(i=1;i<=n;i++)printf("%d ",(n-i+1)*MN);
  return 0;
}
