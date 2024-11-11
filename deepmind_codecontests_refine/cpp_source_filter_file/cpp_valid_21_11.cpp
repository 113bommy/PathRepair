#include <bits/stdc++.h>
using namespace std;
long long y[200100], p[200100], dp[200100], n, m = 998244353;
vector<long long> x;
set<long long> st;
bool s[200100];
void yes(bool x) {
  if (x)
    cout << "YES\n";
  else
    cout << "NO\n";
}
void prepare() {
  p[0] = 0;
  p[1] = x[1] - y[1];
  for (long long i = 2; i <= n; i++) {
    long long l = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
    p[i] = (p[i - 1] + p[i - 1] - p[l - 1] + x[i] - y[i] + 2 * m) % m;
  }
}
long long rec(long long k) {
  if (k == 0) return 0;
  if (dp[k] != -1) return dp[k];
  long long ans = (x[k] - x[k - 1] + rec(k - 1) + m) % m;
  if (s[k]) ans = (ans + p[k] - p[k - 1] + m) % m;
  return dp[k] = ans;
}
void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> n;
  x.push_back(0);
  y[0] = 0;
  for (long long i = 1; i <= n; i++) {
    long long a;
    cin >> a >> y[i] >> s[i];
    x.push_back(a);
  }
  prepare();
  cout << rec(n) + 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
