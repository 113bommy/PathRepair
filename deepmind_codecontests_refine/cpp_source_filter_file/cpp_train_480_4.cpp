#include <bits/stdc++.h>
using namespace std;
inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }
inline int gcd(int n, int m) { return m ? gcd(m, n % m) : n; }
inline int lcm(int x, int y) { return x / gcd(x, y) * y; }
inline void swap(int &x, int &y) {
  int t = x;
  x = y;
  y = t;
  return;
}
namespace yspm {
inline int read() {
  int res = 0, f = 1;
  char k;
  while (!isdigit(k = getchar()))
    if (k == '-') f = -1;
  while (isdigit(k)) res = res * 10 + k - '0', k = getchar();
  return res * f;
}
const int N = 1e5 + 10, B = 510;
int head[N], cnt, sz[N], dep[N], fa[N], top[N], son[N], dfn[N], ord[N], tim,
    a[N], n, Q;
int col[N], tag[N], ans, sum[N / B + 10][N << 1], val[N], st[N], ed[N], bel[N];
struct node {
  int to, nxt;
} e[N << 1];
inline void add(int u, int v) {
  e[++cnt].to = v;
  e[cnt].nxt = head[u];
  return head[u] = cnt, void();
}
inline void dfs1(int x, int fat) {
  dep[x] = dep[fa[x] = fat] + (sz[x] = 1);
  for (register int i = head[x]; i; i = e[i].nxt) {
    int t = e[i].to;
    dfs1(t, x);
    sz[x] += sz[t];
    if (sz[son[x]] < sz[t]) son[x] = t;
  }
  return;
}
inline void dfs2(int x, int topf) {
  top[x] = topf;
  dfn[x] = ++tim;
  ord[tim] = x;
  if (son[x])
    dfs2(son[x], topf);
  else
    return;
  for (register int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != son[x]) dfs2(e[i].to, e[i].to);
  return;
}
inline void rev(int x) {
  col[x] ^= 1;
  if (col[x] == 1) {
    if (val[x] + tag[bel[x]] > n) --ans;
    sum[bel[x]][val[x]]--;
  } else {
    if (val[x] + tag[bel[x]] > n) ++ans;
    sum[bel[x]][val[x]]++;
  }
  return;
}
inline void rebuild(int l, int r, int addi) {
  for (register int i = l; i <= r; ++i) {
    if (col[i]) {
      val[i] += addi;
      continue;
    }
    if (val[i] + tag[bel[i]] > n) ans--;
    sum[bel[i]][val[i]]--;
    val[i] += addi;
    if (val[i] + tag[bel[i]] > n) ++ans;
    sum[bel[i]][val[i]]++;
  }
  return;
}
inline void upd(int l, int r, int v) {
  if (bel[l] + 1 >= bel[r]) return rebuild(l, r, v), void();
  rebuild(l, ed[bel[l]], v);
  rebuild(st[bel[r]], r, v);
  for (register int now = bel[l] + 1; now <= bel[r] - 1; ++now) {
    if (v == 1)
      tag[now] += v, ans += v * sum[now][n - tag[now] + 1];
    else
      ans -= v * sum[now][n - tag[now] + 1], tag[now] += v;
  }
  return;
}
signed main() {
  n = read();
  Q = read();
  for (register int i = 2; i <= n; ++i) fa[i] = read(), add(fa[i], i);
  dfs1(1, 0);
  dfs2(1, 1);
  for (register int i = 1; i <= n; ++i) {
    a[i] = read();
    bel[i] = (i - 1) / B + 1;
    if (bel[i] ^ bel[i - 1]) st[bel[i]] = i, ed[bel[i - 1]] = i - 1;
  }
  ed[bel[n]] = n;
  for (register int i = 1; i <= n; ++i)
    val[i] = n - a[ord[i]], sum[bel[i]][val[i]]++;
  while (Q--) {
    int x = read(), add = x > 0 ? 1 : -1;
    x = abs(x);
    rev(dfn[x]);
    for (; x; x = fa[top[x]]) upd(dfn[top[x]], dfn[x], add);
    printf("%d ", ans);
  }
  puts("");
  return 0;
}
}  // namespace yspm
signed main() { return yspm::main(); }
