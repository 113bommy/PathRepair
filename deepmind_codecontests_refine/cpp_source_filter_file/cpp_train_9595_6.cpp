#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1e3 + 10;
int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b % 2) {
      res = 1LL * res * a % mod;
    }
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  int n, k, a[N], min_id[N], dp[N][N], ans = 0;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    min_id[i] = i - 1;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= a[n] - a[1]; i++) {
    dp[0][0] = 1;
    for (int j = 1; j <= k && j * i <= a[n] - a[1]; j++) {
      dp[0][j] = 0;
    }
    for (int j = 1; j <= n; j++) {
      while (min_id[j] > 0 && a[j] - a[min_id[j]] < i) min_id[j]--;
      dp[j][0] = 1;
      for (int cnt = 1; cnt <= k && cnt * i <= a[n] - a[1]; cnt++) {
        dp[j][cnt] = (dp[min_id[j]][cnt - 1] + dp[j - 1][cnt]) % mod;
      }
    }
    ans += (1LL * (k - 1) * i) <= a[n] - a[1] ? dp[n][k] : 0;
    ans %= mod;
  }
  printf("%d", ans);
  return 0;
}
