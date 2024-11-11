#include <bits/stdc++.h>
using namespace std;
int a[505000], c[505000], d[505000], n, k, dp[5050 * 2][5050], r;
pair<int, int> b[505000];
int main() {
  scanf("%d%d", &k, &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  for (int i = 1; i < n; i++)
    d[i] = b[i].first = a[i] - a[i - 1], b[i].second = i;
  sort(b + 1, b + n);
  for (int i = 1; i < min(n, k * 2 + 2); i++) c[b[i].second] = 1;
  for (int i = 1; i <= k; i++) dp[0][i] = 1e9;
  for (int i = 1; i < n; i++) {
    if (!c[i]) continue;
    r++;
    for (int j = 1; j <= min(r, k); j++)
      dp[r][j] = min(dp[r - 1 - c[i - 1]][j - 1] + d[i], dp[r - 1][j]);
    for (int j = r + 1; j <= k; j++) dp[r][j] = 1e9;
  }
  cout << dp[r][k] << endl;
  return 0;
}
