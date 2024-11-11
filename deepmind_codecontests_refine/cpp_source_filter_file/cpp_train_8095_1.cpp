#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int n;
  scanf("%d",&n);
  int x,y;
  scanf("%d %d",&x,&y);
  int a,b,c,d;
  a=b=x+y;
  c=d=x-y;
  for(int i=2;i<=n;i++) {
    scanf("%d %d",&x,&y);
    a=min(a,x+y);
    b=max(b,x+y);
    c=min(c,x-y);
    d=max(d,x-y);
  }
  printf("%d",max(abs(a-b),abs(c-d));
  return 0;
}