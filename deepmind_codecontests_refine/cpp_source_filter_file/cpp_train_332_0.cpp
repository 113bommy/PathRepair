#include <bits/stdc++.h>
using namespace std;
long long MOD = (1e9) + 7;
const long long N = 1e5 + 5;
const long long level = 25;
long long par[N][level], depth[N];
vector<long long> a[N];
void dfs(long long c, long long p) {
  depth[c] = depth[p] + 1;
  par[c][0] = p;
  for (long long i = 1; i < 40; i++) par[c][i] = par[par[c][i - 1]][i - 1];
  for (auto ne : a[c]) {
    if (ne == p) continue;
    dfs(ne, c);
  }
}
long long lca(long long u, long long v) {
  if (depth[v] < depth[u]) swap(u, v);
  long long diff = depth[v] - depth[u];
  for (long long i = 0; i < level; i++)
    if ((diff >> i) & 1) v = par[v][i];
  if (u == v) return u;
  for (long long i = level - 1; i >= 0; i--)
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  return par[u][0];
}
long long dist(long long u, long long v) {
  if (u == v) return 0;
  long long res = 0;
  if (depth[u] > depth[v]) swap(u, v);
  long long l = lca(u, v);
  return depth[u] + depth[v] - (2 * depth[l]);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc = 1;
  for (long long ti = 1; ti <= tc; ti++) {
    long long n;
    cin >> n;
    for (long long i = 1; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    dfs(1, 0);
    long long q;
    cin >> q;
    while (q--) {
      long long x, y, a, b, k;
      cin >> x >> y >> a >> b >> k;
      long long chk = dist(a, b);
      if (chk <= k && !((k - chk) % 2)) {
        cout << "YES" << endl;
        continue;
      }
      chk = dist(a, x) + dist(y, b) + 1;
      if (chk <= k && !((k - chk) % 2)) {
        cout << "YES" << endl;
        continue;
      }
      chk = dist(a, y) + dist(x, b) + 1;
      if (chk <= k && !((k - chk) % 2)) {
        cout << "YES" << endl;
        continue;
      }
      cout << "NO" << endl;
    }
  }
  return 0;
}
