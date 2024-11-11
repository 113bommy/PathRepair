#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 55, M = 2e4 + 5, K = 25;
int n, m, k;
int a[N][M];
int dp[N][M];
int s[N][M];
int mx[N][2 * K];
int tot[N];
int sum(int x1, int y1, int x2, int y2) {
  return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}
int l_b(int x, int cur) {
  int l = 1, r = tot[cur], ans = 100;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (mx[cur][mid] < x) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (ans == 100)
    return tot[cur] + 1;
  else
    return ans;
}
int main() {
  int i, j;
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (i = 1; i <= n + 1; i++)
    for (j = 1; j <= m; j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m - k + 1; j++) {
      if (i == 1)
        dp[i][j] = sum(i, j, i + 1, j + k - 1);
      else {
        vector<int> v;
        for (int j2 = max(1, j - k + 1); j2 <= j; j2++) {
          if (dp[i - 1][j2] >= mx[i - 1][2 * k]) v.push_back(dp[i - 1][j2]);
          dp[i][j] = max(dp[i][j], dp[i - 1][j2] + sum(i, j, i + 1, j + k - 1) -
                                       sum(i, j, i, j2 + k - 1));
        }
        for (int j2 = j + 1; j2 <= min(m - k + 1, j + k - 1); j2++) {
          if (dp[i - 1][j2] >= mx[i - 1][2 * k]) v.push_back(dp[i - 1][j2]);
          dp[i][j] = max(dp[i][j], dp[i - 1][j2] + sum(i, j, i + 1, j + k - 1) -
                                       sum(i, j2, i, j + k - 1));
        }
        sort(v.begin(), v.end());
        int i1 = 1, j1 = v.size() - 1;
        while (i1 <= tot[i - 1] && j1 >= 0) {
          if (mx[i - 1][i1] > v[j1]) {
            break;
          }
          if (mx[i - 1][i1] == v[j1]) {
            i1++;
            j1--;
            continue;
          }
        }
        dp[i][j] = max(dp[i][j], mx[i - 1][i1] + sum(i, j, i + 1, j + k - 1));
      }
      int pos = l_b(dp[i][j], i), i1;
      if (pos > 2 * k) continue;
      for (i1 = tot[i]; i1 >= pos; i1--) mx[i][i1 + 1] = mx[i][i1];
      mx[i][pos] = dp[i][j];
      tot[i]++;
      if (tot[i] > 2 * k) tot[i] = 2 * k;
    }
  }
  int ans = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m - k + 1; j++) ans = max(ans, dp[i][j]);
  }
  cout << ans << endl;
}
