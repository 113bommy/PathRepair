#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
void solve() {
  long long n, m, c0, d0;
  cin >> n >> m >> c0 >> d0;
  long long a[m + 4], b[m + 5], c[m + 5], d[m + 5];
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i] /= b[i];
  }
  c[0] = c0;
  long long dp[m + 4][n + 4];
  a[0] = 10000;
  memset(dp, 0, sizeof(dp));
  for (long long i = 0; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      for (long long k = 0; k <= a[i]; k++) {
        if (j - k * c[i] < 0) break;
        if (i == 0) {
          dp[i][j] = k * d0;
        } else {
          dp[i][j] = max(dp[i - 1][j - k * c[i]] + k * d[i], dp[i][j]);
        }
      }
    }
  }
  long long mx = -1;
  for (long long i = n; i >= 0; i--) {
    mx = max(mx, dp[m][i]);
  }
  cout << mx << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  solve();
  return 0;
}
