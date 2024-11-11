#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-10;
int dp[2][1000010];
int main() {
  string str[2];
  cin >> str[0];
  reverse(str[0].begin(), str[0].end());
  str[0] += '0';
  int n = str[0].size(), c = 1;
  for (int i = 0; i < n; i++) {
    if (str[0][i] == '0')
      str[1].push_back('1');
    else
      str[1].push_back('0');
  }
  for (int i = 0; i < n; i++) {
    if (str[1][i] == '1' && c == 1) {
      str[1][i] = '0';
    } else if (str[1][i] == '0' && c == 1) {
      str[1][i] = '1';
      c = 0;
    } else {
      c = 0;
    }
  }
  fill(&dp[0][0], &dp[0][0] + 2 * 100010, INF);
  dp[0][0] = dp[1][0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++) {
      if (str[j][i] == '1') {
        dp[j][i + 1] = min(dp[j][i + 1], dp[j][i] + 1);
      } else {
        dp[j][i + 1] = min(dp[j][i + 1], dp[j][i]);
        dp[j][i + 1] = min(dp[j][i + 1], dp[1 - j][i] + 1);
      }
    }
  int p = 1;
  vector<int> res;
  int pos = n, line = 0;
  while (pos > 0) {
    if (str[line][pos - 1] == '1') {
      res.push_back(p * pos);
    } else {
      if (dp[line][pos] == dp[1 - line][pos - 1] + 1) {
        res.push_back(p * pos);
        p *= -1;
        line = 1 - line;
      }
    }
    pos--;
  }
  cout << dp[0][n] << endl;
  for (int i = 0; i < (int)res.size(); i++) {
    if (res[i] > 0)
      cout << "+2^" << res[i] - 1 << endl;
    else
      cout << "-2^" << -res[i] - 1 << endl;
  }
  return 0;
}
