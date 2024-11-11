#include <bits/stdc++.h>
using namespace std;
signed main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > cover;
  for (int i = 0; i < n; i++) {
    int x, s;
    cin >> x >> s;
    cover.push_back({x - s, x + s});
  }
  int dp[100000] = {};
  dp[m] = 0;
  for (int i = m - 1; i >= 0; i--) {
    dp[i] = (m - i);
    for (int j = 0; j < n; j++) {
      if (cover[j].first <= i && cover[j].second > i)
        dp[i] = min(dp[i], dp[i + 1]);
      if (cover[j].first > i) {
        int u = cover[j].first - i - 1;
        dp[i] = min(dp[i], u + dp[min(m, cover[j].second + u)]);
      }
    }
  }
  cout << dp[0];
}
