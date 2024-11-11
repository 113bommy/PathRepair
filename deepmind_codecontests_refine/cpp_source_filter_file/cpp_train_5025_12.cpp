#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 1e5 + 2;
int T, n, a, b, da, db, d[N];
vector<int> g[N];
int bfs(int r) {
  queue<int> q;
  q.push(r);
  for (int i = (1); i <= (n); ++i) d[i] = -1;
  d[r] = 0;
  int ans = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans = u;
    for (int v : g[u])
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> n >> a >> b >> da >> db;
    for (int i = (1); i <= (n); ++i) g[i].clear();
    for (int i = (2); i <= (n); ++i) {
      int u, v;
      cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    int l = bfs(a);
    if (d[b] <= da || db <= 2 * da) {
      cout << "Alice\n";
      continue;
    }
    int longest = bfs(l);
    if (longest > 2 * da)
      cout << "Bob\n";
    else
      cout << "Alice\n";
  }
  return 0;
}
