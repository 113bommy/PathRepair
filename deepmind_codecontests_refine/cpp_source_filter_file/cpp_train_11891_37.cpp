#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, m;
int k;
long long dp[1001][1001];
int main() {
  for (int i = 0; i <= 1000; i++) dp[i][0] = 1;
  for (int i = 1; i <= 1000; i++)
    for (int j = 1; j <= i; j++) {
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
    }
  cin >> n >> m >> k;
  long long ans = dp[n - 1][2 * k] * dp[m - 1][2 * k] % mod;
  cout << ans << endl;
}
