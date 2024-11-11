#include <bits/stdc++.h>
using namespace std;
const int Max = 2e5 + 5;
const int Mod = 1e9 + 7;
int dp[Max][2];
long long qpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % Mod;
    x = x * x % Mod;
    y >>= 1;
  }
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long a = 0, q = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'a') {
      a = (a + qpow(3, q)) % Mod;
      dp[i][1] = dp[i - 1][1];
      dp[i][0] = dp[i - 1][0];
    } else if (s[i - 1] == 'b') {
      dp[i][0] = (dp[i - 1][0] + a) % Mod;
      dp[i][1] = dp[i - 1][1];
    } else if (s[i - 1] == 'c') {
      dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % Mod;
      dp[i][0] = dp[i - 1][0];
    } else {
      dp[i][1] = (dp[i - 1][1] * 3ll % Mod + dp[i - 1][0]) % Mod;
      dp[i][0] = (dp[i - 1][0] * 3ll % Mod + a) % Mod;
      a = (3ll * a % Mod + qpow(3, q)) % Mod;
      q++;
    }
  }
  cout << dp[n][1] << '\n';
}
