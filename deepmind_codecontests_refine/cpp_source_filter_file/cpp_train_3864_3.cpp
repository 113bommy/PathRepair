#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int n, k, m;
long long int z, q, u, a1, l, r, ax, cx, ay, by, cy, ql, qr, d, x, y;
vector<pair<long long int, long long int> > v[400000];
long long int a[300000];
long long int b[600000];
long long int me(long long int a, long long int b, long long int M) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return me((a * a) % M, b / 2, M);
  else
    return (a % M * me((a * a) % M, (b - 1) / 2, M) % M) % M;
}
long long int mI(long long int a, long long int m) { return me(a, m - 2, m); }
long long int dp[1005][2005][4];
int main() {
  cin >> n >> k;
  dp[1][1][0] = 1;
  dp[1][1][3] = 1;
  dp[1][2][1] = 1;
  dp[1][2][2] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < 2000; j++) {
      dp[i][j][0] += dp[i - 1][j][0] + dp[i - 1][j][1];
      dp[i][j][0] += dp[i - 1][j][2] + dp[i - 1][j - 1][3];
      dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j][1];
      dp[i][j][1] += dp[i - 1][j - 2][2] + dp[i - 1][j - 1][3];
      dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 2][1];
      dp[i][j][2] += dp[i - 1][j][2] + dp[i - 1][j - 1][3];
      dp[i][j][3] += dp[i - 1][j - 1][0] + dp[i - 1][j][1];
      dp[i][j][3] += dp[i - 1][j][2] + dp[i - 1][j][3];
      dp[i][j][0] = dp[i][j][0] % mod;
      dp[i][j][1] = dp[i][j][1] % mod;
      dp[i][j][2] = dp[i][j][2] % mod;
      dp[i][j][3] = dp[i][j][3] % mod;
    }
  }
  long long int s = 0;
  for (int i = 0; i <= 3; i++) {
    s = (s % mod + dp[n][k][i] % mod) % mod;
  }
  cout << s % mod;
}
