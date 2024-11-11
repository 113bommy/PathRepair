#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int n, m, t, num[510][510], dp[510][510], sz[510], ans = 1e9;
string s;
vector<int> v;
int main() {
  for (int i = 0; i < 505; i++)
    for (int j = 0; j < 505; j++) dp[i][j] = num[i][j] = 1e9;
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.clear();
    for (int j = 0; j < m; j++)
      if (s[j] == '1') v.push_back(j);
    sz[i] = v.size();
    num[i][v.size()] = 0;
    for (int j = 0; j < v.size(); j++)
      for (int k = j; k < v.size(); k++)
        num[i][v.size() - (k - j + 1)] =
            min(num[i][v.size() - (k - j + 1)], v[k] - v[j] + 1);
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < t + 1; j++) {
      if (dp[i][j] == 1e9) continue;
      for (int k = 0; k < min(t - j + 1, sz[i] + 1); k++)
        dp[i + 1][j + k] = min(dp[i + 1][j + k], dp[i][j] + num[i][k]);
    }
  }
  for (int i = 0; i < t + 1; i++) ans = min(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
