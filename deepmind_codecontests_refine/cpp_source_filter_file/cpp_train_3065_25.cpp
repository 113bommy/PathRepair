#include <bits/stdc++.h>
using namespace std;
const int arr = 5e5 + 100;
int dp[100100][110];
int a[100100], b[100100];
vector<int> vec[arr];
signed main() {
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 101; j++) dp[i][j] = 1e9;
  dp[0][0] = 0;
  for (int i = 1; i <= m; i++) vec[b[i]].push_back(i);
  for (int i = 0; i <= 1e5 + 100; i++) vec[i].push_back(1e9);
  for (int i = 0; i < n; i++)
    for (int cnt = 0; cnt <= 101; cnt++)
      if (dp[i][cnt] <= m) {
        dp[i + 1][cnt] = min(dp[i + 1][cnt], dp[i][cnt]);
        dp[i + 1][cnt + 1] =
            min(dp[i + 1][cnt + 1],
                *lower_bound(vec[a[i + 1]].begin(), vec[a[i + 1]].end(),
                             dp[i][cnt] + 1));
      }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int cnt = 0; cnt <= 101; cnt++)
      if (i + dp[i][cnt] + cnt * e <= s && dp[i][cnt] <= m) {
        ans = max(ans, cnt);
      }
  cout << ans;
}
