#include <bits/stdc++.h>
using namespace std;
istream &in = cin;
int n;
vector<string> s;
int dp[30][30];
int main() {
  in >> n;
  s.resize(n + 1);
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; ++i) in >> s[i];
  for (int k = 1; k <= n; ++k) {
    int h = s[k][0] - 'a', t = s[k][(int)s[k].size() - 1] - 'a';
    for (int i = 'a' - 'a'; i <= 'z' - 'a'; ++i)
      if (dp[i][h] > 0) dp[i][t] = max(dp[i][t], dp[i][h] + (int)s[k].size());
    dp[h][t] = max(dp[h][t], (int)s[k].size());
  }
  int ret = 0;
  for (int i = 0; i < 30; ++i) ret = max(ret, dp[i][i]);
  cout << ret << endl;
  return 0;
}
