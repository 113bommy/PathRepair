// ?????±???????????????????????? 2015-1
#include<cstdio>
#include<algorithm>
using namespace std;
 
 
int main(){
  int a[4],b[2];
  for(int i=0;i<4;i++) scanf("%d",a+i);
  for(int i=0;i<2;i++) scanf("%d",b+i);
  sort(a,a+4);
  sort(b,b+2);
  int ans = 0;
  for(int i=3;i>0;i--) ans+=a[i];
  ans+=b[1];
  printf("%d\n",ans);
  return 0;
}