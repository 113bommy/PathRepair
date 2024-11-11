#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[1000005];
long long vis[1000005];
vector<long long int> a[1000005];
vector<long long int> v[1000005];
long long q[1000005];
long long n, k, m;
long long c = 1;
void dfs(long long i, long long p) {
  if (vis[i]) return;
  vis[i] = c;
  v[p].push_back(i);
  for (auto x : adj[i]) {
    dfs(x, p);
  }
}
void solve() {
  cin >> n >> k;
  for (long long i = 1; i <= k; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cin >> m;
  for (long long i = 1; i <= m; i++) {
    long long x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  long long z = 0;
  for (long long i = 1; i <= n; i++) {
    dfs(i, i);
    for (auto x : v[i]) {
      for (auto y : a[x]) {
        if (vis[y] == c) {
          q[i] = -1;
          break;
        }
      }
      if (q[i] == -1) {
        break;
      }
    }
    c++;
  }
  long long ans = -1;
  for (long long i = 1; i <= n; i++) {
    if (q[i] != -1 && v[i].size() > 0) {
      long long sz = v[i].size();
      ans = max(ans, sz);
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) solve();
}
