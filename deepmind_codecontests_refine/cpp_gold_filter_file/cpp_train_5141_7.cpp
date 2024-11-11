#include <bits/stdc++.h>
using namespace std;
int a[23], f[1 << 23], n, dp[1 << 23];
int main() {
  int T, i, j, k, x, y, m, r, u;
  while (~scanf("%d", &n)) {
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    int mask = 1 << n;
    f[0] = 0;
    for (i = 1; i < mask; i++) f[i] = f[i >> 1] + (i & 1);
    for (i = 0; i < mask; i++) dp[i] = 1000000007;
    dp[1 << (n - 1)] = 1;
    for (i = n - 1; i > 0; i--)
      for (j = (1 << (i + 1)) - 1; j >= (1 << i); j--)
        if (dp[j] < 1000000007)
          for (k = i - 1; k >= 0; k--)
            for (r = k; r >= 0; r--)
              if (a[k] + a[r] == a[i]) {
                dp[u = (j ^ (1 << i) | 1 << (i - 1) | (1 << k) | (1 << r))] =
                    min(dp[u], max(dp[j], f[u]));
              }
    printf("%d\n", dp[1] == 1000000007 ? -1 : dp[1]);
  }
  return 0;
}
