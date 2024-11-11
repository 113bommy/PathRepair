#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    sum = sum * 10 + (c ^ 48);
    c = getchar();
  }
  return sum;
}
void write(long long x) {
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
}
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
long long const maxn = 200005;
long long const p = 1e9;
long long n, m, f[maxn], add[maxn << 2];
struct matrix {
  long long a[3][3];
  inline void clear() { memset(a, 0, sizeof(a)); }
} sum_ma[maxn];
struct node {
  long long fi, se;
} sum[maxn << 2];
inline matrix operator*(matrix a, matrix b) {
  matrix c;
  c.clear();
  for (long long i = 1; i <= 2; i++)
    for (long long j = 1; j <= 2; j++)
      for (long long k = 1; k <= 2; k++)
        c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % p) % p;
  return c;
}
inline node det(node x, matrix y) {
  return (node){(x.fi * y.a[1][1] % p + x.se * y.a[1][2] % p) % p,
                (x.fi * y.a[2][1] % p + x.se * y.a[2][2] % p) % p};
}
inline void pushup(long long k, long long l, long long r, long long mid) {
  node temp = det(sum[k << 1 | 1], sum_ma[mid - l + 1]);
  sum[k].fi = (sum[k << 1].fi + temp.fi) % p;
  sum[k].se = (sum[k << 1].se + temp.se) % p;
}
void build(long long k, long long l, long long r) {
  if (l == r) {
    sum[k] = (node){read(), 0};
    return;
  }
  long long mid = (l + r) >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  pushup(k, l, r, mid);
}
inline void Add(long long k, long long l, long long r, long long v) {
  add[k] = (add[k] + v) % p;
  sum[k].fi = (sum[k].fi + f[r - l] * v % p) % p;
  if (r - l > 1) sum[k].se = (sum[k].se + f[r - l - 1] * v % p) % p;
}
inline void pushdown(long long k, long long l, long long r, long long mid) {
  if (add[k] == 0) return;
  Add(k << 1, l, mid, add[k]);
  Add(k << 1 | 1, mid + 1, r, add[k]);
  add[k] = 0;
}
void change(long long k, long long l, long long r, long long x, long long v) {
  if (l == r) {
    sum[k] = (node){v, 0};
    return;
  }
  long long mid = (l + r) >> 1;
  pushdown(k, l, r, mid);
  if (x <= mid) change(k << 1, l, mid, x, v);
  if (mid < x) change(k << 1 | 1, mid + 1, r, x, v);
  pushup(k, l, r, mid);
}
void change(long long k, long long l, long long r, long long x, long long y,
            long long v) {
  if (l >= x && r <= y) return Add(k, l, r, v);
  long long mid = (l + r) >> 1;
  pushdown(k, l, r, mid);
  if (x <= mid) change(k << 1, l, mid, x, y, v);
  if (mid < y) change(k << 1 | 1, mid + 1, r, x, y, v);
  pushup(k, l, r, mid);
}
node query(long long k, long long l, long long r, long long x, long long y) {
  if (l >= x && r <= y) return sum[k];
  long long mid = (l + r) >> 1;
  pushdown(k, l, r, mid);
  if (y <= mid) return query(k << 1, l, mid, x, y);
  if (x > mid) return query(k << 1 | 1, mid + 1, r, x, y);
  node L = query(k << 1, l, mid, x, y);
  node R = query(k << 1 | 1, mid + 1, r, x, y);
  node temp = det(R, sum_ma[mid - max(l, x) + 1]);
  return (node){(temp.fi + L.fi) % p, (temp.se + L.se) % p};
}
signed main() {
  n = read(), m = read();
  f[0] = f[1] = 1;
  for (long long i = 2; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % p;
  for (long long i = 1; i <= n; i++) f[i] = (f[i] + f[i - 1]) % p;
  sum_ma[0].a[1][1] = sum_ma[0].a[2][2] = 1;
  sum_ma[1].a[1][1] = sum_ma[1].a[1][2] = sum_ma[1].a[2][1] = 1;
  for (long long i = 2; i <= n; i++) sum_ma[i] = sum_ma[i - 1] * sum_ma[1];
  build(1, 1, n);
  for (long long i = 1; i <= m; i++) {
    long long opt = read();
    if (opt == 1) {
      long long x = read(), v = read();
      change(1, 1, n, x, v);
    }
    if (opt == 3) {
      long long x = read(), y = read(), v = read();
      change(1, 1, n, x, y, v);
    }
    if (opt == 2) {
      long long x = read(), y = read();
      writeln(query(1, 1, n, x, y).fi);
    }
  }
  return 0;
}
