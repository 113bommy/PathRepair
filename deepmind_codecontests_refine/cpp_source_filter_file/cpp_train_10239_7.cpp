#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
long long dp[2][N];
long long dp1[2][N];
long long A[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) cin >> A[i];
  for (int i = 2; i <= n; ++i) {
    long long &x = dp[0][i];
    long long &y = dp[1][i];
    if (A[i - 1] % 2 == 0) {
      x = max(x, A[i - 1] + dp[0][i - 1]);
      y = max(y, A[i - 1] - 1 + dp[1][i - 1]);
      y = max(y, A[i - 1] + dp[0][i - 1]);
    } else {
      if (A[i - 1] != 1) x = max(x, A[i - 1] - 1 + dp[0][i - 1]);
      y = max(y, A[i - 1] + dp[1][i - 1]);
    }
  }
  for (int i = n - 1; i >= 1; --i) {
    long long &x = dp1[0][i];
    long long &y = dp1[1][i];
    if (A[i] % 2 == 0) {
      x = max(x, A[i] + dp1[0][i + 1]);
      y = max(y, A[i] - 1 + dp1[1][i + 1]);
      y = max(y, A[i] + dp1[0][i + 1]);
    } else {
      if (A[i - 1] != 1) x = max(x, A[i] - 1 + dp1[0][i + 1]);
      y = max(y, A[i] + dp1[1][i + 1]);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, dp[0][i] + dp1[1][i]);
    ans = max(ans, dp1[0][i] + dp[1][i]);
  }
  cout << ans << endl;
}
