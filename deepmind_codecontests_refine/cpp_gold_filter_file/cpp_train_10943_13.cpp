#include <bits/stdc++.h>
using namespace std;
int n, jc[2002], f[2002], g[2002], h[2002][2002], a[2002][2002], c[2002],
    d[2002];
bool b[2002], bb[2002];
int pow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = 1LL * x * x % 998244353)
    if (y & 1) res = 1LL * res * x % 998244353;
  return res;
}
int main() {
  scanf("%d", &n);
  if (n == 1) {
    putchar('0');
    return 0;
  }
  jc[0] = 1;
  for (int i = 1; i < n; ++i) jc[i] = 1LL * jc[i - 1] * i % 998244353;
  f[1] = 0, f[2] = 1;
  for (int i = 3; i <= n; ++i) {
    f[i] = 1LL * (i - 1) * (f[i - 1] + f[i - 2]) % 998244353;
    if (f[i] >= 998244353) f[i] -= 998244353;
  }
  for (int i = 0; i < n; ++i) g[i] = pow(f[n], i);
  h[1][1] = 0, h[1][0] = 1;
  for (int i = 2; i <= n; ++i) {
    h[i][i] = f[i];
    for (int j = i - 1; j >= 0; --j)
      h[i][j] = (h[i][j + 1] + h[i - 1][j]) % 998244353;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[1][i]);
    int m = a[1][i] - 1;
    for (int j = a[1][i]; j; j -= j & (-j)) m -= c[j];
    ans += 1LL * m * jc[n - i] % 998244353 * g[n - 1] % 998244353;
    if (ans >= 998244353) ans -= 998244353;
    for (int j = a[1][i]; j <= n; j += j & (-j)) ++c[j];
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) b[j] = bb[j] = 0, c[j] = d[j] = 0;
    for (int j = 1; j <= n; ++j)
      for (int k = j; k <= n; k += k & (-k)) ++d[k];
    for (int j = 1, x = n; j <= n; ++j) {
      scanf("%d", &a[i][j]);
      int m = a[i][j] - 1;
      for (int k = a[i][j]; k; k -= k & (-k)) m -= c[k];
      if (a[i - 1][j] < a[i][j] && !b[a[i - 1][j]]) --m;
      bb[a[i - 1][j]] = 1;
      if (!b[a[i - 1][j]])
        for (int k = a[i - 1][j]; k <= n; k += k & (-k)) --d[k];
      int mm = 0;
      for (int k = a[i][j] - 1; k; k -= k & (-k)) mm += d[k];
      if (!b[a[i - 1][j]]) --x;
      ans += (1LL * (m - mm) * h[n - j][x] + 1LL * mm * h[n - j][x - 1]) %
             998244353 * g[n - i] % 998244353;
      if (ans >= 998244353) ans -= 998244353;
      if (!bb[a[i][j]]) --x;
      b[a[i][j]] = 1;
      if (!bb[a[i][j]])
        for (int k = a[i][j]; k <= n; k += k & (-k)) --d[k];
      for (int k = a[i][j]; k <= n; k += k & (-k)) ++c[k];
    }
  }
  printf("%d", ans);
}
