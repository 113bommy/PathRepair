#include <bits/stdc++.h>
using namespace std;
int n, k, len, v[100002];
int sum[100002], dp[2][100002][102], l[100002][102];
int Mod(int x) {
  if (x < 0) x += 998244353;
  if (x >= 998244353) x -= 998244353;
  return x;
}
int main() {
  scanf("%d%d%d", &n, &k, &len);
  for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  sum[0] = 1;
  --len;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (v[i] != -1 && v[i] != j) {
        dp[0][i][j] = dp[1][i][j] = 0;
        l[i][j] = 0;
      } else {
        l[i][j] = l[i - 1][j] + 1;
        if (l[i][j] > len) l[i][j] = len;
        dp[0][i][j] = Mod(sum[i - 1] - dp[1][i - 1][j]);
        if (l[i][j] == len) dp[1][i][j] = Mod(sum[i - len] - dp[0][i - len][j]);
        sum[i] = Mod(sum[i] + dp[0][i][j]);
      }
    }
  }
  if (len == 0) sum[n] = 0;
  printf("%d\n", sum[n]);
  return 0;
}
