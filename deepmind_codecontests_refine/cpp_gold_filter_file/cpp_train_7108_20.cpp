#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int mod = 998244353;
int a[maxn], pre[maxn];
int dp[maxn][maxn], sum[maxn][maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(a + 1, a + 1 + n, 2 * a[i]) - a;
    if (pos != n + 1) {
      pre[pos] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = max(pre[i - 1], pre[i]);
  }
  dp[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    sum[0][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (pre[j] >= i - 1) {
        dp[i][j] =
            (sum[i - 1][pre[j]] + 1ll * dp[i - 1][j] * (pre[j] - i + 2) % mod) %
            mod;
      }
      sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
    }
  }
  printf("%d\n", dp[n][n]);
  return 0;
}
