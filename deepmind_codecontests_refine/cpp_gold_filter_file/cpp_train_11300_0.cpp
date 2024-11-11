#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> adj;
vector<long long> visited;
long long ans = 0;
long long power(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  if (y % 2)
    return x * power(x, y / 2) * power(x, y / 2);
  else
    return power(x, y / 2) * power(x, y / 2);
}
long long dfs(long long s, long long d) {
  visited[s] = 1;
  if (s != 1 && adj[s].size() == 1) {
    return d;
  }
  vector<long long> de;
  for (long long i = 0; i < adj[s].size(); i++) {
    if (visited[adj[s][i]] == 0) {
      long long x = dfs(adj[s][i], d + 1);
      de.push_back(x);
    }
  }
  sort(de.begin(), de.end());
  if (s == 1) {
    if (de.size() > 1)
      return de[de.size() - 1] + de[de.size() - 2];
    else
      return de[0];
  }
  if (de.size() > 1)
    ans = max(ans, de[de.size() - 1] + de[de.size() - 2] - 2 * d);
  return de[de.size() - 1];
}
void solve() {
  long long n, x, y, m;
  cin >> n >> m;
  adj.resize(n + 1);
  visited.resize(n + 1);
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (long long i = 0; i < n + 1; i++) visited[i] = 0;
  long long v = dfs(1, 0);
  ans = max(ans, v);
  cout << ans << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
