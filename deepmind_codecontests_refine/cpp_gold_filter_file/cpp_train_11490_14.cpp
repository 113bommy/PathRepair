#include <bits/stdc++.h>
using namespace std;
const int N = 5005, INF = 500000;
int n, h[N], dp[N][N], psum[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", h + i);
  for (int i = 1; i <= n; i++) psum[i] = psum[i - 1] + h[i];
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;
    dp[i][i + 1] = -INF;
    int k = i;
    for (int j = i; j >= 2; j--) {
      int tot = psum[i] - psum[j - 1];
      for (; k >= 1 && psum[j - 1] - psum[k - 1] <= tot; k--) {
      }
      ++k;
      if (k <= j - 1)
        dp[i][j] = 1 + dp[j - 1][k];
      else
        dp[i][j] = -INF;
    }
    for (int j = i; j >= 1; j--) dp[i][j] = max(dp[i][j + 1], dp[i][j]);
  }
  printf("%d\n", n - dp[n][1]);
}
