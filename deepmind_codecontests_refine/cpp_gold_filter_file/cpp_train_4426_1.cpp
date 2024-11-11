#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20, lg = 20, MOD = 1e9 + 7;
vector<int> edges[maxn], city[maxn];
vector<int> vec[maxn][lg];
vector<int> tmp;
set<int> temp;
int par[maxn][lg], h[maxn];
inline void merg(int v, int i) {
  tmp.clear();
  for (int u : vec[v][i - 1]) {
    tmp.push_back(u);
  }
  for (int u : vec[par[v][i - 1]][i - 1]) {
    tmp.push_back(u);
  }
  sort(tmp.begin(), tmp.end());
  if (tmp.size() > 10) {
    tmp.resize(10);
  }
  for (int u : tmp) {
    vec[v][i].push_back(u);
  }
}
void dfs(int v) {
  for (int u : edges[v]) {
    if (u != par[v][0]) {
      par[u][0] = v;
      h[u] = h[v] + 1;
      for (int i = 1; i < lg; ++i) {
        par[u][i] = par[par[u][i - 1]][i - 1];
      }
      for (int i = 0; i < min(int(city[u].size()), 10); ++i) {
        vec[u][0].push_back(city[u][i]);
      }
      sort(vec[u][0].begin(), vec[u][0].end());
      for (int i = 1; i < lg; ++i) {
        merg(u, i);
      }
      dfs(u);
    }
  }
}
inline void add(int v, int i) {
  for (int u : vec[v][i]) {
    temp.insert(u);
  }
}
inline int getpar(int v, int k) {
  for (int i = 0; i < lg; ++i) {
    if (k & (1 << i)) {
      v = par[v][i];
    }
  }
  return v;
}
inline int getlca(int v, int u) {
  if (h[u] > h[v]) {
    swap(u, v);
  }
  if (h[v] > h[u]) {
    int dif = h[v] - h[u];
    v = getpar(v, dif);
  }
  if (v == u) {
    return v;
  }
  for (int i = lg - 1; i >= 0; --i) {
    if (par[v][i] != par[u][i]) {
      v = par[v][i];
      u = par[u][i];
    }
  }
  return par[v][0];
}
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    x--;
    city[x].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < min(int(city[0].size()), 10); ++i) {
    vec[0][0].push_back(city[0][i]);
  }
  sort(vec[0][0].begin(), vec[0][0].end());
  while (q--) {
    temp.clear();
    int v, u, a, l = 0, dif1 = 0, dif2 = 0, v2, u2, k = 0;
    cin >> v >> u >> a;
    v--;
    u--;
    v2 = v;
    u2 = u;
    l = getlca(u, v);
    dif1 = h[v2] - h[l];
    dif2 = h[u2] - h[l];
    for (int i = lg - 1; i >= 0; --i) {
      if (dif1 & (1 << i)) {
        add(v2, i);
        v2 = par[v2][i];
      }
    }
    for (int i = lg - 1; i >= 0; --i) {
      if (dif2 & (1 << i)) {
        add(u2, i);
        u2 = par[u2][i];
      }
    }
    add(v2, 0);
    k = min(int(temp.size()), a);
    cout << k << ' ';
    vector<int> ans;
    for (auto u : temp) {
      ans.push_back(u);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; ++i) {
      cout << ans[i] + 1 << ' ';
    }
    cout << endl;
  }
}
