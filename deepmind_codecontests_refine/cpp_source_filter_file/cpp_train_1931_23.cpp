#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3;
const int MAX_M = 1e3;
const int MAX_K = 10;
int dp[MAX_N + 1][MAX_M + 1][MAX_K][2];
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  string s1, s2;
  cin >> s1 >> s2;
  for (int len1 = 0; len1 <= n; len1++) {
    dp[len1][0][0][0] = 0;
    dp[len1][0][0][1] = -1e9;
  }
  for (int len2 = 0; len2 <= m; len2++) {
    dp[0][len2][0][0] = 0;
    dp[0][len2][0][1] = -1e9;
  }
  for (int q = 0; q <= k; q++) {
    dp[0][0][q][0] = dp[0][0][q][1] = -1e9;
  }
  dp[0][0][0][0] = 0;
  int ans = 0;
  for (int len1 = 1; len1 <= n; len1++) {
    for (int len2 = 1; len2 <= m; len2++) {
      for (int q = 1; q <= k; q++) {
        dp[len1][len2][q][0] = dp[len1][len2][q][1] = 0;
        if (s1[len1 - 1] == s2[len2 - 1])
          dp[len1][len2][q][1] = max(max(dp[len1 - 1][len2 - 1][q - 1][0] + 1,
                                         dp[len1 - 1][len2 - 1][q - 1][1] + 1),
                                     dp[len1 - 1][len2 - 1][q][1] + 1);
        dp[len1][len2][q][0] =
            max(max(dp[len1 - 1][len2][q][0], dp[len1 - 1][len2][q][1]),
                max(dp[len1][len2 - 1][q][0], dp[len1][len2 - 1][q][1]));
        ans = max(ans, max(dp[len1][len2][q][0], dp[len1][len2][q][1]));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
