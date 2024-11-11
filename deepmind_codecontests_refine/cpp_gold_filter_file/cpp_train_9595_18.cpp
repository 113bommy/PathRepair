#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int mo(int x) {
  if (x < 0) x += mod;
  if (x >= mod) x -= mod;
  return x;
}
int dp[1005][1005], sum[1005][1005], summ[1005][1005], a[1005], cf[1005], n, K;
signed main() {
  cin >> n >> K;
  if (K == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[0] = -1e9;
  sort(a + 1, a + n + 1);
  int ans = 0, maxn = a[n] / (K - 1);
  for (int i = 1; i <= maxn; i++) {
    dp[0][0] = sum[0][0] = 1;
    int tmp = 0;
    for (int j = 1; j <= n; j++) {
      while (a[j] - a[tmp] >= i) tmp++;
      sum[j][0] = 1;
      for (int k = 1; k <= K; k++) {
        dp[j][k] = sum[tmp - 1][k - 1];
        sum[j][k] = mo(sum[j - 1][k] + dp[j][k]);
      }
      ans = mo(ans + dp[j][K]);
    }
  }
  cout << ans;
}
