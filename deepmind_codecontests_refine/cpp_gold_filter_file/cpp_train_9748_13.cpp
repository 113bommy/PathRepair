#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
long long nedge = 0, p[1000010], c[1000010], nex[1000010], head[1000010];
long long n, m, Q, A[200010], B[200010], t[8000010], add[8000010];
inline void addedge(long long x, long long y, long long z) {
  p[++nedge] = y;
  c[nedge] = z;
  nex[nedge] = head[x];
  head[x] = nedge;
}
inline void pushdown(long long nod) {
  if (!add[nod]) return;
  t[nod * 2] += add[nod];
  t[nod * 2 + 1] += add[nod];
  add[nod * 2] += add[nod];
  add[nod * 2 + 1] += add[nod];
  add[nod] = 0;
}
inline void build(long long l, long long r, long long nod) {
  add[nod] = t[nod] = 0;
  if (l == r) {
    t[nod] = B[l];
    return;
  }
  long long mid = l + r >> 1;
  build(l, mid, nod * 2);
  build(mid + 1, r, nod * 2 + 1);
  t[nod] = min(t[nod * 2], t[nod * 2 + 1]);
}
inline void xg(long long l, long long r, long long i, long long j, long long v,
               long long nod) {
  pushdown(nod);
  if (l >= i && r <= j) {
    t[nod] += v;
    add[nod] += v;
    return;
  }
  long long mid = l + r >> 1;
  if (i <= mid) xg(l, mid, i, j, v, nod * 2);
  if (j > mid) xg(mid + 1, r, i, j, v, nod * 2 + 1);
  t[nod] = min(t[nod * 2], t[nod * 2 + 1]);
}
signed main() {
  n = read();
  m = read();
  Q = read();
  for (long long i = 1; i < n; i++) A[i] = read(), B[i] = read();
  B[n] = 1e18;
  for (long long i = n - 1; i; i--) B[i] = min(B[i + 1], B[i]);
  for (long long i = 1; i <= m; i++) {
    long long x = read(), y = read(), z = read();
    addedge(x, y, z);
  }
  build(0, n, 1);
  for (long long i = 1; i <= n; i++) {
    for (long long k = head[i]; k; k = nex[k]) xg(0, n, 0, p[k] - 1, c[k], 1);
    B[i] = t[1] + A[i];
  }
  build(1, n, 1);
  writeln(t[1]);
  while (Q--) {
    long long x = read(), w = read();
    xg(1, n, x, x, w - A[x], 1);
    A[x] = w;
    writeln(t[1]);
  }
  return 0;
}
