#include <bits/stdc++.h>
using namespace std;
int parent[2100], invalid[2100], vis[2100];
std::vector<int> comp[2100], adj[2100];
void dfs(int v, int index) {
  if (vis[v]) return;
  vis[v] = 1;
  comp[index].push_back(v);
  parent[v] = index;
  for (int i = 0; i < adj[v].size(); i++) {
    dfs(adj[v][i], index);
  }
}
int main() {
  int n, i, m, index, temp1, temp2, ans = 0;
  scanf("%d", &n);
  int k;
  scanf("%d", &k);
  for (i = 0; i < k; i++) {
    scanf("%d", &temp1);
    scanf("%d", &temp2);
    adj[temp1].push_back(temp2);
    adj[temp2].push_back(temp1);
  }
  scanf("%d", &m);
  index = 0;
  for (i = 0; i < n; i++) {
    if (!vis[i]) dfs(i, index++);
  }
  for (i = 0; i < m; i++) {
    scanf("%d", &temp1);
    scanf("%d", &temp2);
    if (parent[temp1] == parent[temp2]) invalid[parent[temp1]] = 1;
  }
  for (i = 0; i < index; i++) {
    if (!invalid[i]) ans = max(ans, (int)comp[i].size());
  }
  printf("%d\n", ans);
}
