#include <bits/stdc++.h>
using i64 = long long;
const int N = 1000007, P = 1000000007;
i64 n, m, md, a[N], b[N], c[N], ans;
int main() {
  scanf("%lld", &n), m = ceil(sqrt(n) + 1e-8) - 1, md = n % P;
  for (i64 i = 1, t; i <= m; ++i)
    t = i * i % P, a[i] = (a[i - 1] + t) % P, b[i] = (b[i - 1] + t * t) % P,
    c[i] = (c[i - 1] + t * t % P * t) % P;
  for (i64 i = 1, j = m, k; i <= m; ++i) {
    for (; i * i + j * j > n; --j)
      ;
    k = i * i % P,
    ans = (ans + (1 + md - k) * (2 + md - k) % P * (md + k + k) % P * (j + 1) +
           (4 + 3 * md - 12 * k % P - 6 * md * k % P + 6 * k * k + P + P) % P *
               a[j] +
           (6 * k - 3 * md % P - 6 + P + P) % P * b[j] + 2 * c[j]) %
          P;
  }
  ans = 2 * ((P + 1) / 3) * ans % P,
  ans = (ans + md * (md + 1) % P * (md + 2) % P * ((P + 1) / 6) % P),
  printf("%lld", ans);
}
