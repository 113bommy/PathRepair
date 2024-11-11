#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int r = 1;
  x = x % p;
  while (y) {
    if (y & 1) r = r * x % p;
    y = y >> 1;
    x = x * x % p;
  }
  return r;
}
const int M = 1e5 + 1, N = 3e5 + 99;
vector<int> g[N], topo, v;
int vis[N], cyc[N], lst = 1e5 + 2, tk;
vector<pair<int, int> > vv;
void dfs(int v) {
  if (cyc[v] || tk) {
    (tk = 1);
    return;
  }
  cyc[v] = vis[v] = 1;
  for (auto x : g[v])
    if (cyc[v]) {
      tk = 1;
      return;
    } else if (!vis[x])
      dfs(x);
  cyc[v] = 0;
  topo.push_back(v);
}
int32_t main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    vv.clear();
    for (int j = 0; j < m; j++) {
      int xx;
      cin >> xx;
      vv.push_back({xx, j + 1});
    }
    sort(vv.begin(), vv.end());
    lst++;
    for (int j = 0; j < m; j++) {
      if (vv[j].first == -1) continue;
      if (j && vv[j].first == vv[j - 1].first) {
        v.push_back(vv[j].second);
        continue;
      }
      for (auto x : v) g[lst].push_back(x), g[x].push_back(lst + 1);
      lst++, v.clear();
      v.push_back(vv[j].second);
    }
    for (auto x : v) g[lst].push_back(x);
    v.clear();
  }
  for (int i = 1; i <= m; i++)
    if (!vis[i]) dfs(i);
  if (tk) {
    (cout << -1 << '\n');
    return 0;
  }
  reverse(topo.begin(), topo.end());
  for (auto x : topo)
    if (x < M) cout << x << " ";
  cout << '\n';
}
