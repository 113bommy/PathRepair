#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 5e5 + 10, mod = 1e9 + 7;
int n, a[N];
vector<int> e[N];
inline void GG() {
  puts("0");
  exit(0);
}
int dep[N], fa[N];
inline void dfs(int u) {
  dep[u] = dep[fa[u]] + 1;
  for (auto v : e[u])
    if (v != fa[u]) {
      fa[v] = u, dfs(v);
    }
}
int d[N];
map<int, int> l[N], r[N];
inline bool check(int a, int b, int c) {
  if (l[b][a] == 0 && r[b][c] == n + 1 && d[b] != 2) return 0;
  if (l[b][a] == -1) return 0;
  if (r[b][c] == -1 || r[b][c] == a) return 0;
  return 1;
}
inline void Merge(int a, int b, int c) {
  r[b][l[b][a]] = r[b][c], l[b][r[b][c]] = l[b][a];
  r[b][c] = l[b][a] = -1, d[b]--;
}
int cnt, cnt2, v[N], v2[N];
inline int LCA(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  while (dep[x] < dep[y]) y = fa[y];
  while (x != y) x = fa[x], y = fa[y];
  return x;
}
inline void GetPath(int x, int y) {
  int z = LCA(x, y);
  cnt = cnt2 = 0;
  for (int u = x; u != z; u = fa[u]) v[++cnt] = u;
  v[++cnt] = z;
  for (int u = y; u != z; u = fa[u]) v2[++cnt2] = u;
  reverse(v2 + 1, v2 + 1 + cnt2);
  for (register int i = (1); i <= (cnt2); i++) v[++cnt] = v2[i];
  ++cnt, v[cnt] = n + 1;
  for (register int i = (2); i < (cnt); i++)
    if (!check(v[i - 1], v[i], v[i + 1])) GG();
  for (register int i = (1); i < (cnt); i++) Merge(v[i - 1], v[i], v[i + 1]);
}
int main() {
  n = read();
  for (register int i = (1); i < (n); i++) {
    int x = read(), y = read();
    e[x].push_back(y), e[y].push_back(x);
    l[x][y] = r[x][y] = y;
    l[y][x] = r[y][x] = x;
  }
  dfs(1);
  for (register int i = (1); i <= (n); i++) {
    int x = read();
    if (x == i) GG();
    if (x) a[x] = i;
  }
  for (register int i = (1); i <= (n); i++)
    d[i] = ((int)(e[i]).size()) + 2, l[i][0] = r[i][0] = 0,
    l[i][n + 1] = r[i][n + 1] = n + 1;
  for (register int i = (1); i <= (n); i++)
    if (a[i]) GetPath(i, a[i]);
  vector<int> fac(n + 1);
  fac[0] = 1;
  for (register int i = (1); i <= (n); i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  int ans = 1;
  for (register int i = (1); i <= (n); i++) {
    int cnt = 0;
    for (auto j : e[i])
      if (l[i][j] != -1 && l[i][j] != 0) ++cnt;
    ans = 1ll * ans * fac[cnt] % mod;
  }
  printf("%d\n", ans);
}
