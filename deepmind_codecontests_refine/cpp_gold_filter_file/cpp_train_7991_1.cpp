#include <bits/stdc++.h>
using namespace std;

signed main(){
  int n,k;cin>>n>>k;
  vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  int l=0,r=1e9+1;
  while(r-l>1){
    int mid=(r+l)>>1,cnt=0;
    for(int i=0;i<n;i++)cnt+=(v[i]-1)/mid;
    (cnt<=k?r:l)=mid;
  }
  cout<<r<<endl;
}
