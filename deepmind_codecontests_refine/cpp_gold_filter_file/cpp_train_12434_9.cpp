#include <bits/stdc++.h>
using namespace std;
const int maxn = ((int)1e5) + 5;
long long int dp[maxn][301];
int a[maxn], b[maxn];
int n, m, s, e;
set<int> pos[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> s >> e;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    pos[b[i]].insert(i);
  }
  long long int ans = 0;
  fill(&dp[0][0], &dp[0][0] + maxn * 301, (long long int)1e9);
  for (int i = 0; i <= n; i++) {
    for (int used = 0; used <= min(i, min(n, (s / e))); used++) {
      if (i == 0 || used == 0) {
        dp[i][used] = 0;
        continue;
      }
      long long int& res = dp[i][used];
      res = min(res, dp[i - 1][used]);
      int p = dp[i - 1][used - 1];
      int toFind = a[i - 1];
      auto it = pos[toFind].lower_bound(p);
      if (it != pos[toFind].end()) {
        res = min(res, *it + 1ll);
      }
      int deleted = i + dp[i][used];
      int usedEnergy = e * used;
      if (deleted + usedEnergy <= s) {
        ans = max(ans, used + 0ll);
      }
    }
  }
  cout << ans;
  return 0;
}
