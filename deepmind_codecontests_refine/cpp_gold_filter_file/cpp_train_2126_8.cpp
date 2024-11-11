#include <bits/stdc++.h>
using namespace std;
pair<int, int> dp[2][200005];
int a[200005], ans[200005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  dp[0][0] = pair<int, int>(0, 4);
  dp[1][0] = pair<int, int>(0, 1);
  for (int i = 1; i <= n; i++) {
    dp[0][i] = dp[0][i - 1];
    dp[1][i] = dp[1][i - 1];
    dp[0][i].second++;
    if (dp[0][i].second == 5) dp[0][i].first++, dp[0][i].second = 0;
    dp[1][i].second++;
    if (dp[1][i].second >= 2) dp[1][i].first++, dp[1][i].second = 0;
    if (a[i] != 0) {
      if (dp[0][i].first <= a[i] && a[i] <= dp[1][i].first) {
        if (dp[0][i].first != a[i]) dp[0][i].first = a[i], dp[0][i].second = 0;
        if (dp[1][i].first != a[i]) {
          dp[1][i].first = a[i], dp[1][i].second = 1;
          if (dp[1][i].first == dp[0][i].first) {
            dp[1][i].second = max(dp[1][i].second, dp[0][i].second);
          }
        }
      } else {
        printf("-1\n");
        return 0;
      }
    }
  }
  if (dp[1][n].second == 0) {
    dp[1][n].second = 1;
    dp[1][n].first--;
    if (dp[1][n].first == dp[0][n].first)
      dp[1][n].second = max(dp[1][n].second, dp[0][n].second);
    if (dp[0][n].first > dp[1][n].first) {
      printf("-1\n");
      return 0;
    }
    if (a[n] != 0) {
      if (a[n] > dp[0][n].first) {
        printf("-1\n");
        return 0;
      }
    }
  }
  printf("%d\n", dp[1][n].first);
  int x = dp[1][n].first, c = dp[1][n].second;
  for (int i = n; i >= 1; i--) {
    ans[i] = x;
    int nx = x, nc = c;
    nc--;
    if (nc == -1) nx--, nc = 4;
    if (nx > dp[1][i - 1].first ||
        (nx == dp[1][i - 1].first && nc > dp[1][i - 1].second)) {
      x = dp[1][i - 1].first;
      c = dp[1][i - 1].second;
    } else {
      x = nx;
      c = nc;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
