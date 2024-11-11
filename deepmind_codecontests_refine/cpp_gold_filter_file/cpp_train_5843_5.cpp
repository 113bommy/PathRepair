#include <bits/stdc++.h>
using namespace std;
int n, k, x;
long long int lis[5010];
long long int dp[5010][5010];
long long int hist[5010][2];
int main() {
  int i;
  scanf("%d%d%d", &n, &k, &x);
  for (i = 0; i < n; i++) scanf("%lld", &lis[i]);
  long long int ans = -1;
  memset(dp, -1, sizeof dp);
  for (i = 1; i <= x; i++) {
    int cur;
    int in = 0, fin = 1;
    hist[0][0] = 0;
    hist[0][1] = n;
    for (cur = n - 1; cur >= 0; cur--) {
      while (in < fin && hist[in][1] - cur - 1 >= k) in++;
      if (in == fin || hist[in][0] <= -2)
        break;
      else
        dp[cur][i] = lis[cur] + hist[in][0];
      if (dp[cur][i - 1] >= 0) {
        while (dp[cur][i - 1] >= hist[fin - 1][0] && fin > in) fin--;
        hist[fin][0] = dp[cur][i - 1];
        hist[fin][1] = cur;
        fin++;
      }
    }
  }
  for (i = 0; i < k; i++)
    if (dp[i][x] > ans) ans = dp[i][x];
  printf("%lld\n", ans);
  return 0;
}
