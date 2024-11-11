#include <bits/stdc++.h>
using namespace std;
int n, b;
long long dp[10004][2];
int main() {
  int a, k;
  cin >> n >> a >> b >> k;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = (i != b);
    dp[i][0] += dp[i - 1][0];
  }
  for (int d = 1; d <= k; ++d) {
    int kk = d % 2;
    for (int c = 1; c <= n; ++c)
      if (c != b) {
        int d = abs(b - c) - 1;
        int R = min(c + d, n);
        int L = max(c - d, 1);
        long long& a = dp[c][kk];
        a = dp[R][1 - kk] - dp[L - 1][1 - kk] + 1000000007 -
            (dp[c][1 - kk] - dp[c - 1][1 - kk] + 1000000007);
        if (a >= 1000000007) a -= 1000000007;
      }
    for (int c = 1; c <= n; ++c) {
      long long& a = dp[c][kk];
      a += dp[c - 1][kk];
      if (a >= 1000000007) a -= 1000000007;
    }
  }
  cout << (dp[a][k % 2] - dp[a - 1][k % 2] + 1000000007) % 1000000007 << endl;
}
