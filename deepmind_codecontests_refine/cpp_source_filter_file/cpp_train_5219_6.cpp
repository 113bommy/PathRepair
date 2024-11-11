#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 5, MOD = 998244353;
vector<long long> g[maxn];
long long countt[3], np = 0;
long long pow2[maxn];
long long col[maxn];
long long mul(long long a, long long b) {
  a %= MOD, b %= MOD;
  return ((a * b) % MOD + MOD) % MOD;
}
long long add(long long a, long long b) { return (a + b + MOD) % MOD; }
void clear(long long n) {
  for (long long i = 0; i < n; ++i) {
    g[i].clear();
    col[i] = 0;
  }
  memset(countt, 0, sizeof countt);
  np = 0;
}
void dfs(long long v, long long c) {
  col[v] = c;
  countt[c]++;
  long long nxt = 3 - c;
  for (auto adj : g[v]) {
    if (!col[adj]) {
      dfs(adj, nxt);
    } else if (col[adj] == col[v]) {
      np = 1;
      return;
    }
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  clear(n);
  for (long long i = 1; i <= m; ++i) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long ans = 1;
  for (long long i = 1; i <= n; ++i) {
    if (!col[i]) {
      dfs(i, 1);
      if (np) {
        cout << 0;
        return;
      }
      ans = mul(ans, add(pow2[countt[1]], pow2[countt[2]]));
      countt[1] = countt[2] = 0;
    }
  }
  cout << ans;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  pow2[0] = 1;
  for (long long i = 1; i < maxn; ++i) {
    pow2[i] = mul(pow2[i - 1], 2);
  }
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
