#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long g[1000010], C[1010][1010], f[1010][1010], ln[1010];
long long ppow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1LL) {
      ans = ans * a % 1000000007;
      b--;
    } else {
      a = a * a % 1000000007;
      b /= 2;
    }
  }
  return ans;
}
int main() {
  C[0][0] = 1;
  for (int i = 1; i <= 1000; i++)
    for (int j = 0; j <= i; j++)
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
  f[1][1] = 1;
  for (int i = 2; i <= 1000; i++)
    for (int j = 1; j <= i; j++)
      if (j == 1)
        f[i][j] = 1;
      else
        f[i][j] = (f[i - 1][j] * j % 1000000007 + f[i - 1][j - 1]) % 1000000007;
  ln[0] = 1;
  for (int i = 1; i <= 1000; i++)
    ln[i] = (ln[i - 1] * (long long)i) % 1000000007;
  while (scanf("%d %d %d", &n, &m, &k) != EOF) {
    g[0] = 1;
    for (int i = 1; i <= k; i++)
      g[i] =
          (((g[i - 1] * (k + 1 - i)) % 1000000007) * ppow(i, 1000000007 - 2)) %
          1000000007;
    if (m == 1) {
      cout << ppow(k, n) << endl;
      continue;
    }
    long long ans = 0;
    for (int x = 1; x <= n && x <= k; x++)
      for (int y = 0; y <= x; y++) {
        if (x * 2 - y > k) continue;
        if (y == 0 && m != 2) continue;
        long long ttemp = 1;
        ttemp = ttemp * g[2 * x - y] % 1000000007;
        ttemp = ttemp * C[2 * x - y][y] % 1000000007;
        ttemp = ttemp * C[2 * x - 2 * y][x - y] % 1000000007;
        ttemp = ttemp * ppow(f[n][x], 2) % 1000000007;
        ttemp = ttemp * ppow(ln[x], 2) % 1000000007;
        ttemp = ttemp * ppow(y, n * (m - 2)) % 1000000007;
        ans = (ans + ttemp) % 1000000007;
      }
    cout << ans << endl;
  }
  return 0;
}
