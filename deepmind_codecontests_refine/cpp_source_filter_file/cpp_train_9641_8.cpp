#include <bits/stdc++.h>
using namespace std;
const int N = 250;
const long long INF = 1e18, mod = 1e9 + 7;
int n, m;
bool a[N][N], b[N][N];
int dp[2][2][2][(1 << 15)];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x, a[i][j] = (x == 'x');
    }
  if (n > m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        b[j][n - 1 - i] = a[i][j];
      }
    }
    swap(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = b[i][j];
      }
    }
  }
  dp[0][0][0][0] = 1;
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        if (a[i][j]) {
          int newmask = mask;
          if ((mask >> i) & 1) newmask ^= (1 << i);
          dp[1][0][0][newmask] =
              (dp[1][0][0][newmask] + dp[0][0][0][mask]) % mod;
          dp[1][0][0][newmask] =
              (dp[1][0][0][newmask] + dp[0][0][1][mask]) % mod;
          dp[1][1][0][newmask] =
              (dp[1][1][0][newmask] + dp[0][1][0][mask]) % mod;
          dp[1][1][0][newmask] =
              (dp[1][1][0][newmask] + dp[0][1][1][mask]) % mod;
        } else {
          if (i > 0) {
            dp[1][0][1][mask] = (dp[1][0][1][mask] + dp[0][0][1][mask]) % mod;
            dp[1][1][1][mask] = (dp[1][1][1][mask] + dp[0][1][1][mask]) % mod;
          }
          if ((mask >> i) & 1) {
            dp[1][0][0][mask] = (dp[1][0][0][mask] + dp[0][0][0][mask]) % mod;
            dp[1][1][0][mask] = (dp[1][1][0][mask] + dp[0][1][0][mask]) % mod;
          } else {
            dp[1][1][0][mask] = (dp[1][1][0][mask] + dp[0][0][0][mask]) % mod;
          }
          int newmask = mask | (1 << i);
          dp[1][0][1][newmask] =
              (dp[1][0][1][newmask] + dp[0][0][0][mask]) % mod;
          if (i > 0)
            dp[1][0][1][newmask] =
                (dp[1][0][1][newmask] + dp[0][0][1][mask]) % mod;
          dp[1][1][1][newmask] =
              (dp[1][1][1][newmask] + dp[0][1][0][mask]) % mod;
          if (i > 0)
            dp[1][1][1][newmask] =
                (dp[1][1][1][newmask] + dp[0][1][1][mask]) % mod;
        }
      }
      for (int mask = 0; mask < (1 << n); mask++) {
        dp[0][0][0][mask] = dp[1][0][0][mask], dp[1][0][0][mask] = 0;
        dp[0][0][1][mask] = dp[1][0][1][mask], dp[1][0][1][mask] = 0;
        dp[0][1][0][mask] = dp[1][1][0][mask], dp[1][1][0][mask] = 0;
        dp[0][1][1][mask] = dp[1][1][1][mask], dp[1][1][1][mask] = 0;
      }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
      dp[0][0][0][mask] = (dp[0][0][0][mask] + dp[0][0][1][mask]) % mod,
      dp[0][0][1][mask] = 0;
      dp[0][1][0][mask] = (dp[0][1][0][mask] + dp[0][1][1][mask]) % mod,
      dp[0][1][1][mask] = 0;
    }
  }
  int ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    ans = (ans + dp[0][0][0][mask]) % mod;
    ans = (ans + dp[0][0][1][mask]) % mod;
    ans = (ans + dp[0][1][0][mask]) % mod;
    ans = (ans + dp[0][1][1][mask]) % mod;
  }
  cout << ans;
}
