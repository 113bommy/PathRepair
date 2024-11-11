#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
const long long infl = 2e18;
const int infi = 2e9;
const int mod = 1e9 + 7;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk = clock();
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim);
  return uid(rang);
}
int a[500005];
vector<int> gra[500005];
int dp[20][500005];
void dfs(int fr, int at) {
  dp[0][at] = fr;
  for (int i : gra[at])
    if (i != fr) dfs(at, i);
}
void solve() {
  int n, u, v;
  cin >> n;
  int rt = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < a[rt]) rt = i;
  }
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    gra[u].push_back(v);
    gra[v].push_back(u);
  }
  dfs(rt, rt);
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = dp[i - 1][dp[i - 1][j]];
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (i != rt) {
      long long mi = infl;
      for (int j = 0; j < 20; j++) mi = min(mi, (j + 1LL) * a[dp[j][i]]);
      ans += a[i] + mi;
    }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(time(0));
  int t = 1;
  while (t--) solve();
  return 0;
}
