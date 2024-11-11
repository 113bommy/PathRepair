#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const long long maxn = 2009;
long long dp[maxn][maxn];
long long sz = 0;
struct line {
  long long k, b;
};
line kb[maxn];
long long intersect(line a, line b) {
  if (a.k - b.k == 0) return 1e12;
  return (b.b - a.b) / (a.k - b.k);
}
void add_line(line a) {
  while (sz > 1) {
    line b1, c;
    b1 = kb[sz - 1];
    c = kb[sz - 2];
    if (intersect(a, b1) > intersect(b1, c)) break;
    sz--;
  }
  kb[sz] = a;
  sz++;
}
bool cmp(line x, line y) { return x.k < y.k; }
signed main() {
  long long n, m, q;
  cin >> n >> m >> q;
  vector<vector<pair<long long, long long>>> a(n);
  vector<pair<pair<long long, long long>, long long>> e(m * 2);
  for (long long i = 0; i < m; ++i) {
    long long v, u, w;
    cin >> v >> u >> w;
    v--;
    u--;
    e[i] = {{v, u}, w};
    e[i + m] = {{u, v}, w};
    a[v].push_back({u, w});
    a[u].push_back({v, w});
  }
  for (long long i = 0; i < maxn; ++i)
    for (long long v = 0; v < maxn; ++v) dp[i][v] = -1e12;
  long long ans = 0;
  dp[0][0] = 0;
  for (long long i = 1; i < maxn; ++i) {
    for (long long v = 0; v < n; ++v)
      for (auto u : a[v])
        dp[i][u.first] = max(dp[i - 1][v] + u.second, dp[i][u.first]);
  }
  if (q < maxn) {
    for (long long i = 1; i <= q; ++i) {
      long long ans1 = 0;
      for (long long v = 0; v < n; ++v) ans1 = max(ans1, dp[i][v]);
      ans += ans1;
      ans %= mod;
    }
    cout << ans;
    return 0;
  }
  for (long long i = 1; i < maxn; ++i) {
    long long ans1 = 0;
    for (long long v = 0; v < n; ++v) ans1 = max(ans1, dp[i][v]);
    ans += ans1;
    ans %= mod;
  }
  vector<line> l;
  for (long long i = 0; i < m * 2; ++i)
    if (dp[n][e[i].first.first] >= 0)
      l.push_back({e[i].second, dp[n][e[i].first.first] - n * e[i].second});
  sort(l.begin(), l.end(), cmp);
  vector<line> l2;
  l2.push_back(l[0]);
  for (long long i = 1; i < l.size(); ++i) {
    if (l[i].k != l2.back().k)
      l2.push_back(l[i]);
    else
      l2.back().b = max(l[i].b, l2.back().b);
  }
  for (long long i = 0; i < l2.size(); ++i) add_line(l2[i]);
  vector<long long> p;
  for (long long i = 1; i < sz; ++i) {
    p.push_back(intersect(kb[i - 1], kb[i]));
  }
  p.push_back(1e12);
  long long cur = maxn;
  long long i = 0;
  while (cur <= q) {
    while (p[i] < cur) i++;
    long long t = min(p[i], q);
    long long cnt = (t - cur + 1) % mod;
    long long k1 = (kb[i].k + mod) % mod, b1 = (kb[i].b + mod) % mod;
    ans +=
        b1 * cnt % mod + ((cnt * (cur + cur + cnt - 1) / 2) % mod * k1) % mod;
    ans %= mod;
    cur = t + 1;
  }
  cout << ans;
  return 0;
}
