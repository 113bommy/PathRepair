#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 5;
int dp[MAXN][2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  a.push_back(make_pair(0, 1));
  a.push_back(make_pair(0, 1));
  for (int i = 0; i < 2 * n; i++) {
    int v;
    cin >> v;
    a.push_back(make_pair(v, i + 1));
  }
  sort(a.begin(), a.end());
  for (int i = 1; i <= n; i++) {
    int prev0 = a[2 * i - 2].second;
    int prev1 = a[2 * i - 1].second;
    int cur0 = a[2 * i].second;
    int cur1 = a[2 * i + 1].second;
    dp[i][0] = min(dp[i - 1][0] + abs(cur0 - prev0) + abs(cur1 - prev1),
                   dp[i - 1][1] + abs(cur0 - prev1) + abs(cur1 - prev0));
    dp[i][1] = min(dp[i - 1][0] + abs(cur1 - prev0) + abs(cur0 - prev1),
                   dp[i - 1][1] + abs(cur0 - prev0) + abs(cur1 - prev1));
  }
  cout << max(dp[n][0], dp[n][1]);
  return 0;
}
