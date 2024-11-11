#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 13;
int l[N][N], r[N][N];
pair<int, int> dp[N][N];
char a[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _ = 1;
  while (_--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%c", &a[i][0]);
      for (int j = 1; j <= m; j++) {
        l[i][j] = r[i][j] = 1;
        scanf("%c", &a[i][j]);
      }
    }
    for (int j = 1; j <= m; j++) {
      dp[1][j].first = 1;
      for (int i = 2; i <= n; i++) {
        if (a[i][j] == a[i - 1][j]) {
          dp[i][j].first = dp[i - 1][j].first + 1;
        } else {
          dp[i][j].first = 1;
        }
      }
    }
    for (int j = 1; j <= m; j++) {
      dp[n][j].second = 1;
      for (int i = n - 1; i >= 1; i--) {
        if (a[i][j] == a[i + 1][j]) {
          dp[i][j].second = dp[i + 1][j].second + 1;
        } else {
          dp[i][j].second = 1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 2; j <= m; j++) {
        if (a[i][j] != a[i][j - 1]) {
          continue;
        }
        l[i][j] = min(l[i][j - 1] + 1, min(dp[i][j].first, dp[i][j].second));
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = m - 1; j >= 1; j--) {
        if (a[i][j] != a[i][j + 1]) {
          continue;
        }
        r[i][j] = min(r[i][j + 1] + 1, min(dp[i][j].first, dp[i][j].second));
      }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        ans += min(l[i][j], r[i][j]);
      }
    }
    printf("%lld", ans);
  }
}
