#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 18;
const int inf = 2e9;
const int N = 2e6 + 5;
int all, cost[N], n, m, x, y, ters[N], duz[N], pre[N], t, t2, ans = inf;
char str[22];
int dp[21][1 << 21];
int calc(int x, int y) {
  if (y == 1) return 0;
  int last = ters[x];
  for (int j = m; j >= 0; j--) {
    int t = ters[y] >> (m - j);
    int t2 = ((1 << j) - 1) & last;
    if (t == t2) return j;
  }
}
int main() {
  scanf("%d", &n);
  memset(dp, 11, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%s", str);
    int t = 0;
    if (i == 1) m = strlen(str);
    for (int j = 1; j <= m; j++) {
      if (str[m - j] == '1') t += (1 << j - 1);
    }
    ters[i] = t;
    all += m - calc(i - 1, i);
  }
  for (int i = 1; i <= n; i++) {
    int ans = inf, cc = calc(i - 1, i);
    for (int j = 0; j <= m; j++)
      ans = min(ans, dp[j][ters[i] >> (m - j)] + cc - j);
    for (int j = 0; j <= m; j++)
      dp[j][ters[i - 1] & (1 << j) - 1] =
          min(dp[j][ters[i - 1] & (1 << j) - 1], ans);
  }
  int ans = inf;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= (1 << m) - 1; j++) ans = min(ans, dp[i][j]);
  cout << all + ans << '\n';
  return 0;
}
