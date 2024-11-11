#include <bits/stdc++.h>
using namespace std;
const int sz = 100005;
int n, c;
vector<int> g[sz];
bool in[sz], go[sz];
vector<int> ans;
void dfs(int node, int l, bool of, bool ev, int dad) {
  if (go[node] != in[node]) {
    if ((l % 2 == 0 && !ev) || (l % 2 == 1 && !of)) {
      c++;
      ans.push_back(node);
    }
    in[node] = go[node];
    if (l % 2 == 0)
      ev = 1;
    else
      of = 1;
  } else {
    if (l % 2 == 1 && of) {
      of = 0;
      ans.push_back(node);
      c++;
    } else if (l % 2 == 0 && ev) {
      ev = 0;
      ans.push_back(node);
      c++;
    }
  }
  for (int i = 0; i < g[node].size(); i++) {
    int child = g[node][i];
    if (child == dad) continue;
    dfs(child, l + 1, of, ev, node);
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) cin >> in[i];
  for (int i = 1; i <= n; i++) cin >> go[i];
  dfs(1, 1, 0, 0, -1);
  cout << c << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  return 0;
}
