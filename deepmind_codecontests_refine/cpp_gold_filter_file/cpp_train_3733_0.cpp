#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100+5],x,y,h;
int main()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++){scanf("%d",&a[i]);h+=a[i];}
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d%d",&x,&y);
    printf("%d\n",h-a[x]+y);
  }
  return 0;
}