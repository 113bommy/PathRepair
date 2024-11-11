#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;
void setIO(string inoutname) {
  freopen((inoutname + ".in").c_str(), "r", stdin);
  freopen((inoutname + ".out").c_str(), "w", stdout);
}
vector<long long> g[100005];
long long n, m;
bool vis[100005];
bool ncik;
void dfs(long long u, long long par) {
  vis[u] = 1;
  for (long long s : g[u]) {
    if (s == par) continue;
    if (vis[s])
      ncik = 0;
    else
      dfs(s, u);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cerr.tie(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    ncik = 1;
    dfs(i, i);
    if (ncik) ans++;
  }
  cout << ans << '\n';
  return 0;
}
