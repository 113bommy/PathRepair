#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline char smax(A &a, const B &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename A, typename B>
inline char smin(A &a, const B &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename I>
inline void read(I &x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) c == '-' ? f = 1 : 0;
  x = c & 15;
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  f ? x = -x : 0;
}
const int N = 2000 + 7;
int n, m;
bitset<N> a[N];
int f[N][N], dis[N], vis[N], pre[N], thx[N], wph[N];
char s[N];
struct Edge {
  int to, ne;
} g[N << 1];
int head[N], tot;
inline void addedge(int x, int y) {
  g[++tot].to = y, g[tot].ne = head[x], head[x] = tot;
}
inline void adde(int x, int y) { addedge(x, y), addedge(y, x); }
inline void prim() {
  fill_n(dis + 1, n, -1);
  fill_n(vis + 1, n, 0);
  fill_n(pre + 1, n, 0);
  for (int i = 1; i <= n; ++i) {
    int x = 0;
    for (int j = 1; j <= n; ++j)
      if (!vis[j] && (!x || dis[j] > dis[x])) x = j;
    vis[x] = 1;
    if (pre[x]) adde(pre[x], x);
    if (!x) return;
    for (int j = 1; j <= n; ++j)
      if (!vis[j] && f[x][j] > dis[j]) pre[j] = x, dis[j] = f[x][j];
  }
}
inline int dfs(int x, int fa, int p) {
  if (!a[x][p]) return 0;
  int ans = 1;
  for (int i = head[x], y = g[i].to; i; i = g[i].ne, y = g[i].to)
    if (y != fa) ans += dfs(y, x, p);
  return ans;
}
inline void work() {
  tot = 0;
  fill_n(head + 1, n, 0);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) f[i][j] = f[j][i] = (a[i] & a[j]).count();
  prim();
  for (int i = 1; i <= m; ++i)
    if (dfs(thx[i], 0, i) != wph[i]) return (void)puts("NO");
  puts("YES");
  for (int i = 1; i <= n; ++i)
    for (int j = head[i], y = g[j].to; j; j = g[j].ne, y = g[j].to)
      if (y > i) printf("%d %d\n", i, y);
}
inline void init() {
  fill_n(thx + 1, m, 0);
  fill_n(wph + 1, m, 0);
  read(n), read(m);
  for (int i = 1; i <= n; ++i) a[i].reset();
  static int cs = 0;
  for (int i = 1; i <= m; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; ++j)
      if (s[j] == '1') a[j].set(i), thx[i] = j, ++wph[i];
  }
}
int main() {
  int T;
  read(T);
  while (T--) {
    init();
    work();
  }
  return 0;
}
