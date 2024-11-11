#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(const vector<T> &a) {
  for (T x : a) cout << x << " ";
  cout << '\n';
}
const long long N = 2e5 + 50, oo = 1e9 + 500;
const long long mod = 1e9 + 9;
const long double eps = 1e-6, PI = 2 * acos(0.0);
long long n, m, k;
long long cnt = 0;
vector<long long> g[N];
vector<long long> visit(N, 0);
long long dp[100][100][101][2];
long long ans[100][100];
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  string s;
  cin >> s;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long l = 0; l <= n; l++) {
    for (long long r = 0; r <= n; r++) {
      for (long long c = 1; c <= n; c++) {
        for (long long x = 0; x < 2; x++) {
          dp[l][r][c][x] = -oo;
        }
      }
    }
  }
  for (long long len = 1; len <= n; len++) {
    for (long long l = 0; l + len - 1 < n; l++) {
      long long r = l + len - 1;
      for (long long c = 1; c <= len; c++) {
        for (long long x = 0; x < 2; x++) {
          for (long long md = l; md <= r; md++) {
            if (s[md] == (char)(x + '0')) {
              long long val = 0;
              if (c - 1)
                val += dp[md + 1][r][c - 1][x];
              else
                val += ans[md + 1][r];
              val += ans[l][md - 1];
              dp[l][r][c][x] = max(dp[l][r][c][x], val);
              ;
            }
          }
          ans[l][r] = max(ans[l][r], a[c - 1] + dp[l][r][c][x]);
          ;
        }
      }
    }
  }
  cout << ans[0][n - 1];
}
