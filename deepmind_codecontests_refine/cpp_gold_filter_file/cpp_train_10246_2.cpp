#include <bits/stdc++.h>
using namespace std;
long double PI = 3.14159265358979323846;
int modo = 1e9 + 7;
const long long inf = 1e13;
const long long ms = (1e5) + 5;
vector<pair<int, int>> vv[ms];
bool vis[ms] = {false};
set<int> ss;
int dfs(int node, int t) {
  vis[node] = true;
  int ff = 1;
  for (auto i : vv[node]) {
    if (!vis[i.first]) {
      int pp = dfs(i.first, i.second);
      if (pp) ff = 0;
    }
  }
  if (t) {
    if (ff) {
      ss.insert(node);
      return 1;
    } else
      return 1;
  }
  return !ff;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  int i;
  int u;
  int v;
  int t;
  for (i = 1; i < n; i++) {
    cin >> u >> v >> t;
    t--;
    vv[u].push_back({v, t});
    vv[v].push_back({u, t});
  }
  dfs(1, 0);
  cout << ss.size() << endl;
  for (int ii : ss) cout << ii << " ";
  return 0;
}
