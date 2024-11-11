#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 100 + 10;
const int INF = 10000000;
int x[maxn], y[maxn];
int sum[maxn];
int n;
long long c[1100][1100], dp[maxn][maxn];
void init() {
  c[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    c[i][0] = c[i][i] = c[0][i] = 1;
    for (int j = 1; j <= i - 1; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]), sum[i] = sum[i - 1] + x[i];
  for (int i = 1; i <= n; i++) scanf("%d", &y[i]);
  dp[0][0] = 1;
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= sum[i]; j++) {
      for (int k = 0; k <= y[i + 1]; k++) {
        if (j + x[i + 1] - k < 0) break;
        (dp[i + 1][j + x[i + 1] - k] += dp[i][j] * c[j + x[i + 1]][k]) %= mod;
      }
    }
  }
  long long ans = 1;
  for (int i = n; i >= 1; i--) {
    (ans *= c[sum[i]][x[i]]) %= mod;
  }
  (ans *= dp[n][0]) %= mod;
  printf("%lld\n", ans);
  return 0;
}
