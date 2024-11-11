#include <bits/stdc++.h>
const int N = 1e5 + 10;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
int a[N], s[N], w[N], d[N], u[N], v[N];
std::vector<std::pair<int, int>> G[N];
int col[N], par[N], vis[N], flg, U, V;
inline void check(int u) {
  for (auto dat : G[u]) {
    int v = dat.first;
    if (col[v] == col[u]) return flg = 1, U = v, V = u, void();
    if (col[v] == -1) par[v] = u, col[v] = col[u] ^ 1, check(v);
    if (flg) return;
  }
}
inline void solve(int u) {
  vis[u] = 1;
  for (auto dat : G[u]) {
    int v = dat.first, i = dat.second;
    if (!vis[v]) solve(v), w[i] = ((col[v] - s[v]) % 3 + 3) % 3, s[u] += w[i];
  }
}
inline void Solve(int u) {
  vis[u] = 1;
  for (auto dat : G[u]) {
    int v = dat.first, i = dat.second;
    if (!vis[v]) Solve(v), w[i] = ((a[v] - s[v]) % 3 + 3) % 3, s[u] += w[i];
  }
}
std::pair<int, int> nex[N], pre[N];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    char ch = getchar();
    while (ch != 'X' && ch != 'Y' && ch != 'Z') ch = getchar();
    a[i] = ch - 'X';
  }
  for (int i = 1; i <= m; ++i) {
    int u = read() + 1, v = read() + 1;
    G[u].emplace_back(v, i), ::u[i] = u;
    G[v].emplace_back(u, i), ::v[i] = v;
  }
  memset(col, -1, sizeof(col));
  col[1] = 0, check(1);
  if (flg) {
    int u = U, lst = V, v = par[V];
    std::vector<std::pair<int, int>> cir;
    for (; v != par[U]; lst = v, v = par[v]) {
      for (auto e : G[v])
        if (e.first == lst) nex[v] = e;
      for (auto e : G[lst])
        if (e.first == v) pre[lst] = e;
    }
    for (auto e : G[V])
      if (e.first == U) nex[V] = e;
    for (auto e : G[U])
      if (e.first == V) pre[U] = e;
    Solve(u);
    while (s[u] != a[u]) {
      int p1 = U, p2 = U, x = 1;
      while (nex[p1].first != p2) {
        w[nex[p1].second] += x, w[pre[p2].second] += x;
        p1 = nex[p1].first, p2 = pre[p2].first, x = -x;
      }
      w[nex[p1].second] += x;
      s[u] = (s[u] + 2) % 3;
    }
  } else {
    int rt = 0;
    for (int i = 1; i <= n; ++i)
      if (col[i] == 0) {
        rt = i;
        break;
      }
    solve(rt);
    int cnt = 0;
    if (s[rt] % 3 == 1 && G[rt].size() > 1)
      for (int i = 0; i < 2; ++i) w[G[rt][i].second]++, ++cnt;
  }
  for (int i = 1; i <= m; ++i) w[i] = (w[i] % 3 + 3) % 3;
  for (int i = 1; i <= m; ++i)
    printf("%d %d %d\n", u[i] - 1, v[i] - 1, w[i] ? w[i] : 3);
  return 0;
}
