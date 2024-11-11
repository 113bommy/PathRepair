#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  return f * x;
}
int n, m, Q;
int res, dp[300005];
struct edge {
  int to, nxt, w;
} e[300005 << 1];
int tot, head[300005];
inline void adde(int u, int v, int w) {
  e[++tot] = (edge){v, head[u], w};
  head[u] = tot;
}
void dfs(int u, int fa) {
  dp[u] = 0;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs(v, u);
    res = max(res, dp[u] + dp[v] + e[i].w);
    dp[u] = max(dp[u], dp[v] + e[i].w);
  }
}
int v[300005], fa[300005];
int getf(int x) {
  if (x == fa[x]) return x;
  return fa[x] = getf(fa[x]);
}
signed main() {
  n = read(), m = read(), Q = read();
  for (register int i = (1); i <= (n); ++i) fa[i] = i;
  for (register int i = (2); i <= (m); ++i) {
    int u = read(), v = read();
    adde(u, v, 1);
    adde(v, u, 1);
    fa[getf(u)] = getf(v);
  }
  for (register int i = (1); i <= (n); ++i)
    if (getf(i) == i) {
      res = 0;
      dfs(1, 0);
      v[i] = res;
    }
  while (Q--) {
    int op = read();
    if (op == 1)
      printf("%d\n", v[getf(read())]);
    else {
      int x = getf(read()), y = getf(read());
      if (x == y) continue;
      int len = max((v[x] + 1) / 2 + (v[y] + 1) / 2 + 1, max(v[x], v[y]));
      fa[y] = fa[x];
      v[x] = len;
    }
  }
  return 0;
}
