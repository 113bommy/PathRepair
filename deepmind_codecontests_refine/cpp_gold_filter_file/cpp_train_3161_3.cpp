#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y;
vector<string> arr;
vector<pair<long long, long long>> col;
void solve() {
  cin >> n >> m >> x >> y;
  arr.resize(n);
  col.resize(m);
  vector<vector<pair<long long, long long>>> dp(
      m + 1, vector<pair<long long, long long>>(y + 1));
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < m; i++) {
    long long w = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j][i] == '.') w++;
    }
    col[i] = {w, n - w};
  }
  for (int i = 0; i <= y; i++) dp[0][i] = {1e6, 1e6};
  for (int i = 0; i <= m; i++) dp[i][0] = {0, 0};
  long long mnw = 0, mnb = 0;
  for (int i = 1; i <= m; i++) {
    long long w = 1e6, b = 1e6;
    for (int j = 1; j <= y; j++) {
      if (j == 1) {
        dp[i][j].first = mnb + col[i - 1].first;
        dp[i][j].second = mnw + col[i - 1].second;
      } else {
        dp[i][j].first = dp[i - 1][j - 1].first + col[i - 1].first;
        dp[i][j].second = dp[i - 1][j - 1].second + col[i - 1].second;
      }
      if (j >= x && j <= y) {
        w = min(w, dp[i][j].first);
        b = min(b, dp[i][j].second);
      }
    }
    mnw = w;
    mnb = b;
  }
  long long ans = 1e7;
  for (int i = x; i <= y; i++) {
    ans = min(ans, dp[m][i].first);
    ans = min(ans, dp[m][i].second);
  }
  cout << ans;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
