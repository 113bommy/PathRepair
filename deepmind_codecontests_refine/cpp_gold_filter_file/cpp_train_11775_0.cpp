#include <bits/stdc++.h>
using namespace std;
int n, ans;
bool v[200001];
vector<int> adj[200001];
void dfs(int i, int parent, int d) {
  for (int j : adj[i]) {
    if (j != parent) dfs(j, i, d + 1);
  }
  if (d > 2 && !v[i]) {
    ans++;
    v[parent] = true;
    for (int j : adj[parent]) v[j] = true;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0, 0);
  printf("%d\n", ans);
  return 0;
}
