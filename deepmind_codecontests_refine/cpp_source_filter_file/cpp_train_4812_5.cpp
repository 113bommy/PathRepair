#include <bits/stdc++.h>
using namespace std;
const int maxn = 3500 + 50;
const int INF = 0x3f3f3f3f;
int a[maxn];
int dp[maxn][maxn];
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = max(a[i], a[j]);
      }
    }
    int uncon = m - 1 - k;
    if (uncon < 0) uncon = 0;
    int ans = 0;
    if (uncon) {
      for (int i = 0; i <= k; i++) {
        int sum = INF;
        for (int j = 0; j <= uncon; j++) {
          sum = min(sum, dp[i + j][n - 1 - k + i - uncon + j]);
        }
        ans = max(sum, ans);
      }
    } else {
      for (int i = 0; i <= m - 1; i++) {
        ans = max(ans, max(a[i], a[n - 1 - k + i]));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
