#include <bits/stdc++.h>
using namespace std;
int n, m, q;
long long ans;
pair<int, int> grid[2010];
long long inv[200010], fac[200010], f[2010];
int main() {
  int i, j, x, y;
  for (i = 2, inv[0] = inv[1] = 1; i <= 200000; i++)
    inv[i] = (1000000007 - 1000000007 / i) * inv[1000000007 % i] % 1000000007;
  for (i = 2; i <= 200000; i++) inv[i] = inv[i] * inv[i - 1] % 1000000007;
  for (i = 2, fac[0] = fac[1] = 1; i <= 200000; i++)
    fac[i] = i * fac[i - 1] % 1000000007;
  scanf("%d%d%d", &n, &m, &q);
  for (i = 1; i <= q; i++) scanf("%d%d", &grid[i].first, &grid[i].second);
  sort(grid + 1, grid + 1 + q);
  for (i = 1; i <= q; i++) {
    x = grid[i].first - 1;
    y = grid[i].second - 1;
    f[i] = fac[x + y] * inv[x] % 1000000007 * inv[y] % 1000000007;
  }
  ans = fac[n + m - 2] * inv[n - 1] % 1000000007 * inv[m - 1] % 1000000007;
  for (i = 1; i <= q; i++) {
    for (j = i + 1; j <= q; j++) {
      x = grid[j].first - grid[i].first;
      y = grid[j].second - grid[i].second;
      if (x < 0 || y < 0) continue;
      f[j] = (f[j] -
              f[i] * fac[x + y] % 1000000007 * inv[x] % 1000000007 * inv[y] %
                  1000000007 +
              1000000007) %
             1000000007;
    }
    x = n - grid[i].first;
    y = m - grid[i].second;
    ans = (ans -
           f[i] * fac[x + y] % 1000000007 * inv[x] % 1000000007 * inv[y] %
               1000000007 +
           1000000007) %
          1000000007;
  }
  printf("%I64d", ans);
  return 0;
}
