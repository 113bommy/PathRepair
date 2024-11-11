#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, q;
int h[maxn];
int mark[maxn];
int type[maxn];
int f[20][maxn];
string ans[maxn];
vector<int> roots;
bool albad[20][maxn];
bool nobad[20][maxn];
vector<int> adj[maxn];
void in();
void solve();
void dfs(int u);
void calc_f();
int lca(int u, int v);
int badbala(int v);
bool nbad(int u, int x);
void out();
int main() {
  in();
  solve();
  out();
}
void in() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int par, t;
    cin >> par >> t;
    par--;
    type[i] = t;
    if (par >= 0)
      adj[par].push_back(i);
    else
      roots.push_back(i);
  }
  cin >> q;
}
void solve() {
  memset(f, -1, sizeof f);
  for (auto i : roots) dfs(i);
  calc_f();
  for (int i = 0; i < q; i++) {
    int t, u, v;
    cin >> t >> u >> v;
    u--;
    v--;
    int x = lca(u, v);
    ans[i] = "NO";
    if (x != -1 && u != v) {
      if (t == 1) {
        if (u == x && nbad(v, h[v] - h[x])) ans[i] = "YES";
      } else {
        if (type[v] == 1) {
          v = badbala(v);
          if (h[v] <= h[x])
            if (nbad(u, h[u] - h[x])) ans[i] = "YES";
        }
      }
    }
  }
}
void dfs(int u) {
  mark[u] = 1;
  for (auto v : adj[u]) {
    if (!mark[v]) {
      h[v] = h[u] + 1;
      albad[0][v] = type[v];
      nobad[0][v] = 1 - type[v];
      f[0][v] = u;
      dfs(v);
    }
  }
}
void calc_f() {
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < n; j++) {
      if (f[i - 1][j] != -1) {
        f[i][j] = f[i - 1][f[i - 1][j]];
        albad[i][j] = albad[i - 1][j] & albad[i - 1][f[i - 1][j]];
        nobad[i][j] = nobad[i - 1][j] & nobad[i - 1][f[i - 1][j]];
      }
    }
  }
}
int lca(int u, int v) {
  if (h[u] > h[v]) swap(u, v);
  for (int i = 19; i >= 0; i--)
    if (f[i][v] != -1 && h[f[i][v]] >= h[u]) v = f[i][v];
  if (v == u) return u;
  for (int i = 19; i >= 0; i--) {
    if (f[i][u] != f[i][v]) {
      u = f[i][u];
      v = f[i][v];
    }
  }
  if (f[0][u] != f[0][v]) return -1;
  return f[0][u];
}
int badbala(int v) {
  for (int i = 19; i >= 0; i--)
    if (f[i][v] != -1 && albad[i][v]) v = f[i][v];
  return v;
}
bool nbad(int u, int x) {
  for (int i = 19; i >= 0; i--) {
    if (((1 << i) & x) != 0) {
      if (!nobad[i][u]) return 0;
      u = f[i][u];
    }
  }
  return 1;
}
void out() {
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
