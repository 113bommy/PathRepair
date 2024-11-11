#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, mod = 1e9 + 7;
struct edge {
  long long to, next;
} e[N << 1];
long long po[N] = {1}, vis[N], dfn[N];
long long tot, head[N], az, ans = 1, n, m, a;
inline void add(long long u, long long v) {
  e[++tot] = (edge){v, head[u]};
  head[u] = tot;
}
inline long long read() {
  char c = getchar();
  long long fh = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) fh = (fh << 1) + (fh << 3) + (c ^ 48), c = getchar();
  return fh;
}
void dfs(long long u, long long d) {
  dfn[u] = d;
  vis[u] = 1;
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].to;
    if (!vis[v])
      dfs(v, d + 1);
    else if (vis[v] == 1)
      az = dfn[u] - dfn[v] + 1, ans = (ans * (po[az] - 2 + mod)), m -= az;
  }
  vis[u] = 2;
}
signed main() {
  n = m = read();
  for (long long i = 1; i <= n; ++i) po[i] = (po[i - 1] << 1) % mod;
  for (long long i = 1; i <= n; ++i) a = read(), add(i, a);
  for (long long i = 1; i <= n; ++i)
    if (!vis[i]) {
      az = 0;
      dfs(i, 0);
    }
  ans = (ans * po[m]) % mod;
  cout << ans;
}
