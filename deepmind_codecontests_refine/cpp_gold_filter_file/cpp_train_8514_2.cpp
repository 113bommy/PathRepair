#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;

int main(){
  string s,t;
  cin>>s>>t;
  int n=sz(s),m=sz(t);
  vector<vector<int>>is(26);
  rep(i,n)is[s[i]-'a'].push_back(i);
  rep(i,n)is[s[i]-'a'].push_back(i+n);
  ll ans=0;
  int p=0;//after p
  rep(i,m){
    int c=t[i]-'a';
    if(sz(is[c])==0){
      puts("-1");
      return 0;
    }
    p=*lower_bound(is[c].begin(),is[c].end(),p)+1;
    if (p>=n){
      p-=n;
      ans+=n;
    }
  }
  ans+=p;
  cout<<ans<<endl;
  return 0;
}
