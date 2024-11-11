#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  long long n,k,h[200001],ans=0;
  cin>>n>>k;
  rep(i,n) cin>>h[i];
  sort(h,h+n);
  rep(i,n-k) ans+=h[i];
  cout<<ans;
}
