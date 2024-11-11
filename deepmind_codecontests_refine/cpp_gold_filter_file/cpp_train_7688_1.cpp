#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=100005;
int n,p=1;
int main()
{
  cin>>n;
  long long ans=0;
  for(int i=1;i<=n;++i){
    int x;   
    scanf("%d",&x);
    if(x<p)continue;
    if(x==p)++p;
    else{
      if(x%p==0)ans+=x/p-1;
      else ans+=x/p;
    }
    if(p==1)++p;
  }
  cout<<ans<<endl;
  return 0;
}
