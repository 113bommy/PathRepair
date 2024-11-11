#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
const int M = 2000 + 5;
int n, m, st[N];
bool vis[M][M];
vector<int> G[N], cir;
void make_graph() {
  for (int i = 0; i < m; i++) {
    G[st[i]].push_back(st[i + 1]);
    G[st[i + 1]].push_back(st[i]);
    vis[st[i]][st[i + 1]] = true;
    vis[st[i + 1]][st[i]] = true;
  }
  for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
}
void find_cir(int u) {
  for (int i = 0; i < G[u].size(); i++)
    if (!vis[u][G[u][i]]) {
      vis[u][G[u][i]] = vis[G[u][i]][u] = true;
      find_cir(G[u][i]);
    }
  cir.push_back(u);
}
bool ok(int i) {
  bool ret = (cir.back() == st[m] && cir.size() == m - i);
  if (ret) return true;
  for (int j = 0; j < cir.size() - 1; j++)
    vis[cir[j]][cir[j + 1]] = vis[cir[j + 1]][cir[j]] = false;
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m + 1; i++) scanf("%d", &st[i]);
  make_graph();
  for (int i = m - 1; i >= 0; i--) {
    int u = st[i];
    vis[u][st[i + 1]] = vis[st[i + 1]][u] = false;
    for (int j = 0; j < G[u].size(); j++)
      if (!vis[u][G[u][j]] && G[u][j] > st[i + 1]) {
        vis[u][G[u][j]] = vis[G[u][j]][u] = true;
        find_cir(G[u][j]);
        reverse(cir.begin(), cir.end());
        if (ok(i)) break;
        cir.clear();
        vis[u][G[u][j]] = vis[G[u][j]][u] = false;
      }
    if (cir.empty()) continue;
    for (int j = 0; j <= i; j++) printf("%d ", st[j]);
    for (int j = 0; j < cir.size(); j++) printf("%d ", cir[j]);
    break;
  }
  if (cir.empty()) puts("No solution");
  return 0;
}
