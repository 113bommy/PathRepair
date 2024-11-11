#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100;
long long par[N], vis[N], vis1[N];
vector<long long> adj[N], vec;
void dfs(long long cur, long long p, long long lvl) {
  vis[cur] = 1;
  par[cur] = p;
  for (auto x : adj[cur]) {
    if (vis[x]) continue;
    dfs(x, cur, lvl + 1);
  }
  if (lvl > 2) vec.push_back(cur);
}
signed main() {
  long long n;
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0, 0);
  long long res = 0;
  for (auto i : vec) {
    if (vis1[i] == 0) {
      res++;
      vis1[par[i]] = 1;
      for (auto j : adj[par[i]]) vis1[j] = 1;
    }
  }
  cout << res << endl;
}
