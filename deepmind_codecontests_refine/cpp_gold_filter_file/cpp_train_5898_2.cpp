#include <bits/stdc++.h>
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")
using namespace std;
const int P = 1e9 + 7, i2 = P / 2 + 1, i6 = P / 6 + 1, N = 1e6 + 5;
long long n, m;
int r, f1[N], f2[N], f3[N];
int main() {
  scanf("%lld", &n);
  long long g1 = (n + 1) % P, g3 = (long long)g1 * g1 % P * g1 % P;
  while ((long long)m * m <= n) m++;
  m--;
  for (register int i = 1, _lim_ = m; i <= _lim_; i++) {
    long long v1 = (long long)i * i % P, v2 = (long long)v1 * v1 % P,
              v3 = (long long)v1 * v2 % P;
    f1[i] = (f1[i - 1] + v1) % P;
    f2[i] = (f2[i - 1] + v2) % P;
    f3[i] = (f3[i - 1] + v3) % P;
  }
  for (register int x = 0, _lim_ = m; x <= _lim_; x++) {
    long long s = 0, v1 = (long long)x * x % P, v2 = (long long)v1 * v1 % P,
              v3 = (long long)v1 * v2 % P;
    while ((long long)x * x + (long long)m * m > n) m--;
    s = ((g3 + g1 * (3 * v1 - 3 * v2 - 1) + v1 - v2 * 3 + v3 * 2) % P *
             (m + 1) % P +
         (3 * g1 + 1 - (3 * g1 + 3) * v1 * 2 + v2 * 6) % P * f1[m] % P +
         3 * (v1 * 2 - g1 - 1) * f2[m] + 2 * f3[m]) %
        P;
    s = (s * 2 - g3 + g1 - v1 * (3 * g1 + 1) + v2 * (3 * g1 + 3) - v3 * 2) % P;
    r = (r + s * (1 << (x > 0))) % P;
  }
  r = (long long)r * i6 % P;
  if (r < 0) r += P;
  printf("%d\n", r);
  return 0;
}
