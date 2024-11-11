#include <bits/stdc++.h>
using namespace std;
long long s, n, ans, dp[5001][5001], i, j;
char a[5001];
const int MOD = 1e9 + 7;
int main() {
  dp[0][0] = 1;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 1; i < n; i++) {
    if (a[i - 1] == 'f') {
      for (j = 0; j < i; j++) dp[i][j + 1] = dp[i - 1][j];
    } else {
      s = 0;
      for (j = i - 1; j >= 0; j--) {
        s = (s + dp[i - 1][j]) % MOD;
        dp[i][j] = s;
      }
    }
  }
  s = 0;
  for (j = 0; j < n; j++) {
    s = (s + dp[n - 1][j]) % MOD;
  }
  cout << s;
  return 0;
}
