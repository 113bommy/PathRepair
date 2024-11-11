#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const long long mod = 1e9 + 7;
long long n, m, x, y;
vector<long long> G[47];
long long ans = 0, used[47], now, cnt = 0, cnt2 = 0;
long long par[47], dp[maxn], dp2[maxn];
void dfs1(long long Now) {
  used[Now] = 1;
  cnt++;
  for (long long i : G[Now]) {
    if (!used[i]) {
      par[i] = 1 - par[Now];
      dfs1(i);
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  if (n == 1) return cout << 2 << '\n', 0;
  for (long long i = 1; i <= m; i++) {
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  ans = (1ll << n);
  if (m == 0) ans -= (1ll << n);
  now = 1;
  for (long long i = 1; i <= n; i++) {
    if (!used[i]) {
      cnt2++;
      cnt = 0;
      dfs1(i);
      if (cnt == 1) now *= 2;
    }
  }
  ans += now * 2;
  ans -= (1ll << cnt2);
  long long ok = 1;
  for (long long i = 1; i <= n; i++)
    for (long long j : G[i])
      if (par[i] == par[j]) ok = 0;
  if (ok) ans += (1ll << cnt2);
  long long half = n / 2;
  vector<pair<long long, long long> > v;
  for (long long i = half + 1; i <= n; i++)
    for (long long j : G[i])
      if (j >= half + 1) v.push_back(make_pair(i, j));
  for (long long i = 0; i < (1ll << (n - half)); i++) {
    long long p = 1;
    for (pair<long long, long long> j : v)
      if ((i & (1 << (j.first - half - 1))) &&
          (i & (1 << (j.second - half - 1))))
        p = 0;
    if (p) dp[i] = 1;
  }
  for (long long j = 0; j < (n - half); j++)
    for (long long i = 0; i < (1ll << (n - half)); i++)
      if (i & (1ll << j)) dp[i] += dp[i ^ (1ll << j)];
  for (long long i = 1; i <= half; i++)
    for (long long j : G[i])
      if (j > half) dp2[1 << (i - 1)] |= (1 << (j - half - 1));
  for (long long i = 0; i < (1 << half); i++) {
    for (long long j = 0; j < half; j++)
      if ((1 << j) & i) dp2[i] |= dp2[1 << j];
  }
  v.clear();
  for (long long i = 1; i <= half; i++)
    for (long long j : G[i])
      if (j <= half) v.push_back(make_pair(i, j));
  for (long long i = 0; i < (1ll << half); i++) {
    long long p = 1;
    for (pair<long long, long long> j : v)
      if ((i & (1 << (j.first - 1))) && (i & (1 << (j.second - 1)))) p = 0;
    if (p) ans -= dp[dp2[i] ^ ((1 << (n - half)) - 1)] * 2;
  }
  cout << ans << '\n';
}
