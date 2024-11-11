#include <bits/stdc++.h>
using namespace std;
long long game(long long* a, long long n, long long k, long long buy_sell,
               long long*** dp) {
  if (k == 0 || n == 0) {
    return 0;
  }
  if (dp[n][k][buy_sell] != -1) {
    return dp[n][k][buy_sell];
  }
  long long ans;
  if (buy_sell == 0) {
    long long o1 = game(a + 1, n - 1, k, 0, dp);
    long long o2 = -a[0] + game(a + 1, n - 1, k, 1, dp);
    ans = max(o1, o2);
  } else {
    long long o1 = game(a + 1, n - 1, k, 1, dp);
    long long o2 = a[0] + game(a + 1, n - 1, k - 1, 0, dp);
    ans = max(o1, o2);
  }
  dp[n][k][buy_sell] = ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  T = 1;
start:
  while (T--) {
    long long k, n;
    cin >> k >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long*** dp = new long long**[n + 1];
    for (long long i = 0; i <= n; i++) {
      dp[i] = new long long*[k + 1];
      for (long long j = 0; j <= k; j++) {
        dp[i][j] = new long long[2];
        for (long long k = 0; k < 2; k++) {
          dp[i][j][k] = -1;
        }
      }
    }
    cout << max(game(a, n, k, 0, dp), (long long)0) << endl;
    for (long long i = 0; i <= n; i++) {
      for (long long j = 0; j <= k; j++) {
        delete[] dp[i][j];
      }
      delete[] dp[i];
    }
    delete[] dp;
  }
  return 0;
}
