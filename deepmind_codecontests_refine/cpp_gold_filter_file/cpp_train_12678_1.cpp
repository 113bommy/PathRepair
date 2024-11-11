#include<iostream>
#define int long long
using namespace std;
signed main(){
  int n,a,b;
  cin>>n>>a>>b;
  int ans=n/(a+b)*a;
  ans+=min(n%(a+b),a);
  cout<<ans<<endl;
}
