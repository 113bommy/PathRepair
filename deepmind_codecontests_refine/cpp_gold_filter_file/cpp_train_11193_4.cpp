#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
vector<int> adj[500009];
vector<int> dp;
void dfs(int nd, int pr, int lvl) {
  if (adj[nd].size() == 1) {
    dp.push_back(lvl);
    return;
  }
  for (int i = 0; i < int(adj[nd].size()); i++) {
    int to = adj[nd][i];
    if (to == pr) continue;
    dfs(to, nd, lvl + 1);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  for (int i = 0; i < int(adj[1].size()); i++) {
    int to = adj[1][i];
    dfs(to, 1, 0);
    sort(dp.begin(), dp.end());
    int val = -1;
    for (__typeof((dp).begin()) it = (dp).begin(); it != (dp).end(); it++)
      val = max(*it, val + 1);
    umax(ans, val);
    dp.clear();
  }
  printf("%d\n", ans + 1);
  return 0;
}
