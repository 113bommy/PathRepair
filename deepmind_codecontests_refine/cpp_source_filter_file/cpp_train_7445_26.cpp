#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
long long a[maxn], sz[maxn], res;
vector<long long> adj[maxn];
long long dfs(long long k, long long u = 1, long long par = 0) {
  sz[u] = 1;
  long long s = 1, mx1 = 0, mx2 = 0;
  for (long long v : adj[u])
    if (v != par) {
      long long t = dfs(k, v, u);
      if (t == sz[v])
        s += t;
      else {
        mx2 = max(mx2, t);
        if (mx1 < mx2) swap(mx1, mx2);
      }
      sz[u] += sz[v];
    }
  if (a[u] < k) return 0;
  res = max(res, s + mx1 + mx2);
  return s + mx1;
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 0, u, v; i < n - 1; i++)
    cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
  long long sv = min_element(a, a + n) - a;
  long long l = 1, r = 1e9;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    res = 0;
    dfs(mid, sv);
    if (res >= k)
      l = mid;
    else
      r = mid;
  }
  cout << l << '\n';
  return 0;
}
