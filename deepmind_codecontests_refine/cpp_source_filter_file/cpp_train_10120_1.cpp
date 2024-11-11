#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const int maxn = 5e5 + 10;
int n, m;
int ecnt = 1, head[maxn], to[maxn << 1], nxt[maxn << 1];
inline void addedge(int a, int b) {
  to[++ecnt] = b, nxt[ecnt] = head[a], head[a] = ecnt;
  to[++ecnt] = a, nxt[ecnt] = head[b], head[b] = ecnt;
}
int dp[maxn], f[maxn], fa[maxn], dfn[maxn], pre[maxn], t[maxn], q[maxn << 1],
    len;
inline void solve() {
  for (int i = 0; i < len; i++) q[i + len] = q[i];
  int x = min_element(q, q + len) - q, y = max_element(q, q + len) - q,
      id = q[x];
  t[id] = q[y];
  if (x > y) y += n;
  for (int i = x; i < y; i++)
    if (q[i] > q[i + 1]) t[id] = 0;
  if (y >= n) y -= n;
  if (x < y) x += n;
  for (int i = x; i > y; i--)
    if (q[i] > q[i - 1]) t[id] = 0;
}
void dfs(int x, int father) {
  dfn[x] = ++dfn[0], pre[x] = father;
  for (int u, i = head[x]; i; i = nxt[i])
    if ((i >> 1) != father)
      if (!dfn[u = to[i]])
        fa[u] = x, dfs(u, i >> 1);
      else if (dfn[u] == -1) {
        len = 0;
        q[len++] = i >> 1;
        while (u ^ x) q[len++] = pre[u], u = fa[u];
        solve();
      }
  dfn[x] = -1;
}
inline void work() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) addedge(read(), read());
  for (int i = 1; i <= n; i++) dp[i] = 1;
  dfs(1, 0);
  for (int x, y, i = m; i; i--)
    x = to[i << 1], y = to[i << 1 | 1],
    dp[x] = dp[y] = f[i] = dp[x] + dp[y] - f[t[i]];
  for (int i = 1; i <= n; i++) printf("%d ", dp[i] - 1);
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
