#include <bits/stdc++.h>
using namespace std;
const long long inf = 9.2e18;
const int maxn = 100007;
const int INF = 2.1e9;
const int MOD = 1e9 + 7;
const double dif = 1e-7;
const double PI = acos(-1.0);
int n, m, k;
int rt;
vector<int> G[maxn];
vector<int> r;
int l[maxn], f[maxn][20], flag[maxn][20], root[maxn];
void dfs(int u, int fa) {
  root[u] = rt;
  if (u == rt) {
    l[u] = 0;
  } else {
    l[u] = l[fa] + 1;
  }
  f[u][0] = fa;
  for (int i = 1; (1 << i) <= l[u]; i++) {
    f[u][i] = f[f[u][i - 1]][i - 1];
    flag[u][i] = flag[u][i - 1] | flag[f[u][i - 1]][i - 1];
  }
  for (int i = 0; i < G[u].size(); i++) {
    if (G[u][i] != fa) {
      dfs(G[u][i], u);
    }
  }
}
int lca1(int u, int v) {
  if (l[u] >= l[v]) return 0;
  int tu = 0, tv = 0;
  if (l[u] < l[v]) swap(u, v);
  int k = 0;
  while ((1 << (k + 1)) <= l[u] - l[v]) k++;
  while (l[u] > l[v]) {
    while ((1 << k) > l[u] - l[v]) k--;
    tu |= flag[u][k];
    u = f[u][k];
  }
  if (u != v)
    return 0;
  else
    return tu == 1;
}
int lca2(int u, int v) {
  int tu = 0, tv = 0, s = 0, t = flag[v][0];
  if (l[u] < l[v]) {
    swap(u, v);
    s = 1;
  }
  int k = 0;
  while ((1 << (k + 1)) <= l[u] - l[v]) k++;
  while (l[u] > l[v]) {
    while ((1 << k) > l[u] - l[v]) k--;
    tu |= flag[u][k];
    u = f[u][k];
  }
  if (u == v) {
    if (!s)
      return 0;
    else
      return t == 2;
  }
  k = 0;
  while ((1 << (k + 1)) <= l[v]) k++;
  while (k >= 0) {
    while ((1 << k) > l[u]) k--;
    if (f[u][k] != f[v][k]) {
      tu |= flag[u][k];
      tv |= flag[v][k];
      u = f[u][k];
      v = f[v][k];
    } else
      k--;
  }
  tu |= flag[u][0];
  tv |= flag[v][0];
  if (s) swap(tu, tv);
  return t == 2 && tu == 1;
}
int main() {
  while (cin >> n) {
    r.clear();
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i <= n; i++) {
      int p, t;
      cin >> p >> t;
      if (p != -1) {
        G[p].push_back(i);
        flag[i][0] = t + 1;
      } else
        r.push_back(i);
    }
    for (int i = 0; i < r.size(); i++) {
      rt = r[i];
      dfs(rt, -1);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
      int u, v, t, ok;
      cin >> t >> u >> v;
      if (root[u] != root[v] || u == v) {
        cout << "NO" << endl;
        continue;
      }
      if (t == 1)
        ok = lca1(u, v);
      else
        ok = lca2(u, v);
      if (ok)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
