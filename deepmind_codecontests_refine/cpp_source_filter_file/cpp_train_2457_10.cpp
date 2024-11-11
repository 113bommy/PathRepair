#include <bits/stdc++.h>
using namespace std;
const int mxn = 5005;
int dp[mxn][mxn], ans, n, a[mxn];
int md7[8], pos[114514];
inline void ckmax(int& x, int y) {
  if (x < y) x = y;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i < j)
        dp[i][j] =
            max({md7[a[i] % 7], pos[a[i] - 1], pos[a[i] + 1], dp[0][i]}) + 1;
      else
        dp[i][j] = dp[j][i];
      ckmax(ans, dp[i][j]);
      ckmax(md7[a[j] % 7], dp[i][j]);
      ckmax(pos[a[j]], dp[i][j]);
    }
    memset(md7, 0, sizeof(md7));
    memset(pos, 0, sizeof(pos));
  }
  cout << ans << '\n';
}
