#include <bits/stdc++.h>
using namespace std;
const long long dx[] = {0, 1, 0, -1};
const long long dy[] = {1, 0, -1, 0};
const long long inf = 2e9;
const long long mod = 998244353;
const long long N = 3e3 + 11;
const long long NMAX = 3e2 + 11;
const long long INF64 = 3e18 + 1;
const double eps = 1e-14;
const double PI = acos(-1);
long long n, dp[N][N], m;
char a[N], b[N];
long long ask(long long x) {
  cout << "? " << x + 1 << endl;
  long long y;
  cin >> y;
  return y;
}
void solve() {
  string s, t;
  cin >> s >> t;
  n = (long long)((s).size()), m = (long long)((t).size());
  for (long long i = 1; i <= n; i++) a[i] = s[i - 1];
  for (long long i = 1; i <= m; i++) b[i] = t[i - 1];
  for (long long i = 1; i <= m; i++) {
    if (b[i] == a[1]) {
      dp[i][i] = 1;
    }
  }
  for (long long i = m + 1; i <= n; i++) {
    dp[i][i] = 1;
  }
  for (long long i = 2; i <= n; i++) {
    for (long long L = 1; L + i - 2 <= n; L++) {
      long long R = L + i - 2;
      if (L > 1 && (L > m + 1 || b[L - 1] == a[i])) {
        dp[L - 1][R] += dp[L][R] % mod;
        dp[L - 1][R] %= mod;
      }
      if (R >= m || b[R + 1] == a[i]) {
        dp[L][R + 1] += dp[L][R] % mod;
        dp[L][R + 1] %= mod;
      }
    }
  }
  long long ans = 0;
  for (long long i = m; i <= n; i++) ans = (ans + dp[1][i]) % mod;
  cout << (2 * ans + mod) % mod << '\n';
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
}
