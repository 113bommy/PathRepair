#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[100050];
long long s[100050], a[100050], p[100050];
void dfs(long long u, long long depth = 1) {
  long long mn = 1e9, val = s[p[u]];
  if (!depth) {
    for (auto v : adj[u]) {
      if (s[v] < val) {
        cout << -1;
        exit(0);
      }
      mn = min(s[v] - val, mn);
    }
    a[u] = (mn == 1e9 ? 0 : mn);
    for (auto v : adj[u]) a[v] = s[v] - val - mn;
  }
  for (auto v : adj[u]) dfs(v, 1 - depth);
}
signed main() {
  long long n;
  cin >> n;
  for (long long i = 2; i <= n; i++) {
    long long q;
    cin >> q;
    adj[q].push_back(i);
    p[i] = q;
  }
  for (long long i = 1; i <= n; i++) cin >> s[i];
  dfs(1);
  long long ans = s[1];
  for (long long i = 2; i <= n; i++) ans += a[i];
  cout << ans;
}
