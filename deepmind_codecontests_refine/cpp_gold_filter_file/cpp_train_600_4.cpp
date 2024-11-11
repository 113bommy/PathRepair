#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

vector< vector< pair<int,int> > > to(100005);
ll dist[100005];

int main() {
  int N,M;
  cin >> N >> M;
  REP(i,M) {
    int l,r,c;
    cin >> l >> r >> c;
    l--; r--;
    to[l].emplace_back(r,c);
  }
  REP(i,N-1)
    to[i+1].emplace_back(i,0);

  REP(i,N)
    dist[i] =INF;
  dist[0] = 0;
  // ダイクストラ
  priority_queue< pair<ll, int>, vector< pair<ll,int> >, greater<pair<ll,int> > > q;
  q.push( make_pair(0, 0) );
  while( !q.empty() ) {
    auto v = q.top(); q.pop();
    if ( v.first > dist[v.second] ) continue;
    for ( auto nv: to[v.second] ) {
      if ( dist[nv.first] > dist[v.second] + nv.second ) {
        dist[nv.first] = dist[v.second] + nv.second;
        q.push( make_pair(dist[nv.first], nv.first) );
      }
    }
  }
  ll ans = (dist[N-1] == INF) ? -1 : dist[N-1];
  cout << ans << endl;
}
