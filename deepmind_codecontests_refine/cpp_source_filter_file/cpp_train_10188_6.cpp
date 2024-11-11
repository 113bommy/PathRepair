#include<cstdio>
using namespace std;
int main(){
  int n,p[20001],a;
  scanf("%d"&n);
  for(int i=0;i<n;i++){
    scanf("%d",a);
    p[a]=i;
  }
  for(int i=1;i<=n;i++)
    printf("%d ",n*i);
  printf("\n");
  for(int i=1;i<=n;i++)
    printf("%d ",n*i+p[a]);
  printf("\n");
}