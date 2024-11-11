#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const long long N = 100010;
struct ask {
  long long opt, x;
} a[N];
char s[20];
long long n, lsh[N], len, q, d[N << 2][5], f[N << 2];
inline long long getid(long long x) {
  return lower_bound(lsh + 1, lsh + q + 1, x) - lsh;
}
inline void pushup(long long p) {
  long long ls = p << 1, rs = p << 1 | 1;
  f[p] = (f[ls] + f[rs]) % 5;
  for (long long i = 0; i < 5; ++i)
    d[p][i] = d[ls][i] + d[rs][((i - f[ls]) % 5 + 5) % 5];
}
inline void change(long long p, long long l, long long r, long long x,
                   long long y) {
  if (l == r && r == x) {
    if (y == 0)
      d[p][1] += lsh[x], f[p] = (f[p] + 1) % 5;
    else
      d[p][1] -= lsh[x], f[p] = (f[p] + 4) % 5;
    return;
  }
  long long mid = l + r >> 1, ls = p << 1, rs = p << 1 | 1;
  if (x <= mid)
    change(ls, l, mid, x, y);
  else
    change(rs, mid + 1, r, x, y);
  pushup(p);
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; ++i) {
    scanf("%s", s);
    if (s[0] == 'a') lsh[++len] = (a[i].x = read()), a[i].opt = 0;
    if (s[0] == 'd') lsh[++len] = (a[i].x = read()), a[i].opt = 1;
    if (s[0] == 's') a[i].opt = 2;
  }
  sort(lsh + 1, lsh + len + 1);
  q = unique(lsh + 1, lsh + len + 1) - lsh - 1;
  for (long long i = 1; i <= n; ++i)
    if (a[i].opt <= 1) a[i].x = getid(a[i].x);
  for (long long i = 1; i <= n; ++i) {
    long long opt = a[i].opt, x = a[i].x;
    if (opt <= 1)
      change(1, 1, n, x, opt);
    else
      printf("%lld\n", q ? d[1][3] : 0);
  }
  return 0;
}
