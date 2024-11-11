#include <bits/stdc++.h>
using namespace std;
int calculate_S(string, string, int, int);
int main() {
  int n, m;
  string s1, s2;
  cin >> n >> m;
  cin >> s1;
  cin >> s2;
  int answer = calculate_S(s1, s2, n, m);
  cout << answer;
}
int calculate_S(string a, string b, int n, int m) {
  int high = 0;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i] == b[j]) {
        dp[i + 1][j + 1] = max(dp[i][j] + 2, dp[i + 1][j] - 1);
      } else {
        dp[i + 1][j + 1] =
            max(dp[i][j] - 2, max(dp[i + 1][j] - 1, dp[i][j + 1] - 1));
      }
      if (dp[i + 1][j + 1] > high) {
        high = dp[i + 1][j + 1];
      }
    }
  }
  return high;
}
