#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[200001];
int cp, lv;
bool dfs(int x, int p) {
  int count = (int)adj[x].size() - (x != p);
  for (auto to : adj[x])
    if (to != p) {
      if (dfs(to, x)) count--;
    }
  if (count) {
    if (x != 1) cp++;
    lv += count;
  }
  return count > 0;
}
int solve() {
  cp = 0, lv = 0;
  int v = dfs(1, 1);
  if (v) return lv - cp;
  return lv - cp + 1;
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    printf("(%d)\n", solve());
  }
}
