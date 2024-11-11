#include <bits/stdc++.h>
using namespace std;
int n, m, b, mod;
int a[505];
int dp[505][505];
void d(int x) {
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= b; j++) {
      if (j - x >= 0) {
        dp[i][j] += dp[i - 1][j - x];
        dp[i][j] %= mod;
      }
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &b, &mod);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    d(a[i]);
  }
  int ans = 0;
  for (int i = 0; i <= b; i++) {
    ans += dp[m][i];
    ans %= mod;
  }
  printf("%d\n", ans);
  return 0;
}
