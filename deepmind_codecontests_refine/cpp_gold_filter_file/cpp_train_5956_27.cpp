#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  if (!k) {
    cout << "0\n";
    return 0;
  }
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  h.push_back(h[0]);
  long long** dp;
  dp = new long long*[n + 79];
  for (int i = 0; i < n + 2; i++) {
    dp[i] = new long long[2 * n + 79];
    for (int j = 0; j < 2 * n + 79; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][n + 1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int score = 1; score <= 2 * n + 2; score++) {
      if (h[i] != h[i - 1]) {
        dp[i][score] += dp[i - 1][score - 1];
        dp[i][score] += dp[i - 1][score + 1];
        dp[i][score] += (dp[i - 1][score] * (k - 2ll)) % mod;
      } else {
        dp[i][score] = dp[i - 1][score] * k;
      }
      dp[i][score] %= mod;
    }
  }
  long long ans = 0;
  for (int score = n + 2; score <= 2 * n + 1; score++) {
    ans += dp[n][score];
  }
  cout << (ans % mod) << endl;
  return 0;
}
