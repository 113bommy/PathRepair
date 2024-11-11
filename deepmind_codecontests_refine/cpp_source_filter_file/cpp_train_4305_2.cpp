#include <bits/stdc++.h>
using namespace std;
const int64_t N = 5e5 + 1e1;
bool mark[N];
int64_t n, m, ans, par[N], sz[N];
vector<int64_t> mol[N], adj[N];
int64_t root(int64_t x) { return par[x] = (x == par[x] ? x : root(par[x])); }
int64_t mrg(int64_t x, int64_t y) {
  x = root(x);
  y = root(y);
  if (x == y) {
    return 0;
  }
  if (sz[x] < sz[y]) {
    swap(x, y);
  }
  par[y] = x;
  sz[x] += sz[y];
  return 1;
}
void connect(int64_t v) {
  memset(mark, 0, sizeof mark);
  for (int64_t u : adj[v]) {
    mark[u] = true;
  }
  for (int64_t i = 1; i <= n; i++) {
    if (!mark[i]) {
      ans -= mrg(v, i);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(true == false);
  cin >> n >> m;
  for (int64_t i = 1; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  ans = n;
  int64_t a, b;
  for (int64_t i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int64_t mn = 1;
  for (int64_t i = 2; i <= n; i++) {
    if (adj[i].size() < adj[mn].size()) {
      mn = i;
    }
  }
  connect(mn);
  for (int64_t u : adj[mn]) {
    connect(u);
  }
  cout << ans << '\n';
  for (int64_t i = 1; i <= n; i++) {
    mol[par[i]].push_back(i);
  }
  for (int64_t i = 1; i <= n; i++) {
    if (mol[i].size()) {
      cout << mol[i].size() << ' ';
      for (int64_t u : mol[i]) {
        cout << u << ' ';
      }
      cout << endl;
    }
  }
}
