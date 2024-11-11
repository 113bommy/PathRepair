#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int mod = 1e9 + 7;
int n, k, dp[N][N + N], a[N];
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[n + 1] = a[1];
  dp[0][N] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < N + N; j++) {
      if (dp[i - 1][j]) {
        if (a[i] == a[i + 1]) {
          add(dp[i][j], dp[i - 1][j]);
          add(dp[i][j], 1LL * dp[i - 1][j] * (k - 1) % mod);
        } else {
          add(dp[i][j - 1], dp[i - 1][j]);
          add(dp[i][j + 1], dp[i - 1][j]);
          add(dp[i][j], 1LL * dp[i - 1][j] * (k - 2) % mod);
        }
      }
    }
  }
  int ans = 0;
  for (int i = N + 1; i < N + N; i++) add(ans, dp[n][i]);
  printf("%d", ans);
  return 0;
}
