#include <bits/stdc++.h>
using namespace std;
const int MXN = 5e5 + 5, MXC = 1 << 20;
int n, p[MXN][2];
vector<pair<int, int> > adj[MXC];
bool vis[MXC];
vector<int> ans;
void dfs(int u) {
  vis[u] = 1;
  for (auto& p : adj[u])
    if (!vis[p.first]) dfs(p.first);
}
int build(int m) {
  for (int i = (0); i <= (m); ++i) adj[i].clear();
  int u, v;
  for (int i = (0); i < (n); ++i) {
    u = p[i][0] & m;
    v = p[i][1] & m;
    adj[u].emplace_back(v, i << 1);
    adj[v].emplace_back(u, i << 1 | 1);
  }
  return u;
}
bool valid(int b) {
  int m = (1 << b) - 1;
  memset((vis), 0, (1 << b) * sizeof(vis[0]));
  build(m);
  bool c = 0;
  for (int u = (0); u <= (m); ++u) {
    if (adj[u].size() & 1) return 0;
    if (!vis[u] && adj[u].size()) {
      if (!c)
        dfs(u), c = 1;
      else
        return 0;
    }
  }
  return 1;
}
void path(int b) {
  int m = (1 << b) - 1;
  memset((vis), 0, (n) * sizeof(vis[0]));
  stack<pair<int, int> > stk;
  stk.emplace(p[0][0] & m, -1);
  while (stk.size()) {
    int u = stk.top().first;
    if (adj[u].size()) {
      pair<int, int> e = adj[u].back();
      adj[u].pop_back();
      if (vis[e.second >> 1]) continue;
      vis[e.second >> 1] = 1;
      stk.push(e);
    } else {
      int p = stk.top().second;
      if (p != -1) {
        ans.push_back((p ^ 1) + 1);
        ans.push_back(p + 1);
      }
      stk.pop();
    }
  }
}
void solve() {
  cin >> n;
  for (int i = (0); i < (n); ++i) cin >> p[i][0] >> p[i][1];
  int b = 20;
  ans.reserve(2 * n);
  while (b && !valid(b)) --b;
  path(b);
  cout << b << '\n';
  for (auto& a : ans) cout << a << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
