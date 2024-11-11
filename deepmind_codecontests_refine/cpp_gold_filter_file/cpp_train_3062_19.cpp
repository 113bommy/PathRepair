#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> pts[100010];
int dp[810];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    pts[i].first = y, pts[i].second = n - x + 1;
  }
  sort(pts + 1, pts + k + 1);
  for (int i = 1; i < 810; i++) dp[i] = 1e9;
  int cur = 0, ans;
  for (int i = 1; i <= n; i++) {
    while (cur < k && pts[cur + 1].first < i) cur++;
    int cnt = 0;
    dp[0] = min(dp[0], dp[1]);
    int mn = dp[0];
    for (int j = 1; j <= 800; j++) {
      mn = min(mn, dp[j + 1]);
      if (cur < k && pts[cur + 1].first == i && pts[cur + 1].second == j)
        cur++, cnt++;
      dp[j] = min(dp[j + 1] - cnt * 3, mn + (1 + j) * j / 2 + 2 - cnt * 3);
    }
  }
  ans = min(dp[0], dp[1]) + k * 3;
  cout << ans << endl;
  return 0;
}
