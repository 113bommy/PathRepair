#include <bits/stdc++.h>
using namespace std;
bool block[100005];
vector<pair<int, int> > graph[100005];
int dfs(int u) {
  vector<int> free, unpared;
  for (int i = 0; i < graph[u].size(); i++) {
    int id = graph[u][i].second;
    int v = graph[u][i].first;
    if (block[id]) continue;
    free.push_back(v);
    block[id] = 1;
  }
  for (int i = 0; i < free.size(); i++) {
    int v = free[i];
    int w = dfs(v);
    if (w == 0)
      unpared.push_back(v);
    else {
      printf("%d %d %d\n", u, v, w);
    }
  }
  if (unpared.size() > 1) {
    int v = unpared.back();
    unpared.pop_back();
    int w = unpared.back();
    unpared.pop_back();
    printf("%d %d %d\n", v, u, w);
  }
  if (unpared.size()) {
    return unpared.back();
  } else
    return 0;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u].push_back({v, i});
    graph[v].push_back({u, i});
  }
  if (m & 1) {
    puts("No solution");
    return 0;
  } else {
    dfs(1);
  }
  return 0;
}
