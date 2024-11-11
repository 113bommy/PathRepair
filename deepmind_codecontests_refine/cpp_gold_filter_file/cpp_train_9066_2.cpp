#include <bits/stdc++.h>
using namespace std;
const int M = 100010;
const int inf = 0x7f7f7f7f;
const double eps = 1e-6;
inline int read(void) {
  int x = 0, f = 1;
  char s = getchar();
  while (!isdigit(s)) {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (isdigit(s)) {
    x = (x << 1) + (x << 3) + (s ^ 48);
    s = getchar();
  }
  return x * f;
}
int n, head[M], cnt, ans[M];
struct edge {
  int nxt, to;
} e[M << 1];
inline void add_edge(int u, int v) {
  e[++cnt].nxt = head[u], head[u] = cnt, e[cnt].to = v;
}
int dfn[M], tot, d[M], f[M];
inline void dfs(int rt, int fa) {
  f[rt] = fa;
  for (int i = head[rt]; i; i = e[i].nxt) {
    if (e[i].to == fa) continue;
    dfs(e[i].to, rt);
  }
  dfn[++tot] = rt;
}
inline int get_ans(int k) {
  int all = 0;
  for (int i = 1; i <= n; i++) d[i] = 1;
  for (int i = 1; i <= n; i++) {
    int x = dfn[i];
    if ((~d[x]) && (~d[f[x]]) && f[x]) {
      if (d[x] + d[f[x]] >= k)
        all++, d[f[x]] = -1;
      else
        d[f[x]] = max(d[f[x]], d[x] + 1);
    }
  }
  return all;
}
signed main(void) {
  n = read();
  memset(ans, -1, sizeof(ans));
  for (int i = 1; i <= n - 1; i++) {
    int u = read(), v = read();
    add_edge(u, v), add_edge(v, u);
  }
  dfs(1, 0);
  int len = sqrt(n * log(n) / log(2));
  ans[1] = n;
  for (int i = 2; i <= len; i++) ans[i] = get_ans(i);
  int l, r;
  for (int i = len + 1; i <= n; i = l + 1) {
    l = i, r = n, ans[i] = get_ans(i);
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (get_ans(mid) == ans[i])
        l = mid;
      else
        r = mid;
    }
    for (int j = i + 1; j <= l; j++) ans[j] = ans[i];
  }
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}
