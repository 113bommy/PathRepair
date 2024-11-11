#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const long long N = 100010;
struct edge {
  long long v, nxt;
} e[N << 1];
long long head[N], cnt, n, x, y, a[N], dp[N][2], f[N], g[N], h[N];
inline void add(long long u, long long v) {
  e[++cnt].v = v;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}
inline void dfs(long long u, long long fa) {
  dp[u][0] = dp[u][1] = f[u] = g[u] = a[u];
  h[u] = 0;
  for (long long i = head[u]; i; i = e[i].nxt) {
    long long v = e[i].v;
    if (v == fa) continue;
    dfs(v, u);
    dp[u][0] = max(dp[u][0], max(dp[v][0], dp[u][1] + dp[v][1]));
    dp[u][0] = max(dp[u][0], max(f[u] + g[v], f[v] + g[u]));
    dp[u][1] = max(dp[u][1], max(dp[v][1], f[u] + f[v]));
    g[u] = max(g[u], a[u] + g[v]);
    g[u] = max(g[u], max(f[u] + dp[v][1], f[v] + a[u] + h[u]));
    h[u] = max(h[u], dp[v][1]);
    f[u] = max(f[u], f[v] + a[u]);
  }
}
inline void mian() {
  n = read();
  for (long long i = 1; i <= n; ++i) a[i] = read();
  for (long long i = 1; i <= n - 1; ++i) {
    x = read();
    y = read();
    add(x, y);
    add(y, x);
  }
  dfs(1, 0);
  printf("%d\n", dp[1][0]);
}
signed main() {
  long long qwq = 1;
  while (qwq--) mian();
  return 0;
}
