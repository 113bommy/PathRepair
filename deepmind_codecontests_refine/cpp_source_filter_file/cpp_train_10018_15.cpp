#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 50;
int n, m, a[N], s[N], c[N];
int dp[N][N], mx[N][N];
int t[N][N], ta[N];
int cost(int x, int y) {
  int z = 0;
  while (y) z += c[x] * y, y /= 2, ++x;
  return z;
}
void ins(int x, int y, int z) {
  if (z < -1e9) return;
  for (int o = 0; o < 15; o++) {
    z += y * c[x], y /= 2, ++x;
    t[x][y] = max(t[x][y], z);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (int i = 1; i <= n + m; i++) scanf("%d", &c[i]);
  memset(dp, -0x3f, sizeof(dp));
  memset(mx, -0x3f, sizeof(mx));
  memset(t, -0x3f, sizeof(t));
  memset(ta, -0x3f, sizeof(ta));
  dp[n + 1][1] = ta[0] = 0;
  for (int i = 0; i <= n; i++) t[i][0] = 0;
  for (int i = n; i; i--) {
    for (int j = 1; j <= n; j++) dp[i][j] = mx[a[i]][j - 1] - s[i];
    for (int j = 0; j <= n; j++)
      dp[i][j + 1] = max(dp[i][j + 1], t[a[i]][j] - s[i]);
    for (int j = 0; j < a[i] - 15; j++) dp[i][1] = max(dp[i][1], ta[j] - s[i]);
    for (int j = 1; j <= n; j++) ins(a[i], j, dp[i][j]);
    for (int j = 1; j <= n; j++) mx[a[i]][j] = max(mx[a[i]][j], dp[i][j]);
    for (int j = 1; j <= n; j++)
      ta[a[i]] = max(ta[a[i]], dp[i][j] + cost(a[i], j));
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) ans = max(ans, ta[i]);
  cout << ans;
  return 0;
}
