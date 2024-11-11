#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int a[N], dp[N][N][N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      dp[i][j][0] = a[j] - a[i];
      if (j == i + 1) {
        dp[i][j][1] = a[j] - a[i];
        continue;
      }
      for (int k = 1; k <= j - i; ++k) {
        int pas = 256, r(j);
        while (pas) {
          if (r - pas > i &&
              max(a[j] - a[r - pas], dp[i][r - pas][k - 1]) <
                  max(a[j] - a[r - pas + 1], dp[i][r - pas + 1][k - 1]))
            r -= pas;
          pas >>= 1;
        }
        dp[i][j][k] = max(a[j] - a[r], dp[i][r][k - 1]);
      }
    }
  }
  long long ans(0);
  int s, f, c, r;
  for (int i = 0; i < m; ++i) {
    cin >> s >> f >> c >> r;
    ans = max(ans, 1LL * c * dp[s - 1][f - 1][min(r, f - s)]);
  }
  cout << ans;
  return 0;
}
