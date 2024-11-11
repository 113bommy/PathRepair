#include <bits/stdc++.h>
using namespace std;
int64_t f[111][10], ans, C[111][111];
int a[10], n;
const int64_t mod = 1000000007;
int main() {
  **C = 1;
  for (int i = 1; i <= 100; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  scanf("%d", &n);
  for (int i = 0; i < 10; ++i) scanf("%d", a + i);
  for (int i = 0; i <= n; ++i) {
    f[i][9] = i >= a[9];
    for (int j = 8; j >= 1; --j)
      for (int k = a[j]; k <= i; ++k)
        f[i][j] = (f[i][j] + f[i - k][j + 1] * C[i][k]) % mod;
    for (int k = *a; k <= i; ++k)
      f[i][0] = (f[i][0] + f[i - k][1] * C[i - 1][k]);
  }
  for (int i = 1; i <= n; ++i) ans += f[i][0];
  ans %= mod;
  printf("%lld\n", ans);
}
