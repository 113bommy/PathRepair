#include <bits/stdc++.h>
using namespace std;
unsigned long long dp[4][4][2];
char as[200001];
unsigned long long mod = 1000000007;
unsigned long long three[200001];
void solve() {
  dp[0][0][0] = 1;
  three[0] = 1;
  int n;
  cin >> n;
  int qs = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> as[i];
    if (as[i] == '?') qs += 1, three[qs] = (three[qs - 1] * 3) % mod;
  }
  char a;
  for (int i = 1; i <= n; ++i) {
    char a = as[i];
    int ii = i & 1, ik = ii ^ 1;
    for (int j = 0; j <= 3; ++j) {
      dp[0][j][ii] = dp[0][j][ik];
      dp[1][j][ii] = dp[1][j][ik];
      dp[2][j][ii] = dp[2][j][ik];
      dp[3][j][ii] = dp[3][j][ik];
      if (a == 'a')
        dp[1][j][ii] = (dp[1][j][ii] + dp[0][j][ik]) % mod;
      else if (a == '?' && j != 0)
        dp[1][j][ii] = (dp[1][j][ii] + dp[0][j - 1][ik]) % mod;
      if (a == 'b')
        dp[2][j][ii] = (dp[2][j][ii] + dp[1][j][ik]) % mod;
      else if (a == '?' && j != 0)
        dp[2][j][ii] = (dp[2][j][ii] + dp[1][j - 1][ik]) % mod;
      if (a == 'c')
        dp[3][j][ii] = (dp[3][j][ii] + dp[2][j][ik]) % mod;
      else if (a == '?' && j != 0)
        dp[3][j][ii] = (dp[3][j][ii] + dp[2][j - 1][ik]) % mod;
    }
  }
  unsigned long long ans = 0;
  for (int j = 0; j <= 3; ++j)
    if (qs >= j) {
      ans += dp[3][j][n & 1] * three[qs - j] % mod;
    }
  cout << ans % mod << endl;
}
int main() {
  unsigned c;
  solve();
}
