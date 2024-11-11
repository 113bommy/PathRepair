#include <bits/stdc++.h>
using namespace std;
const int maxn = 36;
long long dp[maxn][maxn];
int main() {
  long long n, h;
  cin >> n >> h;
  for (long long i = 0; i <= h; i++) dp[0][i] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++)
      for (long long k = 0; k < i; k++) {
        dp[i][j] += dp[k][j - 1] * dp[i - 1 - k][j - 1];
      }
  cout << dp[n][n] - dp[n][h - 1] << endl;
}
