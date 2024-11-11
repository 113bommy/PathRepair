#include <bits/stdc++.h>
using namespace std;
const int c = 4002, k = -1e9;
int n, m, l[c], s[c], f[c], dp[c][c], maxi;
void upd(int a, int b) {
  if (a > m) return;
  for (int i = 1; i <= b + 1; i++) {
    int x = i - 1;
    dp[a][x] =
        max(dp[a][x], f[a] * x + max(dp[a - 1][2 * x], dp[a - 1][2 * x + 1]));
  }
  upd(a + 1, b / 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m, m = n + m;
  for (int i = 1; i <= n; i++) cin >> l[n + 1 - i];
  for (int i = 1; i <= n; i++) cin >> s[n + 1 - i];
  for (int i = 1; i <= m; i++) cin >> f[i];
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) dp[i][j] = k;
  for (int i = 1; i <= n; i++) {
    int x = l[i], p = f[x] - s[i];
    for (int j = m; j > 0; j--) {
      dp[x][j] = max(dp[x][j], dp[x][j - 1] + p);
    }
    upd(x + 1, m / 2);
  }
  for (int i = 1; i <= m; i++) maxi = max(maxi, dp[i][1]);
  cout << maxi << "\n";
  return 0;
}
