#include <bits/stdc++.h>
using std::max;
using std::sort;
const int MAXN = 4e5 + 7;
int n, q, k, s, ans, ccnt;
int home[MAXN], nxt[MAXN], to[MAXN], len[MAXN];
inline void ct(int x, int y, int z) {
  ccnt++;
  nxt[ccnt] = home[x];
  home[x] = ccnt;
  to[ccnt] = y;
  len[ccnt] = z;
}
namespace fastIO {
static char buf[(1 << 19)], *p1 = buf + (1 << 19), *pend = (1 << 19) + buf;
inline char nc() {
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, (1 << 19), stdin);
  }
  return *p1++;
}
inline int read() {
  int x = 0, f = 1;
  register char s = nc();
  for (; !isdigit(s); s = nc())
    if (s == '-') f = -1;
  for (; isdigit(s); s = nc()) x = (x << 1) + (x << 3) + s - '0';
  return x * f;
}
}  // namespace fastIO
using namespace fastIO;
const int MAXM = 2e5 + 7;
struct rec {
  int root, f[MAXM][21], g[MAXM][21], d[MAXN], dep[MAXN], son[MAXN], top[MAXN],
      rnk[MAXN];
  int l[MAXN], r[MAXN], s[MAXN], t;
  void dfs1(int u, int F) {
    for (int i = home[u]; i; i = nxt[i]) {
      int v = to[i];
      if (v != F) {
        d[v] = d[u] + len[i], dfs1(v, u);
      }
    }
  }
  void dfs2(int u) {
    for (int i = home[u]; i; i = nxt[i]) {
      int v = to[i];
      if (v != f[u][0]) {
        f[v][0] = u;
        g[v][0] = len[i];
        for (int j = 0; f[v][j]; ++j) {
          f[v][j + 1] = f[f[v][j]][j];
          g[v][j + 1] = g[v][j] + g[f[v][j]][j];
        }
        d[v] = d[u] + len[i];
        dfs2(v);
        if (dep[v] + len[i] > dep[u]) dep[u] = dep[v] + len[i], son[u] = v;
      }
    }
    for (int i = home[u]; i; i = nxt[i]) {
      int v = to[i];
      if (v != f[u][0] && v != son[u]) s[l[++t] = v] = dep[v] + u;
    }
  }
  void getroot(int u) {
    dfs1(u, 0);
    root = u;
    for (int i = 1; i <= n; ++i)
      if (d[i] > d[root]) root = i;
    d[root] = 0;
    dfs2(root);
    s[l[++t] = root] = dep[root];
    sort(l + 1, l + t + 1, [&](int i, int j) { return s[i] > s[j]; });
    for (int i = 1; i <= t; ++i) r[i] = r[i - 1] + s[l[i]];
    for (int i = 1; i <= t; ++i) {
      int x = l[i], p = x;
      while (x) {
        top[x] = p;
        rnk[x] = i;
        x = son[x];
      }
    }
  }
  inline int plan1(int x, int y) {
    int z = dep[x];
    for (int i = 20; ~i; --i) {
      if (rnk[f[x][i]] >= y) z += g[x][i], x = f[x][i];
    }
    return r[y - 1] + z + g[x][0];
  }
  inline int plan2(int x, int y) {
    int z = dep[x];
    for (int i = 20; ~i; --i) {
      if (rnk[f[x][i]] > y) z += g[x][i], x = f[x][i];
    }
    return r[y] - dep[f[x][0]] + z + g[x][0];
  }
  inline int ask(int x, int y) {
    y = 2 * y - 1;
    return rnk[x] <= y ? r[y] : max(plan1(x, y), plan2(x, y));
  }
} t[2];
int in[MAXN];
int main() {
  n = read();
  q = read();
  for (int i = 1, x, y, z; i < n; ++i) {
    x = read(), y = read(), z = read();
    ct(x, y, z);
    ct(y, x, z);
    in[x]++;
    in[y]++;
    s += z;
  }
  for (int i = 1; i <= n; ++i) k += (in[i] == 1);
  t[0].getroot(1), t[1].getroot(t[0].root);
  for (int i = 1, x, y; i <= q; ++i) {
    x = read(), y = read();
    x = (x + ans - 1) % n + 1;
    y = (y + ans - 1) % n + 1;
    ans = 2 * y >= k ? s : max(t[0].ask(x, y), t[1].ask(x, y));
    printf("%d\n", ans);
  }
  return 0;
}
