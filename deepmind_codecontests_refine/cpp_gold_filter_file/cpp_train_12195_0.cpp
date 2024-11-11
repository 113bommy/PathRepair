#include <bits/stdc++.h>
using namespace std;
int n, root = 1;
int root_red = -1, root_blue = -1;
vector<vector<int>> adj;
vector<int> color, cnt_red, cnt_blue, par;
vector<bool> used;
void dfs1(int v) {
  used[v] = true;
  cnt_red[v] = (color[v] == 1 ? 1 : 0);
  cnt_blue[v] = (color[v] == 2 ? 1 : 0);
  for (auto u : adj[v])
    if (!used[u]) {
      par[u] = v;
      dfs1(u);
      cnt_red[v] += cnt_red[u];
      cnt_blue[v] += cnt_blue[u];
    }
}
void dfs2(int v) {
  used[v] = true;
  for (auto u : adj[v])
    if (!used[u]) dfs2(u);
  if (root_red == -1 && cnt_red[v] == cnt_red[root]) root_red = v;
  if (root_blue == -1 && cnt_blue[v] == cnt_blue[root]) root_blue = v;
}
int main() {
  cin >> n;
  color.resize(n + 1);
  cnt_red.resize(n + 1);
  cnt_blue.resize(n + 1);
  par.resize(n + 1);
  par[root] = -1;
  for (int i = 1; i <= n; i++) cin >> color[i];
  adj.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  used.assign(n + 1, false);
  dfs1(root);
  used.assign(n + 1, false);
  dfs2(root);
  set<int> s;
  vector<int> vr = {root_red, root_blue};
  for (auto cur : vr) {
    while (cur != -1) {
      if (cnt_red[cur] == 0 || cnt_blue[cur] == 0)
        s.insert(cur);
      else
        break;
      cur = par[cur];
    }
  }
  cout << s.size() << endl;
}
