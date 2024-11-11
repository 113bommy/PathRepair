#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  x *= f;
}
long long n, l, r, k;
long long ans = -1;
int main() {
  read(n);
  read(l);
  read(r);
  read(k);
  long long len = r - l + 1;
  if (len < 0) len += n;
  if (n <= 12000) {
    for (long long i = 0; i <= len - 1; ++i)
      for (long long j = 0; j <= n - len; ++j) {
        long long kk = k - 1;
        kk %= i + j + n;
        kk++;
        if (kk == i + len) ans = (((ans) > (i + j)) ? (ans) : (i + j));
        kk = k - 1;
        kk %= i + j + 1 + n;
        kk++;
        if (kk == i + len || kk == i + len + 1)
          ans = (((ans) > (i + j + 1)) ? (ans) : (i + j + 1));
      }
  } else {
    long long lim = k / n;
    if (k <= 2 * len && k >= len)
      ans = (((ans) >
              (n - len + ((((k - len + 1)) < (len)) ? ((k - len + 1)) : (len))))
                 ? (ans)
                 : (n - len +
                    ((((k - len + 1)) < (len)) ? ((k - len + 1)) : (len))));
    for (long long t = 1; t <= lim; ++t) {
      long long kk = k - t * n - len;
      long long a0 = kk - t;
      long long b0 = 1 - a0;
      long long zl =
          (((ceil((a0 - len) / (double)t)) > (ceil(-b0 / (double)(t + 1))))
               ? (ceil((a0 - len) / (double)t))
               : (ceil(-b0 / (double)(t + 1))));
      long long zr =
          (((floor(a0 / (double)t)) < (floor((n - len - b0) / (double)(t + 1))))
               ? (floor(a0 / (double)t))
               : (floor((n - len - b0) / (double)(t + 1))));
      if (zl <= zr) {
        ans = (((ans) > (a0 - t * zl + b0 + (t + 1) * zl))
                   ? (ans)
                   : (a0 - t * zl + b0 + (t + 1) * zl));
        ans = (((ans) > (a0 - t * zr + b0 + (t + 1) * zr))
                   ? (ans)
                   : (a0 - t * zr + b0 + (t + 1) * zr));
      }
      kk = k - t * n - len + 1;
      a0 = kk - t;
      b0 = 1 - a0;
      zl = (((ceil((a0 - len) / (double)t)) > (ceil(-b0 / (double)(t + 1))))
                ? (ceil((a0 - len) / (double)t))
                : (ceil(-b0 / (double)(t + 1))));
      zr = (((floor((a0 - 1) / (double)t)) <
             (floor((n - len - b0) / (double)(t + 1))))
                ? (floor((a0 - 1) / (double)t))
                : (floor((n - len - b0) / (double)(t + 1))));
      if (zl <= zr) {
        ans = (((ans) > (a0 - t * zl + b0 + (t + 1) * zl))
                   ? (ans)
                   : (a0 - t * zl + b0 + (t + 1) * zl));
        ans = (((ans) > (a0 - t * zr + b0 + (t + 1) * zr))
                   ? (ans)
                   : (a0 - t * zr + b0 + (t + 1) * zr));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
