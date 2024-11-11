#include <bits/stdc++.h>
using namespace std;
const int N = 1501;
const int M = N * (N - 1) / 2;
const int maxn = N << 1;
const int mo = 998244353;
int rd() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * f;
}
int n, ls[maxn], rs[maxn], edge[maxn], sz[maxn], fa[maxn], m, f[maxn][maxn],
    tot[maxn];
bool able[maxn];
int cnt;
int find(int x) { return (fa[x] == x) ? x : fa[x] = find(fa[x]); }
void add(int &x, int y) {
  x += y;
  if (x >= mo) x -= mo;
}
struct node {
  int u, v;
  node() {}
  node(int _u, int _v) {
    u = _u;
    v = _v;
  }
} e[M];
int calc(int x) { return x * (x - 1) >> 1; }
void dfs(int u) {
  if (u <= n) {
    tot[u] = f[u][1] = 1;
    return;
  }
  int L = ls[u], R = rs[u];
  dfs(L);
  dfs(R);
  for (int i = 1; i <= tot[L]; i++)
    for (int j = 1; j <= tot[R]; j++)
      add(f[u][i + j], 1LL * f[L][i] * f[R][j] % mo);
  tot[u] = tot[L] + tot[R];
  if (able[u]) add(f[u][1], 1);
}
int main() {
  n = rd();
  m = n * (n - 1) / 2;
  cnt = n;
  for (int i = 1; i <= n + n; i++) fa[i] = i, sz[i] = (i <= n);
  for (int i = 1; i <= n; i++)
    for (int j = 1, x; j <= n; j++) {
      x = rd();
      if (i < j) e[x] = node(i, j);
    }
  for (int i = 1; i <= m; i++) {
    int u = find(e[i].u), v = find(e[i].v);
    if (u != v) {
      fa[u] = fa[v] = ++cnt;
      ls[cnt] = u;
      rs[cnt] = v;
      edge[cnt] = edge[u] + edge[v] + 1;
      sz[cnt] = sz[u] + sz[v];
      if (edge[cnt] == calc(sz[cnt])) able[cnt] = true;
    } else if ((++edge[cnt]) == calc(sz[cnt]))
      able[cnt] = true;
  }
  dfs(cnt);
  for (int i = 1; i <= n; i++) printf("%d ", f[cnt][i]);
  return 0;
}
