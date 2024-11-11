#include <bits/stdc++.h>
const int N = 3e5 + 10;
using namespace std;
int n, A[N];
int dp[2][35];
int main() {
  memset(dp, 0x3f, sizeof(dp));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    A[i] /= 100;
  }
  int s = 0, t = 1;
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int a = A[i] / 10;
    for (int j = 0; j <= 31; ++j)
      if (dp[s][j] < dp[0][32]) {
        if (j + a <= 31) dp[t][j + a] = min(dp[t][j + a], dp[s][j] + A[i]);
        int b = min(j, A[i]);
        if (b) dp[t][j - b] = min(dp[t][j - b], dp[s][j] + A[i] - b);
        dp[s][j] = dp[0][32];
      }
    swap(s, t);
  }
  int ans = dp[0][32];
  for (int i = 0; i < 20; ++i) ans = min(ans, dp[s][i]);
  printf("%d00\n", ans);
  return 0;
}
