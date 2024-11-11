#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  ll ans=0;
  for(int i=k+1;i<=n;++i){
    ans+=i-k;
    if(k==0) --ans;
    ans+=(long long)(n-i+1)/i*(i-k)+max(0,(n-i+1)%i-k);
  }
  cout<<ans<<endl;
}
    
