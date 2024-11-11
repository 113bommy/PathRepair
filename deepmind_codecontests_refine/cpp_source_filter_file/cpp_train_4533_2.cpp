#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 20) + 10;
int n, m, a[maxn], dp[21][maxn];
char ch[maxn];
int main() {
  scanf("%d%d", &n, &m);
  memset(a, 0, sizeof(a));
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    scanf("%s", ch);
    for (int j = 0; j < m; ++j) a[j] = a[j] * 2 + ch[j] - '0';
  }
  for (int i = 1; i <= m; ++i) dp[0][a[i]]++;
  for (int mask = 0; mask < 1 << n; ++mask) {
    for (int i = 0; i < n; ++i) dp[1][mask] += dp[0][mask ^ (1 << i)];
  }
  for (int k = 2; k <= n; ++k) {
    for (int mask = 0; mask < 1 << n; ++mask) {
      for (int i = 0; i < n; ++i) dp[k][mask] += dp[k - 1][mask ^ (1 << i)];
      dp[k][mask] = (dp[k][mask] + (k - 2 - n) * dp[k - 2][mask]) / k;
    }
  }
  int ans = 2e9;
  for (int mask = 0; mask < 1 << n; ++mask) {
    int nowans = 0;
    for (int i = 1; i <= n; ++i) nowans += dp[i][mask] * min(i, n - i);
    ans = min(ans, nowans);
  }
  cout << ans << endl;
}
