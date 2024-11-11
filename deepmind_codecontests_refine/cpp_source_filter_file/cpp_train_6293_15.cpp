#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long double inf = 1e99;
long double fac_log[maxn];
long double C(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return fac_log[n] - fac_log[m] - fac_log[n - m];
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    fac_log[i] = fac_log[i - 1] + log(i);
  }
  long double ans = 0.0;
  for (int r = 0; r <= n; ++r) {
    for (int c = 0; c <= n; ++c) {
      int t = n * (r + c) - r * c;
      if (t > k) break;
      long double res = C(m - t, k - t) + C(n, r) + C(n, c) - C(m, k);
      ans += exp(res);
      if (ans > inf) {
        puts("1e99");
        return 0;
      }
    }
  }
  printf("%.12Lf\n", ans);
  return 0;
}
