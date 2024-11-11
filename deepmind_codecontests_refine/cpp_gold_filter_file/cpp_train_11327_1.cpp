#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int n,m,cnt=0;
  scanf("%d %d",&n,&m);
  vector<int> v(2*n);
  vector<pair<int,int>> p(m);
  rep(i,n) scanf("%d",&v[i]);
  rep(i,m) scanf("%d %d",&p[i].second,&p[i].first);
  sort(p.begin(),p.end());
  for (int i = m-1; i >= 0 && cnt < n; --i)
     rep(j,p[i].second) {
         v[n + cnt++]=p[i].first;
         if(cnt==n) break;
     }
  sort(v.begin(),v.end(),greater<int>());
  long long ans=0;
  rep(i,n) ans+=v[i];
  cout<<ans;
}