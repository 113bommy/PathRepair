#include <bits/stdc++.h>
using namespace std;
const long long N = 105;
const long long mod = 1e9 + 7;
long long dp[N][N], Left[N][N], Right[N][N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, 0, sizeof(dp));
  long long n, m;
  cin >> n >> m;
  for (long long row = 1; row <= n; row++) {
    long long k;
    cin >> k;
    while (k--) {
      long long l, r;
      cin >> l >> r;
      for (long long x = l; x <= r; x++) {
        Left[row][x] = l;
        Right[row][x] = r;
      }
    }
  }
  for (long long l = 1; l <= m; l++) {
    for (long long r = l; r <= m; r++) {
      for (long long k = l; k <= r; k++) {
        long long amt = 0;
        for (long long y = 1; y <= n; y++) {
          if (Left[y][k] >= l && Right[y][k] <= r) amt++;
        }
        dp[l][r] = max(dp[l][k - 1] + dp[k + 1][r] + amt * amt, dp[l][r]);
      }
    }
  }
  cout << dp[1][m];
}
