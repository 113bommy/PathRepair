#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
vector<int> edges[300005];
vector<int> ice[300005];
int choice[300005];
void dfs(int cur, int top) {
  int nxt;
  vector<int> used;
  for (int i = 0; i < ice[cur].size(); ++i) {
    nxt = ice[cur][i];
    if (choice[nxt]) used.push_back(choice[nxt]);
  }
  sort(used.begin(), used.end());
  int idx = 0, val = 1;
  for (int i = 0; i < ice[cur].size(); ++i) {
    nxt = ice[cur][i];
    if (!choice[nxt]) {
      while (idx < used.size() && val == used[idx]) ++val, ++idx;
      choice[nxt] = val++;
    }
  }
  for (int i = 0; i < edges[cur].size(); ++i) {
    nxt = edges[cur][i];
    if (nxt == top) continue;
    dfs(nxt, cur);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, t, s;
  int u, v;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i) {
      cin >> s;
      while (s--) {
        cin >> t;
        ice[i].push_back(t);
      }
      sort(ice[i].begin(), ice[i].end());
    }
    for (int i = 0; i < n - 1; ++i) {
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    memset(choice, 0, sizeof(choice));
    dfs(1, 0);
    int mx = 1;
    for (int i = 1; i <= m; ++i) mx = max(mx, choice[i]);
    cout << mx << "\n";
    for (int i = 1; i <= m; ++i) cout << max(choice[i], 1) << " ";
    cout << "\n";
    for (int i = 1; i <= n; ++i) edges[i].clear();
    for (int i = 1; i <= n; ++i) ice[i].clear();
  }
  return 0;
}
