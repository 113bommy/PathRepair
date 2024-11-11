#include <bits/stdc++.h>
using namespace std;
long long dp[100005][5], mp[4][100005];
inline long long MAX(long long a, long long b) { return a > b ? a : b; }
inline long long MAX4(long long a, long long b, long long c, long long d) {
  return MAX(MAX(a, b), MAX(c, d));
}
inline long long S(long long i, long long a, long long b, long long c) {
  return mp[a][i] + mp[b][i] + mp[c][i];
}
int main() {
  long long n, ans;
  scanf("%lld", &n);
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= n; j++) scanf("%lld", &mp[i][j]);
  if (n == 1) {
    printf("%lld\n", mp[1][1] + mp[2][1] + mp[3][1]);
    return 0;
  }
  dp[1][0] = S(1, 1, 0, 0);
  dp[1][1] = S(1, 1, 2, 0);
  dp[1][2] = dp[1][3] = S(1, 1, 2, 3);
  dp[1][4] = -0x3f3f3f3f3f3f3f3f;
  for (int i = 2; i < n; i++) {
    dp[i][0] = MAX4(dp[i - 1][0] + S(i, 1, 0, 0), dp[i - 1][1] + S(i, 1, 2, 0),
                    dp[i - 1][2] + S(i, 1, 2, 3), dp[i - 1][4] + S(i, 1, 2, 3));
    dp[i][1] = MAX4(dp[i - 1][0] + S(i, 1, 2, 0), dp[i - 1][1] + S(i, 2, 0, 0),
                    dp[i - 1][2] + S(i, 2, 3, 0), -0x3f3f3f3f3f3f3f3f);
    dp[i][2] = MAX4(dp[i - 1][0] + S(i, 1, 2, 3), dp[i - 1][1] + S(i, 2, 3, 0),
                    dp[i - 1][2] + S(i, 3, 0, 0), dp[i - 1][3] + S(i, 1, 2, 3));
    dp[i][3] = MAX4(dp[i - 1][0] + S(i, 1, 2, 3), dp[i - 1][3] + S(i, 1, 2, 3),
                    -0x3f3f3f3f3f3f3f3f, -0x3f3f3f3f3f3f3f3f);
    dp[i][4] = MAX4(dp[i - 1][2] + S(i, 1, 2, 3), dp[i - 1][4] + S(i, 1, 2, 3),
                    -0x3f3f3f3f3f3f3f3f, -0x3f3f3f3f3f3f3f3f);
  }
  ans = MAX4(dp[n - 1][0] + S(n, 1, 2, 3), dp[n - 1][1] + S(n, 2, 3, 0),
             dp[n - 1][2] + S(n, 3, 0, 0), dp[n - 1][3] + S(n, 1, 2, 3));
  printf("%lld\n", ans);
  return 0;
}
