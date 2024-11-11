#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
char a[255][255], temp[255][255];
int dp[255][(1 << 16)][2][2];
int n, m;
int calc(int r, int c, int mask, int penalty, int above) {
  if (r == n) return calc(0, c + 1, mask, penalty, 0);
  if (c == m) return 1;
  if (dp[c * n + r][mask][penalty][above] != -1)
    return dp[c * n + r][mask][penalty][above];
  int ans = 0;
  if (a[r][c] == 'x')
    ans = calc(r + 1, c, mask & (~(1 << r)), penalty, 0);
  else {
    if ((mask & (1 << r)) || above)
      ans = calc(r + 1, c, mask, penalty, above);
    else if (penalty == 0)
      ans = calc(r + 1, c, mask, 1, above);
    ans += calc(r + 1, c, (mask | (1 << r)), penalty, 1);
    if (ans >= MOD) ans %= MOD;
  }
  dp[c * n + r][mask][penalty][above] = ans;
  return ans;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n > m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) temp[j][i] = a[i][j];
    swap(n, m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] = temp[i][j];
  }
  cout << calc(0, 0, 0, 0, 0) << endl;
  return 0;
}
