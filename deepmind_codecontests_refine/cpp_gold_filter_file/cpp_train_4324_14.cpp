#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int u, id;
  Edge(int _u, int _id) {
    u = _u;
    id = _id;
  }
};
vector<Edge> to[200005];
vector<int> ans[200005];
int skp[200005];
void dfs(int v, int p) {
  int s = 1;
  for (auto x : to[v]) {
    if (x.u == p) continue;
    s += (skp[v] == s);
    ans[s].push_back(x.id);
    skp[x.u] = s;
    s++;
    dfs(x.u, v);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int v, u;
    cin >> v >> u;
    to[v].push_back(Edge(u, i));
    to[u].push_back(Edge(v, i));
  }
  int root = 1;
  for (int i = 2; i <= n; i++)
    if (to[root].size() < to[i].size()) root = i;
  cout << to[root].size() << "\n";
  dfs(root, 0);
  for (int i = 1; i <= to[root].size(); i++) {
    cout << ans[i].size() << ' ';
    for (auto x : ans[i]) cout << x << ' ';
    cout << '\n';
  }
}
