#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
int n, m, D, p[200005];
vector<int> adj[200005], req;
vector<pair<int, int> > ans;
void fk() {
  cout << "NO\n";
  exit(0);
}
int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
bool join(int x, int y) {
  if ((x = find(x)) == (y = find(y))) return 0;
  p[x] = y;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> D;
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v, --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (adj[0].size() < D) fk();
  iota(p, p + n, 0);
  for (int i = 1; i < n; ++i)
    for (int j : adj[i])
      if (j) join(i, j);
  for (int j : adj[0])
    if (join(0, j)) req.push_back(j);
  if (req.size() > D) fk();
  cout << "YES\n";
  iota(p, p + n, 0);
  for (int j : req) {
    join(0, j);
    ans.push_back(make_pair(0, j));
    --D;
  }
  for (int j : adj[0]) {
    if (!D) break;
    if (!join(0, j)) continue;
    ans.push_back(make_pair(0, j));
    --D;
  }
  for (int i = 1; i < n; ++i)
    for (int j : adj[i])
      if (j && join(i, j)) ans.push_back(make_pair(i, j));
  for (pair<int, int> a : ans)
    cout << a.first + 1 << " " << a.second + 1 << "\n";
  return 0;
}
