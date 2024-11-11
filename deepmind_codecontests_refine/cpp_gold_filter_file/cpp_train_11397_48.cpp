#include <bits/stdc++.h>
using namespace std;
int n, k;
long long int m;
const int maxn = 1100;
long long int dp[maxn][maxn][2];
long long int pw[maxn];
int main() {
  cin >> n >> k >> m;
  for (int i = 0; i <= 9; i++) {
    if (!i || i % k != 0) {
      dp[1][i % k][1]++;
      dp[1][i % k][1] %= m;
    } else {
      dp[1][0][0]++;
      dp[1][0][0] %= m;
    }
  }
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = (pw[i - 1] * 10) % k;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < k; j++) {
      for (int kt = 0; kt <= 9; kt++) {
        if (i == n - 1 && kt == 0) continue;
        int ost = (j + kt * pw[i]) % k;
        dp[i + 1][ost][0] += dp[i][j][0];
        dp[i + 1][ost][0] %= m;
        if (ost == 0 && kt != 0) {
          dp[i + 1][ost][0] += dp[i][j][1];
          dp[i + 1][ost][0] %= m;
        } else {
          dp[i + 1][ost][1] += dp[i][j][1];
          dp[i + 1][ost][1] %= m;
        }
      }
    }
  }
  long long int res = 0;
  for (int i = 0; i <= k; i++) {
    res += dp[n][i][0];
    res %= m;
  }
  cout << res << endl;
  return 0;
}
