#include <bits/stdc++.h>
using namespace std;
long long int dp[2005][2005];
int main() {
  int n, k;
  cin >> n >> k;
  long long int s = 0;
  dp[0][1] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 1; j <= n; j++) {
      for (int p = j; p <= n; p += j) {
        (dp[i + 1][p] += dp[i][j]) % 1000000007;
      }
    }
  }
  for (int i = 1; i <= n; ++i) (s += dp[k][i]) %= 1000000007;
  cout << s;
  return 0;
}
