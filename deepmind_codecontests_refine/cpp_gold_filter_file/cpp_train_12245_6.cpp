#include <bits/stdc++.h>
using namespace std;
int black = 0, white = 0;
vector<int> G[100010];
void dfs(int u, int d, int fa) {
  if (d & 1)
    black++;
  else
    white++;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs(v, d + 1, u);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 1, -1);
  cout << 1LL * black * white - n + 1 << endl;
  return 0;
}
