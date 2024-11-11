#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10, M = 4e4 + 10;
const int INF = 0x3f3f3f3f;
int n, m, g, s, t, cur[N], gap[N], dep[N], q[N];
int fst[N], nxt[M], to[M], val[M], tot = 2;
int ans, a[N];
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
inline void add(int u, int v, int w) {
  nxt[tot] = fst[u];
  to[tot] = v, val[tot] = 1ll * w;
  fst[u] = tot;
  ++tot;
  nxt[tot] = fst[v];
  to[tot] = u, val[tot] = 0;
  fst[v] = tot;
  ++tot;
}
inline void bfs() {
  for (int i = s; i <= t; ++i) dep[i] = q[i] = gap[i] = 0;
  int hd = 0, tl = 1;
  dep[t] = 1, gap[1] = 1;
  q[tl] = t;
  while (hd < tl) {
    int u = q[++hd];
    for (int i = fst[u]; i; i = nxt[i]) {
      int v = to[i];
      if (!dep[v]) {
        dep[v] = dep[u] + 1;
        ++gap[dep[v]];
        q[++tl] = v;
      }
    }
  }
}
long long dfs(int u, long long lim) {
  if (u == t) return lim;
  int ans = 0, tmp;
  for (int i = cur[u]; i; i = nxt[i]) {
    int v = to[i];
    cur[u] = i;
    if (dep[v] == dep[u] - 1 && val[i]) {
      tmp = dfs(v, min(lim, 1ll * val[i]));
      val[i] -= tmp, lim -= tmp;
      ans += tmp, val[i ^ 1] += tmp;
      if (!lim) break;
    }
  }
  if ((!ans) || lim) {
    if (--gap[dep[u]] == 0) dep[s] = n + m + 3;
    ++gap[++dep[u]];
  }
  return ans;
}
inline long long isap() {
  long long ans = 0;
  bfs();
  while (dep[s] <= n + m + 2) {
    memcpy(cur, fst, sizeof(cur));
    ans += dfs(s, INF);
  }
  return ans;
}
int main() {
  n = read(), m = read(), g = read(), s = 0, t = n + m + 1;
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= n; ++i) {
    int w = read();
    if (!a[i])
      add(s, i, w);
    else
      add(i, t, w);
  }
  for (int i = 1; i <= m; ++i) {
    int sign = read(), w = read(), k = read();
    ans += w;
    for (int j = 1; j <= k; ++j) {
      int x = read();
      if (!sign)
        add(i + n, x, INF);
      else
        add(x, i + n, INF);
    }
    int opt = read();
    if (opt) w += g;
    if (!sign)
      add(s, i + n, w);
    else
      add(i + n, t, w);
  }
  printf("%d", ans - isap());
  return 0;
}
