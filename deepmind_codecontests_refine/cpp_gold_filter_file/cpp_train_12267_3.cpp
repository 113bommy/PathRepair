#include<bits/stdc++.h>
using namespace std;

#define int long long
int ans,n,k;

signed main(){
  cin>>n>>k;
  if(k==0)
    return cout<<n*n<<endl,0;
  for(int i=1;i<=n;++i){
    if(i>k){
      ans+=(i-k)*(n/i);
      ans+=max(0LL,((n%i)-k)+1LL);
    }
  }
  return cout<<ans<<endl,0;
}