#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7, N = 3050, M = 3000000;
int n, m, tmp, ans, K, i;
int u[M], v[M], c[M], co[M], nxt[M], t = 1, S, T, l, r, q[M], g[N], f[N], d[N];
bool in[N];
void add(int x, int y, int z, int zo) {
  u[++t] = x, v[t] = y, c[t] = z;
  co[t] = zo;
  nxt[t] = g[x];
  g[x] = t;
  u[++t] = y, v[t] = x, c[t] = 0;
  co[t] = -zo;
  nxt[t] = g[y];
  g[y] = t;
}
bool spfa() {
  int x, i;
  for (i = 1; i <= T; i++) d[i] = inf, in[i] = 0;
  d[S] = 0;
  in[S] = 1;
  l = r = M >> 1;
  q[l] = S;
  while (l <= r) {
    int x = q[l++];
    if (x == T) continue;
    for (i = g[x]; i; i = nxt[i])
      if (c[i] && co[i] + d[x] < d[v[i]]) {
        d[v[i]] = co[i] + d[x];
        f[v[i]] = i;
        if (!in[v[i]]) {
          in[v[i]] = 1;
          if (d[v[i]] < d[q[l]])
            q[--l] = v[i];
          else
            q[++r] = v[i];
        }
      }
    in[x] = 0;
  }
  return d[T] < inf;
}
void init() {
  memset(g, 0, sizeof(g));
  t = 1;
  ans = 0;
}
int Q;
int mincostflow() {
  int flow = 0;
  while (spfa()) {
    for (tmp = inf, i = T; i != S; i = u[f[i]])
      if (tmp > c[f[i]]) tmp = c[f[i]];
    for (flow += tmp, ans += d[i = T] * tmp; i != S; i = u[f[i]])
      c[f[i]] -= tmp, c[f[i] ^ 1] += tmp;
  }
  if (flow != n) return -1;
  return ans;
}
int maxn[N], minn[N];
int main() {
  init();
  int i, j;
  scanf("%d%d", &n, &Q);
  S = 0, T = n + n * n + 1;
  for (i = 1; i <= n; i++) maxn[i] = n, minn[i] = 1;
  while (Q--) {
    int op, l, r, val;
    scanf("%d%d%d%d", &op, &l, &r, &val);
    for (i = l; i <= r; i++) {
      if (op == 2)
        maxn[i] = min(maxn[i], val);
      else
        minn[i] = max(minn[i], val);
    }
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) add(i * n + j, T, 1, j * j - (j - 1) * (j - 1));
  for (i = 1; i <= n; i++) {
    add(S, i, 1, 0);
    for (j = minn[i]; j <= maxn[i]; j++) {
      for (int k = 1; k <= n; k++) {
        add(i, j * n + k, 1, 0);
      }
    }
  }
  printf("%d\n", mincostflow());
  return 0;
}
