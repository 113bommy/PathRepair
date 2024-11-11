#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
const long long infl = 2e18;
const long long infi = 2e9;
const long long mod = 1e9 + 7;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk = clock();
long long rng(long long lim) {
  uniform_int_distribution<long long> uid(0, lim);
  return uid(rang);
}
long long a[500005];
vector<long long> gra[500005];
long long dp[19][500005];
void dfs(long long fr, long long at) {
  dp[0][at] = fr;
  for (long long i : gra[at])
    if (i != fr) dfs(at, i);
}
void solve() {
  long long n, u, v;
  cin >> n;
  long long rt = 1;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < a[rt]) rt = i;
  }
  for (long long i = 1; i < n; i++) {
    cin >> u >> v;
    gra[u].push_back(v);
    gra[v].push_back(u);
  }
  dfs(rt, rt);
  for (long long i = 1; i < 19; i++)
    for (long long j = 1; j <= n; j++) dp[i][j] = dp[i - 1][dp[i - 1][j]];
  long long ans = 0;
  for (long long i = 1; i <= n; i++)
    if (i != rt) {
      long long mi = infi;
      for (long long j = 0; j < 19; j++) mi = min(mi, (j + 1) * a[dp[j][i]]);
      ans += a[i] + mi;
    }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(time(0));
  long long t = 1;
  while (t--) solve();
  return 0;
}
