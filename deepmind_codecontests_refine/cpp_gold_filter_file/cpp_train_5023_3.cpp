#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, color[2 * maxn], at[2 * maxn];
bool vis[maxn];
vector<int> node[1 << 20], route;
void dfs(int curNode) {
  while (node[curNode].size()) {
    int now = node[curNode].back();
    node[curNode].pop_back();
    if (!vis[now >> 1]) {
      vis[now >> 1] = true;
      dfs(at[now ^ 1]);
      if (!route.size() || at[route.back()] == at[now ^ 1]) {
        route.push_back(now ^ 1);
        route.push_back(now);
      }
    }
  }
}
bool solve(int beauty) {
  route.clear();
  for (int i = 0; i < 1 << beauty; i++) node[i].clear();
  for (int i = 0; i < 2 * n; i++) {
    at[i] = color[i] & (1 << beauty) - 1;
    node[at[i]].push_back(i);
  }
  dfs(at[0]);
  if (route.size() == 2 * n && at[route.back()] == at[route.front()])
    return true;
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) scanf("%d", &color[i]);
  for (int i = 20; i >= 0; i--) {
    memset(vis, 0, sizeof(vis));
    if (solve(i)) {
      printf("%d\n", i);
      for (auto j : route) printf("%d ", j + 1);
      break;
    }
  }
}
