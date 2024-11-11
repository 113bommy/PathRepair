#include <bits/stdc++.h>
using namespace std;
const long long N = 110, mod = 1e9 + 7;
long long p[N], pre[N][N][N], suf[N][N][N], ans[N][N][N], how[N][N][N];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  p[0] = p[1] = 2;
  for (long long i = 2; i < N; i++) p[i] = (p[i - 1] * p[i - 2]) % mod;
  long long n, t;
  string s;
  cin >> n >> t >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1') {
      ans[1][i][i] = suf[1][i][i] = pre[1][i][i] = how[1][i][i] = 1;
    } else {
      ans[1][i][i] = suf[0][i][i] = pre[0][i][i] = how[0][i][i] = 1;
    }
  }
  for (long long i = 2; i <= t; i++) {
    for (long long x = 0; x < n; x++) {
      for (long long y = x; y < n; y++) {
        how[i][x][y] =
            (how[i][x][y] + how[i - 1][x][y] + how[i - 2][x][y]) % mod;
        pre[i][x][y] =
            ((pre[i - 1][x][y] * p[i - 2]) % mod + pre[i - 2][x][y]) % mod;
        suf[i][x][y] =
            ((suf[i - 2][x][y] * p[i - 1]) % mod + suf[i - 1][x][y]) % mod;
        ans[i][x][y] = ((ans[i - 1][x][y] * p[i - 2]) % mod +
                        (ans[i - 2][x][y] * p[i - 1]) % mod) %
                       mod;
        for (long long j = x + 1; j <= y; j++) {
          how[i][x][y] =
              (how[i][x][y] + (how[i - 2][j][y] * how[i - 1][x][j - 1]) % mod) %
              mod;
          pre[i][x][y] =
              (pre[i][x][y] + (pre[i - 2][j][y] * how[i - 1][x][j - 1]) % mod) %
              mod;
          suf[i][x][y] =
              (suf[i][x][y] + (suf[i - 1][x][j - 1] * how[i - 2][j][y]) % mod) %
              mod;
          ans[i][x][y] =
              (ans[i][x][y] + (suf[i - 1][x][j - 1] * pre[i - 2][j][y]) % mod) %
              mod;
        }
      }
    }
  }
  cout << ans[t][0][n - 1] << '\n';
  return 0;
}
