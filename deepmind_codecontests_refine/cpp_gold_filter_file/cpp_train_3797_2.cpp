#include <bits/stdc++.h>
using namespace std;
long long n, m, t;
long long a[55], b[55], dp1[55][55][55], dp2[55][55][55], dp[55][55];
vector<pair<long long, long long> > ve[105];
map<pair<long long, long long>, long long> ma;
signed main() {
  string s1, s2;
  cin >> s1 >> s2;
  n = s1.size(), m = s2.size();
  for (long long i = 1; i <= n; i++) {
    char x = s1[i - 1];
    a[i] = x - 'a';
  }
  for (long long i = 1; i <= m; i++) {
    char x = s2[i - 1];
    b[i] = x - 'a';
  }
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    string s;
    cin >> s;
    long long x, y, z;
    x = s[0] - 'a', y = s[s.size() - 2] - 'a', z = s[s.size() - 1] - 'a';
    ve[x].push_back(make_pair(y, z));
    ma[make_pair(y, z)] = x;
  }
  for (long long i = 1; i <= n; i++) dp1[i][i][a[i]] = 1;
  for (long long i = 1; i <= m; i++) dp2[i][i][b[i]] = 1;
  for (long long i = 1; i < n; i++) {
    long long x = a[i], y = a[i + 1];
    if (ma[make_pair(x, y)]) dp1[i][i + 1][ma[make_pair(x, y)]] = 1;
  }
  for (long long i = 1; i < m; i++) {
    long long x = b[i], y = b[i + 1];
    if (ma[make_pair(x, y)]) dp2[i][i + 1][ma[make_pair(x, y)]] = 1;
  }
  for (long long len = 2; len <= n; len++) {
    for (long long l = 1; l <= n - len + 1; l++) {
      long long r = l + len - 1;
      for (long long k = l; k <= r; k++) {
        for (long long i = 0; i < 26; i++) {
          for (long long j = 0; j < ve[i].size(); j++) {
            long long x = ve[i][j].first, y = ve[i][j].second;
            dp1[l][r][i] = dp1[l][r][i] | (dp1[l][k][x] & dp1[k + 1][r][y]);
          }
        }
      }
    }
  }
  for (long long len = 2; len <= m; len++) {
    for (long long l = 1; l <= m - len + 1; l++) {
      long long r = l + len - 1;
      for (long long k = l; k <= r; k++) {
        for (long long i = 0; i < 26; i++) {
          for (long long j = 0; j < ve[i].size(); j++) {
            long long x = ve[i][j].first, y = ve[i][j].second;
            dp2[l][r][i] = dp2[l][r][i] | (dp2[l][k][x] & dp2[k + 1][r][y]);
          }
        }
      }
    }
  }
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= m; j++) dp[i][j] = 200000000007;
  }
  dp[0][0] = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      for (long long ii = 1; ii <= i; ii++) {
        for (long long jj = 1; jj <= j; jj++) {
          for (long long k = 0; k <= 25; k++) {
            if (dp1[ii][i][k] == 1 && dp2[jj][j][k] == 1)
              dp[i][j] = min(dp[i][j], dp[ii - 1][jj - 1] + 1);
          }
        }
      }
    }
  }
  if (dp[n][m] == 200000000007)
    cout << -1 << endl;
  else
    cout << dp[n][m] << endl;
  return 0;
}
