#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;
using ll = long long;


int main(void)
{
  ll n,m,l;
  cin >> n >> m >> l;
  ll dist[301][301];
  REP(i,301) REP(j,301) dist[i][j]=l+1;
  REP(i,m) {
    ll a,b,c;
    cin >> a >> b >> c;
    dist[a][b]=c;
    dist[b][a]=c;
  }
  REP(k,n+1)REP(i,n+1)REP(j,n+1)
    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
  REP(i,n+1)REP(j,n+1)
    if(dist[i][j]<=l) dist[i][j]=1;
    else dist[i][j]=n;
  REP(k,n+1)REP(i,n+1)REP(j,n+1)
    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
  ll q;
  cin >> q;
  REP(i,q) {
    ll s,t;
    cin >> s >> t;
    ll answer = dist[s][t];
    if(answer>=n) answer = 0;
    cout << answer-1 << endl;
  }
  return 0;
}

