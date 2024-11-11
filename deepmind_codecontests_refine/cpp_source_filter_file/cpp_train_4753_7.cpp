#include <bits/stdc++.h>
using namespace std;
string s[555];
int dp[555], v[555], ones[555];
vector<pair<int, int> > vc[555];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1') ones[cnt++] = j + 1;
    }
    memset(v, 0, sizeof(v));
    ones[cnt] = m + 1;
    for (int j = 0; j < cnt; j++) {
      for (int k = j; k < cnt; k++) {
        int len = cnt - (k - j + 1);
        int value = m - (ones[k] - ones[j] + 1);
        v[len] = max(v[len], value);
      }
    }
    for (int j = 0; j <= k; j++) {
      if (v[j]) vc[i].push_back(make_pair(j, v[j]));
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = k; j >= 0; j--) {
      for (int k = 0; k < vc[i].size(); k++) {
        if (j >= vc[i][k].first)
          dp[j] = max(dp[j], dp[j - vc[i][k].first] + vc[i][k].second);
      }
    }
  }
  cout << n * m - dp[k] << endl;
  return 0;
}
