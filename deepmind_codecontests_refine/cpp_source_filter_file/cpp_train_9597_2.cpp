#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
long long power(long long a, long long b, long long m = mod) {
  long long x = 1;
  while (b) {
    if (b & 1) {
      x = 1ll * x * a % m;
    }
    a = 1ll * a * a % m;
    b /= 2;
  }
  return x;
}
const int N = 2e6 + 9;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n + 2, vector<char>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  if (n == 1 && m == 1) {
    cout << "1\n";
    return 0;
  }
  vector<vector<long long>> r(n + 2, vector<long long>(m + 2)),
      d(n + 2, vector<long long>(m + 2)),
      sum_r(n + 3, vector<long long>(m + 3)),
      sum_d(n + 3, vector<long long>(m + 3)),
      rocks_row(n + 3, vector<long long>(m + 3)),
      rocks_col(n + 3, vector<long long>(m + 3));
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (i == n && j == m && a[i][j] == '.') {
        r[i][j] = d[i][j] = 1;
      } else {
        r[i][j] =
            (sum_d[i][j + 1] - sum_d[i][m + 1 - rocks_row[i][j + 1]] + mod) %
            mod;
        d[i][j] =
            (sum_r[i + 1][j] - sum_r[n + 1 - rocks_col[i + 1][j]][j] + mod) %
            mod;
      }
      sum_d[i][j] = (d[i][j] + sum_d[i][j + 1]) % mod;
      sum_r[i][j] = (r[i][j] + sum_r[i + 1][j]) % mod;
      rocks_row[i][j] = (rocks_row[i][j + 1] + a[i][j] == 'R') % mod;
      rocks_col[i][j] = (rocks_col[i + 1][j] + a[i][j] == 'R') % mod;
    }
  }
  cout << (r[1][1] + d[1][1]) % mod << "\n";
  return 0;
}
