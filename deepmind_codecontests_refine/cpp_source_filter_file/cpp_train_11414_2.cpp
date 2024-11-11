#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > vs;
int getCode(int x, int y) { return (1 << (3 * x + (2 - y))); }
int n, cost[5], step, col[1010], dp[4096][1010];
string str[4];
int main() {
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < 4; i++) step |= getCode(i, 0);
  cin >> n;
  for (int i = 1; i <= 4; i++) cin >> cost[i];
  for (int i = 0; i < 4; i++) cin >> str[i];
  for (int j = 0; j < n; j++)
    for (int i = 0; i < 4; i++)
      if (str[i][j] == '*') col[j] |= getCode(i, 2);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 1; i + k <= 4 && j + k <= 3; k++) {
        vs.push_back((make_pair((0), (cost[k]))));
        for (int x = i; x < i + k; x++)
          for (int y = j; y < j + k; y++) vs.back().first |= getCode(x, y);
      }
  for (int i = 0; i < 4096; i++) fill(dp[i], dp[i] + 1010, 2147483647);
  dp[col[0]][0] = 0;
  int res = 2147483647;
  for (int j = 0, m, c, m_; j < n; j++) {
    for (int mask = 4095; mask >= 0; mask--) {
      if (dp[mask][j] == 2147483647) continue;
      for (auto v : vs) {
        tie(m, c) = v;
        m_ = (mask | m) ^ m;
        dp[m_][j] = min(dp[m_][j], dp[mask][j] + c);
      }
      if (j + 4 < n) dp[0][j + 3] = min(dp[0][j + 3], dp[mask][j] + cost[4]);
      if ((mask & step) == 0)
        dp[(mask << 1) | col[j + 1]][j + 1] =
            min(dp[(mask << 1) | col[j + 1]][j + 1], dp[mask][j]);
    }
  }
  cout << min(res, dp[0][n]) << endl;
  return 0;
}
