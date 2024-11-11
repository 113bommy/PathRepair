#include <bits/stdc++.h>
using namespace std;
vector<int> g[100000];
int ok[100000], tot, vis[100000];
int n, m, t;
vector<int> ans;
void f(int x, int pre) {
  vis[x] = 1;
  ans.push_back(x);
  ok[x] ^= 1;
  for (int i = 0; i < g[x].size(); i++) {
    int t = g[x][i];
    if (vis[t]) continue;
    f(t, x);
    ans.push_back(x);
    ok[x] ^= 1;
  }
  if (ok[x] && x != t) {
    ans.push_back(pre);
    ok[pre] ^= 1;
    ans.push_back(x);
    ok[x] ^= 1;
  }
}
bool check() {
  if (!tot) return true;
  int s = -1;
  for (int i = 0; i < n; i++)
    if (ok[i]) {
      s = i;
      break;
    }
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < g[x].size(); i++) {
      if (!vis[g[x][i]]) vis[g[x][i]] = 1, q.push(g[x][i]);
    }
  }
  for (int i = 0; i < n; i++)
    if (ok[i] && !vis[i]) return false;
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) cin >> ok[i], tot += ok[i];
  if (!check()) {
    cout << -1 << endl;
    return 0;
  }
  t = -1;
  for (int i = 0; i < n; i++)
    if (ok[i]) t = i;
  if (t == -1) {
    cout << 0 << endl;
    return 0;
  }
  memset(vis, 0, sizeof(vis));
  f(t, -1);
  cout << ans.size() - ok[t] << endl;
  for (int i = ok[t]; i < ans.size(); i++) cout << ans[i] + 1 << " ";
  cout << endl;
}
