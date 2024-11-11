#include <bits/stdc++.h>
using namespace std;
class graph {
 public:
  int v;
  vector<int> *adj;
  map<int, set<int>> bidirect;
  graph(int v) {
    this->v = v;
    adj = new vector<int>[v];
  }
  void dfshelper(int i, vector<bool> &vis) {
    vis[i] = true;
    for (int j = 0; j < adj[i].size(); j++) {
      cout << i + 1 << " " << adj[i][j] + 1 << endl;
      if (vis[adj[i][j]] == false) {
        dfshelper(adj[i][j], vis);
      }
    }
  }
  void dfs() {
    vector<bool> vis(v, false);
    for (int i = 0; i < v; i++) {
      if (!vis[i]) dfshelper(i, vis);
    }
  }
  bool topological(int v, vector<bool> &vis, vector<bool> &instack,
                   stack<int> &st) {
    vis[v] = true;
    instack[v] = true;
    bool ans = true;
    for (int i = 0; i < adj[v].size(); i++) {
      if (instack[adj[v][i]] == true)
        return false;
      else if (!vis[adj[v][i]]) {
        ans = topological(adj[v][i], vis, instack, st);
      }
    }
    instack[v] = false;
    st.push(v);
    return ans;
  }
  vector<int> Topo() {
    vector<bool> vis(v, false);
    vector<bool> instack(v, false);
    stack<int> ans;
    for (int i = 0; i < v; i++) {
      if (!vis[i]) {
        if (topological(i, vis, instack, ans) == false) {
          return {};
        }
      }
    }
    vector<int> a;
    while (!ans.empty()) {
      a.push_back(ans.top());
      ans.pop();
    }
    return a;
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  graph g(n);
  int t, o, in;
  for (int i = 0; i < m; i++) {
    cin >> t >> o >> in;
    o--;
    in--;
    if (t == 1) {
      g.adj[o].push_back(in);
    } else {
      g.bidirect[o].insert(in);
      g.bidirect[in].insert(o);
    }
  }
  vector<int> ans = g.Topo();
  if (ans.size() < n) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (auto j : g.bidirect[ans[i]]) {
      g.adj[ans[i]].push_back(j);
      g.bidirect[j].erase(ans[i]);
    }
  }
  g.dfs();
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
