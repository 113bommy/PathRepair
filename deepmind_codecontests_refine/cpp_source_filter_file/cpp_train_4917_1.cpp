#include <bits/stdc++.h>
using namespace std;
const long long N = 507;
long long a[N], dp[N], cut[N][N];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= (long long)n; ++i) cin >> a[i];
  for (long long i = 1; i <= (long long)n; ++i) cut[i][i] = i;
  for (long long len = 2; len <= n; ++len) {
    for (long long l = 1; l <= (long long)n - len + 1; ++l) {
      for (long long bnd = l; bnd < l + len - 1; ++bnd)
        if (cut[l][bnd] && cut[bnd + 1][l + len - 1] == cut[l][bnd])
          cut[l][l + len - 1] = cut[l][bnd] + 1;
    }
  }
  for (long long i = 1; i <= (long long)n; ++i) {
    dp[i] = dp[i - 1] + 1;
    for (long long bnd = 1; bnd <= i; ++bnd)
      if (cut[bnd][i]) dp[i] = min(dp[i], dp[bnd - 1] + 1);
  }
  cout << dp[n];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
