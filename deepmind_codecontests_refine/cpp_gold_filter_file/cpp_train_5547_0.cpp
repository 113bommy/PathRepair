#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
bool comp(long long a, long long b) { return a > b; }
void sol() {}
int main() {
  int r, n;
  cin >> r >> n;
  vector<int> t(n + 1);
  vector<pair<int, int>> coor(n + 1);
  coor[0] = {1, 1};
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    cin >> coor[i].first;
    cin >> coor[i].second;
  }
  vector<pair<pair<int, int>, pair<int, int>>> dp(n + 1);
  dp[0].first = {1, 1};
  for (int cur = 0; cur <= n; cur++) {
    for (int next = cur + 1; next <= min(cur + 4 * r, n); next++) {
      if (t[next] >= dp[cur].second.second +
                         abs(dp[cur].first.first - coor[next].first) +
                         abs(dp[cur].first.second - coor[next].second)) {
        if (dp[next].second.first <= dp[cur].second.first) {
          dp[next].second.first = dp[cur].second.first + 1;
          dp[next].first.first = coor[next].first;
          dp[next].first.second = coor[next].second;
          dp[next].second.second = t[next];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, dp[i].second.first);
  }
  cout << ans << endl;
}
