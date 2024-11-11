#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n, k, dp[N], sum, pos, s1, s2, deep[N], mndp[N], ans, ss, ss1;
vector<pair<long long, long long> > g[N];
void dfs(long long x, long long p) {
  dp[x] = 0;
  for (long long i = 0; i < g[x].size(); ++i) {
    long long y = g[x][i].first;
    if (y == p) continue;
    dfs(y, x);
    dp[x] = max(dp[x], dp[y] + g[x][i].second);
  }
}
void get_ans(long long x, long long p, long long s) {
  if (max(dp[x], s) <= sum) {
    sum = max(dp[x], s);
    pos = x;
  }
  vector<long long> a(g[x].size(), 0), b(g[x].size(), 0);
  for (long long i = 0; i < g[x].size(); ++i) {
    long long y = g[x][i].first;
    if (y != p)
      a[i] = b[i] = dp[y] + g[x][i].second;
    else
      a[i] = b[i] = 0;
    if (i > 0) a[i] = max(a[i], a[i - 1]);
  }
  for (long long i = (long long)b.size() - 2; i >= 0; --i) {
    b[i] = max(b[i], b[i + 1]);
  }
  for (long long i = 0; i < g[x].size(); ++i) {
    long long y = g[x][i].first;
    if (y == p) continue;
    long long mx = 0;
    if (i > 0) mx = max(mx, a[i - 1]);
    if (i + 1 < b.size()) mx = max(mx, b[i + 1]);
    get_ans(y, x, max(s, mx) + g[x][i].second);
  }
}
void dfs1(long long x, long long p, long long s) {
  deep[x] = deep[p] + 1;
  mndp[deep[x]] = min(mndp[deep[x]], max(s, dp[x]));
  ans = min(ans, max(mndp[deep[x]], ss1));
  vector<long long> a(g[x].size(), 0), b(g[x].size(), 0);
  for (long long i = 0; i < g[x].size(); ++i) {
    long long y = g[x][i].first;
    if (y != p)
      a[i] = b[i] = dp[y] + g[x][i].second;
    else
      a[i] = b[i] = 0;
    if (i > 0) a[i] = max(a[i], a[i - 1]);
  }
  for (long long i = (long long)b.size() - 2; i >= 0; --i) {
    b[i] = max(b[i], b[i + 1]);
  }
  for (long long i = 0; i < g[x].size(); ++i) {
    long long y = g[x][i].first;
    if (y == p) continue;
    long long mx = 0;
    if (i > 0) mx = max(mx, a[i - 1]);
    if (i + 1 < b.size()) mx = max(mx, b[i + 1]);
    dfs1(y, x, max(mx, s));
  }
}
void dfs2(long long x, long long p, long long s) {
  deep[x] = deep[p] + 1;
  ans = min(ans, max(max(s, dp[x]), ss1));
  if (k - deep[x] - 1 > 0) {
    ans = min(ans, max(mndp[k - deep[x] - 1], max(s, dp[x])));
  }
  vector<long long> a(g[x].size(), 0), b(g[x].size(), 0);
  for (long long i = 0; i < g[x].size(); ++i) {
    long long y = g[x][i].first;
    if (y != p)
      a[i] = b[i] = dp[y] + g[x][i].second;
    else
      a[i] = b[i] = 0;
    if (i > 0) a[i] = max(a[i], a[i - 1]);
  }
  for (long long i = (long long)b.size() - 2; i >= 0; --i) {
    b[i] = max(b[i], b[i + 1]);
  }
  for (long long i = 0; i < g[x].size(); ++i) {
    long long y = g[x][i].first;
    if (y == p) continue;
    long long mx = 0;
    if (i > 0) mx = max(mx, a[i - 1]);
    if (i + 1 < b.size()) mx = max(mx, b[i + 1]);
    dfs2(y, x, max(mx, s));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 0; i <= n; ++i) {
    mndp[i] = 1e18;
  }
  if (n == 1) return cout << 0, 0;
  if (n == 2) {
    long long x, y, z;
    cin >> x >> y >> z;
    if (k == 2) z = 0;
    cout << z;
    return 0;
  }
  for (long long i = 1; i < n; ++i) {
    long long x, y, z;
    cin >> x >> y >> z;
    g[x].push_back(make_pair(y, z));
    g[y].push_back(make_pair(x, z));
  }
  dfs(1, 0);
  sum = 1e18;
  pos = 0;
  get_ans(1, 0, 0);
  if (k == 1) return cout << sum, 0;
  dfs(pos, 0);
  vector<pair<long long, long long> > a(g[pos].size());
  for (long long i = 0; i < g[pos].size(); ++i) {
    a[i] = make_pair(dp[g[pos][i].first] + g[pos][i].second, g[pos][i].first);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  long long s = 0;
  if (a.size() > 2)
    ss = a[2].first;
  else
    ss = 0;
  s1 = a[0].second;
  s2 = a[1].second;
  mndp[0] = a[0].first;
  deep[pos] = 0;
  ans = sum;
  ss1 = a[1].first;
  dfs1(s1, pos, ss);
  for (int i = 1; i <= n; ++i) {
    mndp[i] = min(mndp[i], mndp[i - 1]);
  }
  ss1 = a[0].first;
  dfs2(s2, pos, ss);
  cout << ans;
}
