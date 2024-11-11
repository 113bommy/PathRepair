#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> e[N];
vector<int> link[N];
int lo[N];
int dep[N];
bool kp;
int a, b, rt;
void dfs1(int x, int fa) {
  dep[x] = dep[fa] + 1;
  lo[x] = 0;
  link[x].assign(3, 0);
  for (auto v : e[x]) {
    if (v != fa) {
      dfs1(v, x);
      link[x].emplace_back(lo[v] + 1);
      lo[x] = max(lo[x], lo[v] + 1);
    }
  }
}
void dfs2(int x, int fa) {
  partial_sort(link[x].begin(), link[x].begin() + 3, link[x].end(),
               greater<int>());
  for (auto v : e[x]) {
    if (v != fa) {
      link[v].emplace_back(link[x][link[x][0] == lo[v] + 1 ? 1 : 0] + 1);
      dfs2(v, x);
    }
  }
  if (kp == 0 && link[x].size() > 2 && link[x][2] >= dep[b] - 1) kp = 1, rt = x;
}
int f[N][20], lg[N];
int md[N];
void dfs3(int x, int fa) {
  dep[x] = dep[fa] + 1;
  f[x][0] = fa;
  for (int i = 1; i <= 18; i++) f[x][i] = f[f[x][i - 1]][i - 1];
  md[x] = x;
  for (auto v : e[x]) {
    if (v != fa) {
      dfs3(v, x);
      if (dep[md[x]] < dep[md[v]]) md[x] = md[v];
    }
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  while (dep[x] != dep[y]) {
    x = f[x][lg[dep[x] - dep[y]]];
  }
  if (x == y) return x;
  for (int i = 18; i >= 0; i--) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  }
  return f[x][0];
}
int uup(int x, int h) {
  int i = 0;
  while (h) {
    if (h & 1) x = f[x][i];
    h >>= 1;
    i++;
  }
  return x;
}
bool vis[N];
void solve() {
  int n, u, v;
  kp = 0;
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) {
    e[i].clear();
    vis[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  dfs1(a, 0);
  dfs2(a, 0);
  if (kp == 0) {
    printf("NO\n");
    return;
  }
  dfs3(rt, 0);
  int x = a, y = b;
  bool flag = 0;
  int o = lca(x, y);
  if (o == x || o == y) flag = 1;
  for (int i = 1; i <= n && !flag; i++) {
    int p = md[x];
    if (vis[p]) break;
    if (dep[p] - dep[x] >= dep[y] - dep[o])
      flag = 1;
    else {
      vis[p] = 1;
      y = uup(y, dep[p] - dep[x]);
      x = p;
      swap(x, y);
    }
  }
  printf(flag ? "YES\n" : "NO\n");
}
int main() {
  int t;
  for (int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
