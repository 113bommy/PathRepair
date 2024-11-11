#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n, m; cin>>n>>m;
  vector<vector<pll>> g(n, vector<pll>());
  rrep1(i, n-1)g[i].push_back({0, i-1});
  rep(i, m){
    ll l, r, c; cin>>l>>r>>c; l--;r--;
    g[l].push_back( {c, r} );
  }

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  vector<ll> d(n);
  rep(i, n)d[i]=INF;
  d[0]=0;
  pq.push( {0, 0} );
  while(pq.size()){
    auto p = pq.top();pq.pop();
    if(p.first > d[p.second])continue;
    d[p.second] = p.first;
    for(auto np: g[p.second]){
      if(d[np.second] < np.first+p.first)continue;
      d[np.second] = np.first+p.first;
      pq.push( {d[np.second], np.second} );
    }
  }

  cout<<(d[n-1] == INF : -1 : d[n-1])<<endl;

  return 0;
}