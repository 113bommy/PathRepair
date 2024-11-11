#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2")
using namespace std;
const long long inf = 1e9;
void print(vector<long long>& a) {
  for (int x : a) cout << x << " ";
  cout << "\n";
}
void assign(vector<long long>& a, vector<long long>& p, vector<long long>& s) {
  p.assign((int)(a.size()), -inf);
  s.assign((int)(a.size()) + 1, -inf);
  for (int i = 1; i < (int)(a.size()); ++i) {
    p[i] = max(p[i - 1], a[i]);
  }
  for (int i = (int)(a.size()) - 1; i >= 0; --i) {
    s[i] = max(s[i + 1], a[i]);
  }
}
int main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<long long> > a(n + 1, vector<long long>(m + 1, 0)),
      prfs(n + 1, vector<long long>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      prfs[i][j] = prfs[i][j - 1] + a[i][j];
    }
  }
  vector<vector<long long> > dp(n + 1, vector<long long>(m + 1, -inf));
  for (int i = 0; i <= m; ++i) dp[0][i] = 0;
  vector<long long> sfx(m + 1, -inf), prf(m + 1, -inf);
  assign(dp[0], prf, sfx);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i % 2 == 0) {
        dp[i][j] = prfs[i][j] + sfx[j + 1];
      }
      if (i % 2 == 1) {
        dp[i][j] = prfs[i][j] + prf[j - 1];
      }
    }
    assign(dp[i], prf, sfx);
  }
  long long ans = 0;
  for (int i = 1; i <= m; ++i) ans = max(ans, dp[n][i]);
  cout << ans;
  return 0;
}
