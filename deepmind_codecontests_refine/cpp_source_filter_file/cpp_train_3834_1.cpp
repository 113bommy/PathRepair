#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long int ans=0;
  vector<int>v(n+1);
  vector<int>w(n+1);
  for(int i=0;i<n;++i){
    cin>>v[i]>>w[i];
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  sort(w,begin(),w,end());
  for(int i=0;i<n+1;++i){
    if(v[i]>w[i]) ans+=(v[i]-w[i])*2;
  }
  cout<<ans<<endl;
}