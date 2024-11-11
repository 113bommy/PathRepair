#include <bits/stdc++.h>
using namespace std;
bool mark[100010];
vector<int> graf[100010];
int DFS(int u, int parent) {
  mark[u] = true;
  for (int i = 0; i < graf[u].size(); i++) {
    int v = graf[u][i];
    if (v == parent) continue;
    if (v != parent && mark[v]) return 1;
    if (DFS(v, u) == 1) return 1;
  }
  return 0;
}
int main() {
  int n, m, sol = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    graf[u].push_back(v);
    graf[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) sol += (1 - DFS(i, -1));
  }
  printf("%d\n", sol);
  return 0;
}
