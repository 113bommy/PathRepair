#include <bits/stdc++.h>
using namespace std;
int dp[1003][1003][12][3];
string s, t;
int solve(int i, int j, int k, int cont) {
  if (i < 0 || j < 0) return 0;
  if (dp[i][j][k][cont] != -1) return dp[i][j][k][cont];
  int ret = -9;
  if (s[i] == t[j]) {
    if (cont) {
      ret = max(ret, 1 + solve(i - 1, j - 1, k, 1));
    } else if (k > 0)
      ret = max(ret, 1 + solve(i - 1, j - 1, k - 1, 1));
  }
  ret = max(ret, solve(i - 1, j, k, 0));
  ret = max(ret, solve(i, j - 1, k, 0));
  dp[i][j][k][cont] = ret;
  return ret;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cin >> s >> t;
  for (int i = 0; i < 1003; ++i) {
    for (int j = 0; j < 1003; ++j) {
      for (int k = 0; k < 12; ++k) {
        for (int l = 0; l < 3; ++l) {
          dp[i][j][k][l] = -1;
        }
      }
    }
  }
  int ans = solve(n - 1, m - 1, k, 1);
  cout << ans << "\n";
}
