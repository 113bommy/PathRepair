#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int n, x, y;
bool change[MAX], visited[MAX];
vector<int> adj[MAX], ans;
void dfs(int u, int c1, int c2, bool ok1, bool ok2) {
  visited[u] = true;
  if ((c1 && ok1) || (c2 && ok2)) {
    change[u] = !change[u];
    if (change[u]) {
      if (ok1 && c1)
        ok1 = false;
      else
        ok2 = false;
      change[u] = false;
      ans.push_back(u);
    }
  } else if (change[u]) {
    if (!ok1)
      c1 = 1, ok1 = true;
    else
      c2 = 1, ok2 = true;
    change[u] = false;
    ans.push_back(u);
  }
  for (const auto &v : adj[u])
    if (!visited[v]) dfs(v, (c1 + 1) % 2, (c2 + 1) % 2, ok1, ok2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) cin >> change[i];
  for (int i = 1; i <= n; i++) {
    cin >> x;
    change[i] = !(x == change[i]);
  }
  dfs(1, 0, 0, 0, 0);
  cout << ans.size() << "\n";
  for (const auto &v : ans) cout << v << "\n";
  return 0;
}
