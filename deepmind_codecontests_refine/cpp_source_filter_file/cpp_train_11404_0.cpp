#include <bits/stdc++.h>
const int N = 1e4 + 5;
int ans, n;
double f[2][N];
signed main() {
  scanf("%lld%lf", &n, &f[1][1]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) {
      if (f[i & 1][j] >= 1.0) {
        f[i & 1 ^ 1][j] += (f[i & 1][j] - 1.0) / 2.0;
        f[i & 1 ^ 1][j + 1] += (f[i & 1][j] - 1.0) / 2.0;
        ans++;
      }
      f[i & 1][j] = 0;
    }
  printf("%lld", ans);
  return 0;
}
