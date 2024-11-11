#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  int n,sum=0,a=0;cin>>n;
  vector<int>ans(n);
  vector<int>v(n);
  rep(i,n)cin>>v[i];
  rep(i,n)sum+=v[i];
  for(int i=1;i<n;i+=2)a+=v[i];
  ans[0]=sum-a*2;
  for(int i=1;i<n;i++)ans[i]=v[i-1]*2-ans[i-1];
  rep(i,n)cout<<ans[i]<<endl;
}
