#include <bits/stdc++.h>
using namespace std;
const int N = 500110;
long long mod = 1e9 + 7;
long long fmod(long long b, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp & 1ll) res = (res * b) % mod;
    b = (b * b) % mod;
    exp /= 2ll;
  }
  return res;
}
int num = 0;
vector<int> adj[N];
int vis[N];
long long A[N], pw[N];
void dfs(int i) {
  num--;
  vis[i] = 1;
  for (int k : adj[i])
    if (!vis[k]) dfs(k);
}
map<long long, vector<pair<int, int> > > mp1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, n, i, j, m, k, u, v;
  cin >> n >> m >> k;
  int lim = 5e5 + 100;
  pw[0] = 1;
  for (i = 1; i <= lim; i++) pw[i] = (pw[i - 1] * 2ll) % mod;
  for (i = 1; i <= n; i++) cin >> A[i];
  for (i = 0; i < m; i++) {
    cin >> u >> v;
    mp1[A[u] ^ A[v]].push_back(make_pair(u, v));
  }
  long long ans = pw[k + n];
  for (auto ve : mp1) {
    for (auto j : ve.second) {
      adj[j.first].push_back(j.second);
      adj[j.second].push_back(j.first);
    }
    int comp = 0;
    num = n;
    for (auto j : ve.second) {
      if (!vis[j.first]) dfs(j.first), comp++;
      if (!vis[j.second]) dfs(j.second), comp++;
    }
    for (auto j : ve.second) {
      adj[j.second].clear();
      adj[j.first].clear();
      vis[j.first] = vis[j.second] = 0;
    }
    ans = (ans + mod - pw[n] + pw[num + comp]);
    if (ans >= mod) ans -= mod;
  }
  cout << ans << "\n";
  return 0;
}
