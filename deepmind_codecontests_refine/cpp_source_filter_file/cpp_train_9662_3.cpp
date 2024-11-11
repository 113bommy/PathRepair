#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,h[128],ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>h[i];
    if(i)ans+=max(0,h[i]-h[i-1]);
    else ans+=h[i];
  }
  cout<<ans<<endl;
}