#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5, M = 2e4 + 5;
int a[105], b[300];
int dp[105][M];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(dp, 0, sizeof(dp));
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= k; i++) b[i] = i;
    for (int i = 1; i < k; i++) b[k + i] = k - i;
    for (int i = 0; i < 2 * k; i++) dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < 2 * k * n; j++) {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1]);
        if (l < b[j % (2 * k)] + a[i]) dp[i][j] = 0;
      }
    int flag = 0;
    for (int i = 0; i < 2 * k * n; i++)
      if (dp[n][i]) {
        flag = 1;
        break;
      }
    if (flag)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
