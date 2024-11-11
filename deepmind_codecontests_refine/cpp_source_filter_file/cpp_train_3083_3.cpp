#include <bits/stdc++.h>
using namespace std;
const int M = 5001;
const int inf = 1e9 + 100;
int n, m, k, q;
pair<int, pair<int, int>> qq[250001];
int check(int tt) {
  pair<int, pair<int, int>> pp = {tt, {M, M}};
  int ind = upper_bound(qq, qq + q, pp) - qq;
  int grid[n + 1][m + 1];
  memset(grid, 0, sizeof(grid));
  for (int i = 0; i < ind; i++) {
    grid[qq[i].second.first][qq[i].second.second] = 1;
  }
  int dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (grid[i][j] == 1)
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
      if (dp[i][j] >= k) return 1;
    }
  }
  return 0;
}
int main() {
  cin >> n >> m >> k >> q;
  for (int i = 0; i < q; i++) {
    cin >> qq[i].second.first >> qq[i].second.second >> qq[i].first;
  }
  sort(qq, qq + q);
  int ll = 1, rr = 1e9 + 3, mid;
  while (1) {
    mid = (ll + rr) / 2;
    if (ll == rr) break;
    if (check(mid) == 1) {
      rr = mid;
    } else
      ll = mid + 1;
  }
  if (check(mid) == 1)
    cout << mid << endl;
  else
    cout << -1 << endl;
  return 0;
}
