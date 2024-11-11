#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20, sgn[] = {1, -1};
int n, m, tot, h[N], d[N], a[N], b[N], out[N], vis[N];
struct edge {
  int t, n;
} e[N << 1];
inline void input() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);
}
inline void add_edge(int x, int y) {
  e[++m] = (edge){y, h[x]}, h[x] = m;
  e[++m] = (edge){x, h[y]}, h[y] = m;
}
inline void dfs(int u) {
  for (int &i = h[u], p, v; v = e[p = i].t, i; i = e[i].n)
    if (!vis[i + 1 >> 1])
      vis[i + 1 >> 1] = 1, dfs(v), out[++tot] = p - sgn[p & 1], out[++tot] = p;
}
inline int check(int x) {
  memset(h, 0, x + 1 << 2), memset(vis, 0, n + 1 << 2), tot = m = 0;
  for (int i = 1; i <= n; i++)
    d[a[i] &= x] ^= 1, d[b[i] &= x] ^= 1, add_edge(a[i], b[i]);
  for (int i = 0; i <= x; i++)
    if (d[i]) return memset(d, 0, x + 1 << 2), 0;
  return dfs(a[1]), tot == n * 2;
}
inline void work() {
  for (int i = 20; i >= 0; i--)
    if (check((1 << i) - 1)) {
      cout << i << '\n';
      for (int j = 1; j <= tot; j++) cout << out[j] << ' ';
      return;
    }
}
int main() {
  input();
  work();
  return 0;
}
