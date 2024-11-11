#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> v;
long long dp[80][80];
pair<int, int> from[80][80];
set<int> s;
int main() {
  int t;
  cin >> t;
  while (t) {
    t--;
    int i, j, n, k;
    cin >> n >> k;
    v.clear();
    s.clear();
    for (i = 1; i <= n; i++) {
      int a, b;
      cin >> a >> b;
      v.push_back({{b, a - b}, i});
      s.insert(i);
    }
    sort(v.begin(), v.end());
    for (i = 0; i <= n; i++) {
      for (j = 0; j <= k; j++) {
        dp[i][j] = -100000000000;
        from[i][j] = {-1, -1};
      }
    }
    dp[0][0] = 0;
    for (i = 0; i < n; i++) {
      int ind = v[i].second;
      long long a = v[i].first.second, b = v[i].first.first;
      for (j = 0; j <= k; j++) {
        if (dp[i + 1][j] < dp[i][j] + (k - 1) * b) {
          from[i + 1][j] = {ind, j};
          dp[i + 1][j] = dp[i][j] + (k - 1) * b;
        }
        if (j > 0 && dp[i + 1][j] < dp[i][j - 1] + (j - 1) * b + a) {
          from[i + 1][j] = {ind, j - 1};
          dp[i + 1][j] = dp[i][j - 1] + (j - 1) * b + a;
        }
      }
    }
    vector<int> ans;
    int nx = n, ny = k;
    while (ny != 0) {
      pair<int, int> p = from[nx][ny];
      if (p.second != ny) {
        ans.push_back(p.first);
        s.erase(p.first);
      }
      nx--;
      ny = p.second;
    }
    cout << 2 * n - k << endl;
    for (i = k - 1; i > 0; i--) {
      cout << ans[i] << " ";
    }
    for (int x : s) {
      cout << x << " " << -x << " ";
    }
    cout << ans[0] << endl;
  }
}
