#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAX = 1e7 + 1;
const long long inf = 1e18;
long long mod = 1e9 + 7;
long long solve(int n) {
  if (n < 3) return 0;
  long long dp[n + 1][n + 1];
  for (long long gap = 0; gap <= n; gap++) {
    for (long long i = 1, j = gap; j <= n && i <= n; i++, j++) {
      if (j < i + 2)
        dp[i][j] = 0;
      else {
        dp[i][j] = inf;
        for (long long k = i + 1; k < j; k++) {
          long long val = dp[i][k] + dp[k][j] + i * j * k;
          if (dp[i][j] > val) dp[i][j] = val;
        }
      }
    }
  }
  return dp[1][n];
}
int main() {
  int N;
  cin >> N;
  cout << solve(N) << endl;
  return 0;
}
