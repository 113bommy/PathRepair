#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
int main() {
  int N;
  cin >> N;
  char c;
  vector<vector<int>> dp(N + 10, vector<int>(N + 10, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    if (c == 'f') {
      for (int j = 0; j <= i; j++) dp[i][j + 1] = dp[i - 1][j];
    } else {
      for (int j = 0; j <= i; j++) dp[i][j] = dp[i - 1][j];
      for (int j = i; j >= 1; j--)
        dp[i][j - 1] = (dp[i][j - 1] + dp[i][j]) % mod;
    }
    cin >> c;
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) ans = (ans + dp[N][i]) % mod;
  cout << ans;
}
