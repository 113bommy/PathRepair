#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(const vector<T> &a) {
  for (T x : a) cout << x << " ";
  cout << '\n';
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());
vector<long long> xx = {1, 0, -1, 0};
vector<long long> yy = {0, 1, 0, -1};
string dir = "LRUD";
const long long N = 5e5 + 50, oo = 2e15 + 500;
const long long mod = 1e9 + 7;
const long long M2 = 1000000093, x2 = 27162;
const long long M1 = 1000000087, x1 = 241;
const double eps = 1e-12, PI = 2 * acos(0.0);
long long n, m, k;
long long cnt = 0;
long long lg = 18;
vector<vector<long long> > g;
vector<vector<long long> > rg;
vector<long long> visit(N, 0);
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  string s;
  cin >> s;
  vector<vector<vector<long long> > > dp(
      n, vector<vector<long long> >(n, vector<long long>(2, oo)));
  for (long long l = 0; l + 1 < n; l++) {
    dp[l][l][s[l] - '0'] = 0;
  }
  for (long long len = 2; len <= n; len++) {
    for (long long l = 0; l + len - 1 < n; l++) {
      long long r = l + len - 1;
      if (s[l] == '1') {
        dp[l][r][0] = min(dp[l][r][0], 1 + dp[l + 1][r][1]);
        ;
        dp[l][r][1] = min(dp[l][r][1], dp[l + 1][r][0]);
        ;
      }
      if (s[l] == '0') {
        dp[l][r][1] = min(dp[l][r][1], 1 + dp[l + 1][r][0]);
        ;
        dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][1]);
        ;
      }
      long long fl = ((r - 1) & 1) == (l & 1);
      if (fl) {
        if (s[r] != s[l]) {
          dp[l][r][(s[l] - '0')] =
              min(dp[l][r][(s[l] - '0')], dp[l][r - 1][(s[l] - '0')]);
          ;
        } else {
          dp[l][r][(s[l] - '0')] =
              min(dp[l][r][(s[l] - '0')], 1 + dp[l][r - 1][(s[l] - '0')]);
          ;
        }
      } else {
        if (s[r] != s[l]) {
          dp[l][r][(s[l] - '0')] =
              min(dp[l][r][(s[l] - '0')], dp[l][r - 1][(s[l] - '0')] + 1);
          ;
        } else {
          dp[l][r][(s[l] - '0')] =
              min(dp[l][r][(s[l] - '0')], dp[l][r - 1][(s[l] - '0')]);
          ;
        }
      }
    }
  }
  long long ans = min(dp[0][n - 1][0], dp[0][n - 1][1]);
  ans >= oo ? cout << -1 : cout << ans;
}
