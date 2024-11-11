#include <bits/stdc++.h>
using namespace std;
const int kInf = 2e6;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> a(n);
  vector<vector<int>> d(n, vector<int>(n, kInf));
  for (int i = 0; i < n; i += 1) {
    cin >> a[i];
    for (int j = 0; j < n; j += 1) {
      if (a[i][j] == '1') {
        d[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i += 1) {
    d[i][i] = 0;
  }
  for (int k = 0; k < n; k += 1)
    for (int i = 0; i < n; i += 1)
      for (int j = 0; j < n; j += 1) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  int k;
  cin >> k;
  vector<int> path(k, 0);
  for (int i = 0; i < k; i += 1) {
    cin >> path[i];
    path[i] -= 1;
  }
  vector<int> dp(k, kInf);
  vector<int> from(k, -1);
  dp[0] = 0;
  for (int i = 1; i < k; i += 1) {
    for (int j = max(0, i - n); j < i; j += 1) {
      if (abs(i - j) == d[path[j]][path[i]]) {
        if (dp[j] + 1 < dp[i]) {
          dp[i] = dp[j] + 1;
          from[i] = j;
        }
      }
    }
  }
  int who = k - 1;
  vector<int> ans;
  while (who >= 0) {
    ans.push_back(path[who]);
    who = from[who];
  }
  cout << ans.size() << "\n";
  reverse(ans.begin(), ans.end());
  for (auto temp : ans) cout << temp + 1 << " ";
}
