#include <bits/stdc++.h>
using namespace std;
long long read() {
  char c = getchar();
  long long x = 0, flag = 1;
  while (c < '0' || c > '9') {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * flag;
}
const long long INF = 1e15;
const long long MAXN = 15;
long long dp[MAXN][1 << MAXN], ed[MAXN][MAXN];
long long n, m, c;
struct LCA {
  long long u, v, lca;
} a[105];
struct Edge {
  long long u, v;
} e[105];
long long dfs(long long u, long long S) {
  long long &cur = dp[u][S], pos = 0;
  if (cur + 1) return cur;
  S -= (1 << u), cur = 0;
  for (pos = 0; pos < n; ++pos)
    if ((1 << pos) & S) break;
  for (long long sub = S; sub; sub = (sub - 1) & S)
    if (sub & (1 << pos)) {
      bool flag = 1;
      long long cnt = 0, v = 0;
      for (long long i = 1; i <= c; ++i)
        if ((sub & (1 << a[i].u)) && (sub & (1 << a[i].v)) && (a[i].lca == u)) {
          flag = 0;
          break;
        }
      if (!flag) continue;
      for (long long i = 1; i <= c; ++i)
        if ((sub & (1 << a[i].lca)) &&
            (!(sub & (1 << a[i].v)) || !(sub & (1 << a[i].u)))) {
          flag = 0;
          break;
        }
      if (!flag) continue;
      for (long long i = 1; i <= m; ++i)
        if (e[i].u != u && e[i].v != u &&
            (((sub & (1 << e[i].u)) > 0) ^ ((sub & (1 << e[i].v)) > 0))) {
          flag = 0;
          break;
        }
      if (!flag) continue;
      for (long long i = 0; i < n; ++i)
        if (ed[u][i] && (sub & (1 << i))) ++cnt, v = i;
      if (cnt > 1) continue;
      if (cnt == 1)
        cur += dfs(v, sub) * dfs(u, S ^ sub ^ (1 << u));
      else
        for (v = 0; v < n; ++v)
          if (sub & (1 << v)) cur += dfs(v, sub) * dfs(u, S ^ sub ^ (1 << u));
    }
  return cur;
}
int main() {
  n = read(), m = read(), c = read();
  for (long long i = 1; i <= m; ++i)
    e[i].u = read() - 1, e[i].v = read() - 1,
    ed[e[i].u][e[i].v] = ed[e[i].v][e[i].u] = 1;
  for (long long i = 1; i <= c; ++i)
    a[i].u = read() - 1, a[i].v = read() - 1, a[i].lca = read() - 1;
  memset(dp, -1, sizeof(dp));
  for (long long i = 0; i < n; ++i) dp[i][1 << i] = 1;
  printf("%lld\n", dfs(0, (1 << n) - 1));
  return 0;
}
