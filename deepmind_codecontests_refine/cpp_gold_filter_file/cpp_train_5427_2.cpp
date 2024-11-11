#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 2;
const long long mod = 1000000007;
long long n, par[N], s[N], a[N], d[N];
vector<long long> adj[N], dep[N];
void dfs(long long u, long long p) {
  for (long long v : adj[u]) {
    if (v == p) continue;
    d[v] = d[u] + 1;
    dep[d[v]].push_back(v);
    dfs(v, u);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> par[i];
    adj[i].push_back(par[i]);
    adj[par[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  a[1] = s[1];
  dep[1].push_back(1), d[1] = 1;
  dfs(1, 1);
  for (long long dd = 2; dd <= n; dd += 2) {
    for (long long u : dep[dd]) {
      if (adj[u].size() == 1)
        a[u] = 0;
      else {
        long long mn = (1LL << 61);
        for (long long v : adj[u]) {
          if (v == par[u]) continue;
          mn = min(mn, s[v] - s[par[u]]);
        }
        if (mn < 0) {
          cout << -1;
          return 0;
        }
        a[u] = mn;
        for (long long v : adj[u]) {
          if (v == par[u]) continue;
          a[v] = s[v] - s[par[u]] - a[u];
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i];
  }
  cout << ans;
}
