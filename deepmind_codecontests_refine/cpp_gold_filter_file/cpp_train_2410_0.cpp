#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long M = 1e9 + 7;
vector<long long> ans;
vector<long long> col(N, -1);
vector<long long> adj[N];
vector<long long> vis(N, -1);
pair<long long, long long> dfs(long long src) {
  vis[src] = 1;
  pair<long long, long long> p = {1, 0};
  p.second = col[src];
  for (long long child : adj[src])
    if (vis[child] == -1) {
      pair<long long, long long> p2 = dfs(child);
      p.first += p2.first, p.second += p2.second;
    }
  if (p.first == p.second) ans.push_back(src);
  p = {1, 0};
  p.second = col[src];
  return p;
}
int32_t main() {
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, v, c, root;
  cin >> n;
  for (long long u = 1; u <= n; u++) {
    cin >> v >> c;
    if (v != -1)
      adj[u].push_back(v), adj[v].push_back(u), col[u] = c;
    else
      root = u, col[u] = c;
  }
  pair<long long, long long> p = dfs(root);
  sort(ans.begin(), ans.end());
  if (ans.size() == 0)
    cout << "-1" << endl;
  else
    ;
  for (auto x : ans) cout << x << " ";
  cout << "\n";
  ;
}
