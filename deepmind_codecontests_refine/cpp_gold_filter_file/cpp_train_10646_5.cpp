#include <bits/stdc++.h>
const long long N = 18 + 2;
const long long M = 1 << N;
long long n, q;
long long sum[M << 2];
bool rev[N];
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while ('0' > ch or ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
  while ('0' <= ch and ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
void build(long long p, long long l, long long r) {
  if (l == r) {
    sum[p] = read();
    return;
  }
  long long mid = l + r >> 1;
  build((p << 1), l, mid), build((p << 1 | 1), mid + 1, r);
  sum[p] = sum[(p << 1)] + sum[(p << 1 | 1)];
}
void modify(long long p, long long l, long long r, long long depth, long long k,
            long long val) {
  if (l == r) {
    sum[p] = val;
    return;
  }
  long long mid = l + r >> 1;
  if (k <= mid)
    modify((p << 1) | rev[depth], l, mid, depth - 1, k, val);
  else
    modify((p << 1) | rev[depth] ^ 1, mid + 1, r, depth - 1, k, val);
  sum[p] = sum[(p << 1)] + sum[(p << 1 | 1)];
}
long long query(long long p, long long l, long long r, long long depth,
                long long x, long long y) {
  if (x <= l and r <= y) return sum[p];
  long long mid = l + r >> 1, res = 0;
  if (x <= mid) res += query((p << 1) | rev[depth], l, mid, depth - 1, x, y);
  if (mid + 1 <= y)
    res += query((p << 1) | rev[depth] ^ 1, mid + 1, r, depth - 1, x, y);
  return res;
}
signed main() {
  n = read(), q = read();
  build(1, 1, 1LL << n);
  for (long long opt, x, y; q--;) {
    opt = read();
    if (opt == 1)
      x = read(), y = read(), modify(1, 1, 1LL << n, n, x, y);
    else if (opt == 2)
      for (x = read(); ~x; x--) rev[x] ^= 1;
    else if (opt == 3)
      x = read(), rev[x + 1] ^= 1;
    else
      x = read(), y = read(), printf("%lld\n", query(1, 1, 1LL << n, n, x, y));
  }
  return 0;
}
