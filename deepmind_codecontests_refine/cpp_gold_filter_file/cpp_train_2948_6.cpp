#include <bits/stdc++.h>
using namespace std;
const int mn = 101000, inf = 1 << 30;
int n, m, L, R, len, ans = 0, st, ed, mi;
int sa[mn], f[mn], s[mn], px[mn], py[mn], q[mn];
int tt, po[mn], w[mn], g[mn], que[mn], fa[mn], dis[mn], dep[mn];
bool del[mn];
struct list {
  int la[mn], next[mn * 2], y[mn * 2], v[mn * 2], tt;
  void add(int i, int j, int k) {
    next[++tt] = la[i], la[i] = tt, y[tt] = j, v[tt] = k;
  }
} e;
int root(int st, int size) {
  int r = 1, h = 1, p, i, j, res;
  que[1] = st, fa[st] = 0, s[st] = 1;
  while (r <= h) {
    for (i = que[r++], p = e.la[i]; p; p = e.next[p]) {
      j = e.y[p];
      if (del[j] || j == fa[i]) continue;
      s[j] = 1, fa[j] = i, que[++h] = j;
    }
  }
  res = que[h];
  for (r = h; r >= 1; --r) {
    i = que[r], f[i] = 0;
    for (p = e.la[i]; p; p = e.next[p]) {
      j = e.y[p];
      if (del[j] || j == fa[i]) continue;
      s[i] += s[j], f[i] = max(f[i], s[j]);
    }
    f[i] = max(f[i], size - f[i]);
    if (f[i] < f[res]) res = i;
  }
  return res;
}
bool cmp(int i, int j) { return s[i] < s[j]; }
void bfs(int st) {
  int r = 1, h = 1, p, i, j;
  que[1] = st, fa[st] = 0;
  while (r <= h) {
    i = que[r++];
    if (dis[i] > g[dep[i]]) g[dep[i]] = dis[i], py[dep[i]] = i;
    for (p = e.la[i]; p; p = e.next[p]) {
      j = e.y[p];
      if (j == fa[i] || del[j]) continue;
      fa[j] = i, dep[j] = dep[i] + 1, que[++h] = j;
      if (e.v[p] >= mi)
        dis[j] = dis[i] + 1;
      else
        dis[j] = dis[i] - 1;
    }
  }
}
bool check(int r, int mid) {
  int i, j, v, k = 0, qh, qt;
  px[0] = r, mi = sa[mid];
  for (i = 1; i <= s[po[tt]]; ++i) f[i] = -inf;
  for (i = 1; i <= tt; ++i) {
    v = po[i];
    for (j = 1; j <= s[v]; ++j) g[j] = -inf;
    dis[v] = w[v] >= mi ? 1 : -1, dep[v] = 1;
    bfs(v);
    qh = 1, qt = 0;
    for (j = 1; j <= s[v]; ++j) {
      while (k >= 0 && j + k >= L) {
        while (qh <= qt && f[q[qt]] < f[k]) --qt;
        q[++qt] = k;
        --k;
      }
      while (qh <= qt && q[qh] + j > R) ++qh;
      if (qh <= qt && g[j] + f[q[qh]] >= 0) {
        if (mid > ans) ans = mid, st = px[q[qh]], ed = py[j];
        return 1;
      }
    }
    for (k = 1; k <= j - 1; ++k)
      if (f[k] < g[k]) f[k] = g[k], px[k] = py[k];
    k = j - 1;
  }
  return 0;
}
void calc(int r, int size) {
  int p, i;
  tt = 0;
  for (p = e.la[r]; p; p = e.next[p]) {
    i = e.y[p];
    if (del[i]) continue;
    if (s[i] > s[r]) s[i] = size - s[r];
    po[++tt] = i, w[i] = e.v[p];
  }
  if (!tt) return;
  sort(po + 1, po + 1 + tt, cmp);
  int lo = ans, hi = len, m;
  while (lo < hi) {
    m = (lo + hi + 1) / 2;
    if (check(r, m))
      lo = m;
    else
      hi = m - 1;
  }
  check(r, lo);
}
void solve(int u, int size) {
  int p, r = root(u, size);
  del[r] = 1;
  calc(r, size);
  for (p = e.la[r]; p; p = e.next[p])
    if (!del[e.y[p]]) solve(e.y[p], s[e.y[p]]);
}
int main() {
  scanf("%d%d%d", &n, &L, &R);
  int i, x, y, z;
  for (i = 1; i <= n - 1; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    e.add(x, y, z), e.add(y, x, z);
    sa[i] = z;
  }
  sort(sa + 1, sa + n), len = unique(sa + 1, sa + n) - sa - 1;
  sa[len + 1] = inf;
  solve(1, n);
  printf("%d %d\n", st, ed);
  return 0;
}
