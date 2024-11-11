#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 20;
int a[51][20005];
int dp[51][20005];
int pref1[20005], pref2[20005], suf1[20005], suf2[20005];
int n, m, k;
int sum[52][20005];
int s(int i, int a, int b) {
  int x = sum[i][b];
  if (a) x -= sum[i][a - 1];
  return x;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      sum[i][j] = a[i][j];
      if (j) sum[i][j] += sum[i][j - 1];
    }
    sum[i][m] = sum[i][m - 1];
  }
  int ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j + k <= m; ++j) {
      if (i == n - 1)
        dp[i][j] = s(i, j, j + k - 1);
      else {
        int mx = -inf;
        if (j + 1 < k)
          mx = max(mx, suf2[k] - s(i + 1, j, k));
        else
          mx = max(mx, suf2[j]);
        if (j + k - 1 + k > m)
          mx = max(mx, pref2[m - k] - s(i + 1, m - k + 1, j + k - 1));
        else
          mx = max(pref2[j + k - 1], mx);
        if (j - k >= 0) mx = max(mx, pref1[j - k]);
        if (j + k < m) mx = max(mx, suf1[j + k]);
        dp[i][j] = mx + s(i, j, j + k - 1) + s(i + 1, j, j + k - 1);
      }
      if (i == 0) ans = max(ans, dp[i][j]);
    }
    memset(suf1, 0, sizeof suf1);
    memset(suf2, 0, sizeof suf2);
    for (int j = 0; j < m; ++j) {
      pref1[j] = dp[i][j];
      if (j) pref1[j] = max(pref1[j], pref1[j - 1]);
      pref2[j] = dp[i][j];
      if (j)
        pref2[j] = max(pref2[j], pref2[j - 1]) - a[i][j];
      else
        pref2[j] -= a[i][j];
    }
    for (int j = m - 1; j >= 0; --j) {
      suf1[j] = max(dp[i][j], suf1[j + 1]);
      if (j - k + 1 >= 0)
        suf2[j] = max(dp[i][j - k + 1], suf2[j + 1]) - a[i][j];
    }
  }
  cout << ans << '\n';
}
