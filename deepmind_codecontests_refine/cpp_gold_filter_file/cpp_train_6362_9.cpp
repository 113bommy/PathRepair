#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
inline void print(long long x) {
  if (x < 0) putchar('-'), x = ~x + 1;
  if (x >= 10) print(x / 10);
  putchar((x % 10) | 48);
}
long long n;
long long l, r, k;
signed main() {
  n = read();
  l = read(), r = read(), k = read();
  long long len = 0;
  if (l <= r)
    len = r - l + 1;
  else
    len = n - l + 1 + r;
  if (k < len) {
    printf("-1\n");
  } else {
    k -= len;
    if (k <= len)
      printf("%lld\n", k + (n - (len)) + (k == len ? 0 : 1));
    else {
      if (k < n) {
        printf("-1\n");
      } else {
        long long t = k / n, lf = k % n;
        if (t >= 1e5) {
          long long ans = 0;
          for (long long i = 1; i <= n - (len); ++i) {
            if (k % (n + i) <= i && k % (n + i) <= (len)) ans = i;
          }
          for (long long i = n - (len) + 1; i <= n; ++i) {
            long long minn = i - (n - (len)) - 1;
            if (k % (n + i) >= minn && k % (n + i) <= (len)) ans = i;
          }
          print(ans);
        } else {
          long long ans = 0;
          for (long long p = 0; p <= t; ++p) {
            long long turn = t - p;
            if (lf > turn * n + len) break;
            long long x = lf / turn;
            long long y = lf % turn;
            if (x > n - (len)) {
              while (y < x - (n - (len)) - 1) {
                --x, y += turn;
              }
              if (y <= len) ans = x;
            } else {
              if (y <= x && y <= len) ans = x;
            }
            lf += n;
          }
          print(ans);
        }
      }
    }
  }
  return 0;
}
