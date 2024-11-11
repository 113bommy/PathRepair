#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
bool ispoweroftwo(long long n) { return n & (!(n & (n - 1))); }
long long mod = 1000000007;
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, -1, 0, 1};
bool test = 0;
const long long inf = 1e18;
const long long N = 1e5 + 5;
long long cache[N][4][4];
long long k, n;
long long color[N][3];
vector<long long> adj[N];
long long dp(long long u, long long f = 3, long long f1 = 3, long long p = -1) {
  long long &ans = cache[u][f][f1];
  if (ans != -1) return ans;
  long long kid1 = -1, kid2 = -1;
  for (auto it : adj[u]) {
    if (it == p) continue;
    if (kid1 == -1)
      kid1 = it;
    else
      kid2 = it;
  }
  if (kid1 == -1) return ans = 0;
  if (kid2 != -1) {
    vector<long long> c1, c2, c3;
    for (long long i = 0; i < 3; ++i) {
      if (i == f) continue;
      c1.emplace_back(color[kid1][i] + dp(kid1, i, f, u));
      c3.emplace_back(i);
    }
    for (long long i = 0; i < 3; ++i) {
      if (i == f) continue;
      c2.emplace_back(color[kid2][i] + dp(kid2, i, f, u));
    }
    ans = min(c1[0] + c2[1], c1[1] + c2[0]);
    return ans;
  }
  ans = inf;
  for (long long i = 0; i < 3; ++i) {
    if (i == f or i == f1) continue;
    ans = min(ans, color[kid1][i] + dp(kid1, i, f, u));
  }
  return ans;
}
vector<long long> col(N);
void path(long long u, long long f, long long f1 = 3, long long p = -1) {
  long long &ans = cache[u][f][f1];
  long long kid1 = -1, kid2 = -1;
  for (auto it : adj[u]) {
    if (it == p) continue;
    if (kid1 == -1)
      kid1 = it;
    else
      kid2 = it;
  }
  if (kid1 == -1) return;
  if (kid2 != -1) {
    vector<long long> c1, c2, c3;
    for (long long i = 0; i < 3; ++i) {
      if (i == f) continue;
      c1.emplace_back(color[kid1][i] + cache[kid1][i][f]);
      c3.emplace_back(i);
    }
    for (long long i = 0; i < 3; ++i) {
      if (i == f) continue;
      c2.emplace_back(color[kid2][i] + cache[kid2][i][f]);
    }
    if (ans != c1[0] + c2[1]) swap(kid1, kid2);
    col[kid1] = c3[0] + 1;
    col[kid2] = c3[1] + 1;
    path(kid1, c3[0], f, u);
    path(kid2, c3[1], f, u);
    return;
  }
  for (long long i = 0; i < 3; ++i) {
    if (i == f or i == f1) continue;
    if (ans == color[kid1][i] + cache[kid1][i][f]) {
      col[kid1] = i + 1;
      path(kid1, i, f, u);
    }
  }
}
void solve(long long tc = 0) {
  memset(cache, -1, sizeof(cache));
  cin >> n;
  for (long long i = 0; i < 3; ++i)
    for (long long j = 1; j <= n; ++j) cin >> color[j][i];
  for (long long i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    adj[x].emplace_back(y);
    adj[y].emplace_back(x);
  }
  for (long long i = 1; i <= n; ++i) {
    if (adj[i].size() >= 3) {
      cout << "-1\n";
      return;
    }
  }
  adj[0].emplace_back(1);
  long long ans = dp(0, 3);
  cout << ans << "\n";
  path(0, 3);
  for (long long i = 1; i <= n; ++i) cout << col[i] << " ";
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  if (test) cin >> t;
  for (long long i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}
