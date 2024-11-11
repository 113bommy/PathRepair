#include <bits/stdc++.h>
using namespace std;
const long long N = 2004;
long long dp[N][N], temp[N][N][2];
long long cn[N][2], a[N], n;
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) a[i]--;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    cn[i][0] = cn[i - 1][0] + !a[i];
    cn[i][1] = cn[i - 1][1] + a[i];
  }
  for (long long i = 1; i <= n / 2; i++) swap(a[i], a[n - i + 1]);
  for (long long i = 1; i <= n; i++)
    if (a[i] == 0)
      temp[i][i][0] = 1, temp[i][i][1] = 1;
    else
      temp[i][i][1] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      if (a[j] == 0)
        temp[i][j][0] = temp[i][j - 1][0] + 1,
        temp[i][j][1] = max(temp[i][j - 1][1], temp[i][j - 1][0] + 1);
      else
        temp[i][j][0] = temp[i][j - 1][0],
        temp[i][j][1] = max(temp[i][j - 1][1], temp[i][j - 1][0]) + 1;
    }
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = i; j <= n; j++) dp[i][j] = temp[i][j][1];
  for (long long l = 1; l <= n; l++) {
    for (long long r = l + 1; r <= n; r++) {
      long long val = 0;
      val += cn[n][1] - cn[r][1];
      val += cn[l - 1][0];
      val += temp[n + 1 - r][n + 1 - l][1];
      ans = max(ans, val);
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
}
