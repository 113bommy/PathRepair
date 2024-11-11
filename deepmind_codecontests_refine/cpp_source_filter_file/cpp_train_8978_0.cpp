#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long id[n * 2 + 1];
    vector<long long> coin;
    coin.push_back(0LL);
    for (long long i = 1; i <= 2 * n; i++) {
      long long x;
      cin >> x;
      id[x] = i;
    }
    long long csk = 2 * n;
    for (long long i = 2 * n; i >= 1; i--) {
      if (id[i] <= csk) {
        long long x = csk - id[i] + 1;
        coin.push_back(x);
        csk = id[i] - 1;
      }
    }
    long long coin_size = coin.size() - 1;
    long long dp[coin_size + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (long long i = 0; i <= coin_size; i++) dp[i][0] = 1;
    for (long long i = 1; i <= coin_size; i++) {
      for (long long j = 1; j <= n; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= coin[i]) dp[i][j] = dp[i - 1][j - coin[i]];
      }
    }
    if (dp[coin_size][n])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
