#include <bits/stdc++.h>
using namespace std;
const long long N = 200010;
inline long long read() {
  char ch = getchar();
  long long p = 0;
  long long f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    p = p * 10 + ch - '0';
    ch = getchar();
  }
  return p * f;
}
struct node {
  long long x, y, d, next;
} edge[N];
long long len, first[N];
void ins(long long x, long long y, long long d) {
  len++;
  edge[len].x = x;
  edge[len].y = y;
  edge[len].d = d;
  edge[len].next = first[x];
  first[x] = len;
}
long long ans[N], rt, tot, lc[N << 2], rc[N << 2], lazy[N << 2], c[N << 2];
long long a[N], b[N];
void push_down(long long u) {
  if (lazy[u]) {
    lazy[lc[u]] += lazy[u];
    lazy[rc[u]] += lazy[u];
    c[lc[u]] += lazy[u];
    c[rc[u]] += lazy[u];
    lazy[u] = 0;
  }
}
void link(long long &u, long long L, long long R, long long k, long long cc) {
  if (!u) u = ++tot, c[u] = 0;
  if (L == R) {
    c[u] += cc;
    return;
  }
  push_down(u);
  long long mid = (L + R) >> 1;
  if (k <= mid)
    link(lc[u], L, mid, k, cc);
  else
    link(rc[u], mid + 1, R, k, cc);
  c[u] = min(c[lc[u]], c[rc[u]]);
}
void chg(long long u, long long L, long long R, long long l, long long r,
         long long cc) {
  if (l > r) return;
  if (L == l && R == r) {
    c[u] += cc;
    lazy[u] += cc;
    return;
  }
  long long mid = (L + R) >> 1;
  push_down(u);
  if (r <= mid)
    chg(lc[u], L, mid, l, r, cc);
  else if (l > mid)
    chg(rc[u], mid + 1, R, l, r, cc);
  else {
    chg(lc[u], L, mid, l, mid, cc);
    chg(rc[u], mid + 1, R, mid + 1, r, cc);
  }
  c[u] = min(c[lc[u]], c[rc[u]]);
}
int main() {
  long long n = read();
  long long m = read();
  long long q = read();
  len = 0;
  memset(first, -1, sizeof(first));
  for (long long i = 1; i < n; i++) a[i] = read(), b[i] = read();
  for (long long i = 1; i <= m; i++) {
    long long x = read();
    long long y = read();
    long long d = read();
    ins(x, y, d);
  }
  rt = tot = 0;
  memset(lc, 0, sizeof(lc));
  memset(rc, 0, sizeof(rc));
  memset(c, 63, sizeof(c));
  for (long long i = 1; i < n; i++) link(rt, 1, n - 1, i, b[i]);
  long long s = 0;
  for (long long i = 1; i <= n; i++) {
    long long x = i;
    for (long long k = first[x]; k != -1; k = edge[k].next) {
      long long y = edge[k].y;
      chg(rt, 1, n - 1, 1, y - 1, edge[k].d);
      s += edge[k].d;
    }
    ans[i] = min(s, c[rt]) + a[i];
  }
  rt = tot = 0;
  memset(lc, 0, sizeof(lc));
  memset(rc, 0, sizeof(rc));
  memset(c, 63, sizeof(c));
  for (long long i = 1; i <= n; i++) link(rt, 1, n, i, ans[i]);
  printf("%lld\n", c[rt]);
  while (q--) {
    long long x = read();
    long long w = read();
    link(rt, 1, n, x, w - a[x]);
    a[x] = w;
    printf("%lld\n", c[rt]);
  }
  return 0;
}
