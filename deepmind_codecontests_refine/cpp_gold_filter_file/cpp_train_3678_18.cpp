#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
vector<long long> adj[N];
bool vis[N];
long long n, m, k;
long long dfs(long long u) {
  if (vis[u]) return 0;
  vis[u] = true;
  long long ret = 1;
  for (auto v : adj[u]) ret += dfs(v);
  return ret;
}
long long fexp(long long a, long long b) {
  long long ans = 1;
  while (b)
    if (b & 1)
      ans = (ans * a) % k, b--;
    else
      a = (a * a) % k, b /= 2;
  return ans;
}
int main() {
  cin.tie(0), ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<long long> v;
  for (long long i = 1; i <= n; i++) {
    long long amt = dfs(i);
    if (amt > 0) v.push_back(amt);
  }
  if (v.size() == 1) return cout << 1 % k << endl, 0;
  long long ans = fexp(n, v.size() - 2);
  for (auto x : v) ans = (ans * x) % k;
  cout << ans << endl;
}
