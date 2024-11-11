#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 17;
const long long INF = 3e18 + 7;
vector<pair<long long, long long> > g[maxn];
vector<long long> path;
set<pair<long long, long long> > myst;
bool mark[maxn];
long long n, m, last, sp[maxn], par[maxn];
long long ext_min() {
  pair<long long, long long> ret = *myst.begin();
  myst.erase(ret);
  return ret.second;
}
void update(long long v) {
  mark[v] = true;
  for (long long i = 0; i < g[v].size(); i++) {
    if (!mark[g[v][i].first]) {
      long long u = g[v][i].first;
      myst.erase(make_pair(sp[u], u));
      if (sp[u] > sp[v] + g[v][i].second) par[u] = v;
      sp[u] = min(sp[u], sp[v] + g[v][i].second);
      myst.insert(make_pair(sp[u], u));
    }
  }
}
inline void dijkstra(long long v) {
  fill(sp, sp + n + 10, INF);
  sp[v] = 0;
  update(v);
  for (long long i = 1; i < n; i++) {
    long long u = ext_min();
    update(u);
  }
}
inline void input() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }
}
inline void show() {
  if (sp[n] != INF) {
    long long x = n;
    while (x >= 1) {
      path.push_back(x);
      x = par[x];
    }
    for (long long i = path.size() - 1; i >= 0; i--) cout << path[i] << ' ';
  } else
    cout << -1;
  cout << endl;
}
int32_t main() {
  input();
  dijkstra(1);
  show();
  return 0;
}
