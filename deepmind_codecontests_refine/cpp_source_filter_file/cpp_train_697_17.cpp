#include <bits/stdc++.h>
using namespace std;
long long dp[55][55][5005];
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto &x : arr) {
    cin >> x.first;
  }
  for (auto &x : arr) {
    cin >> x.second;
  }
  map<int, vector<int>> mp;
  for (auto x : arr) {
    mp[x.first].push_back(x.second);
  }
  vector<pair<int, vector<int>>> a;
  for (auto &x : mp) {
    a.push_back(x);
    sort(a.back().second.begin(), a.back().second.end());
    ;
  }
  int nn = a.size();
  for (int i = 0; i < 55; i++) {
    for (int j = 0; j < 55; j++) {
      fill(dp[i][j], dp[i][j] + 5005, 1e15);
    }
  }
  dp[0][0][0] = 0;
  int pre = 0;
  for (int i = 0; i < nn; i++) {
    auto &den = a[i].second;
    int val = a[i].first, sz = den.size();
    for (int j = 0; j <= pre; j++) {
      for (int k = 0; k <= pre * 100; k++) {
        dp[i + 1][j + sz][k] = min(dp[i + 1][j + sz][k], dp[i][j][k]);
        int sum = 0;
        for (int r = sz - 1; r >= 0; r--) {
          sum += den[r];
          int rem = max(0, j - (sz - r));
          dp[i + 1][rem + r][k + sum] = min(dp[i + 1][rem + r][k + sum],
                                            dp[i][j][k] + 1ll * val * (sz - r));
        }
      }
    }
    pre += sz;
  }
  long long ans = LLONG_MAX;
  for (int i = 1; i <= 100 * n; i++) {
    ans = min(ans, (dp[nn][0][i] * 1000) / i);
  }
  cout << ans << endl;
  return 0;
}
