#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int c[maxn], f[maxn], h[maxn], dp[515][5005];
int main() {
  int n, k, z, tmp;
  scanf("%d%d", &n, &k);
  z = n * k;
  for (int i = 1; i <= z; i++) scanf("%d", &tmp), c[tmp]++;
  for (int i = 1; i <= n; i++) scanf("%d", &tmp), f[tmp]++;
  for (int i = 1; i <= k; i++) scanf("%d", &h[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= z; j++) {
      for (int l = 0; l <= k; l++) {
        dp[i][j + l] = max(dp[i][j + l], dp[i - 1][j] + h[l]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < maxn; i++)
    if (f[i]) res += dp[f[i]][c[i]];
  printf("%d\n", res);
  return 0;
}
