#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N = 2e5 + 5;
vector<int> G[N], G2[N];
int n, m, u, v;
int answer(int u) {
  printf("! %d\n", u);
  fflush(stdout);
  return 0;
}
int Q1(int u) {
  printf("d %d\n", u);
  fflush(stdout);
  scanf("%d", &u);
  if (u == -1) exit(0);
  return u;
}
int Q2(int u) {
  printf("s %d\n", u);
  fflush(stdout);
  scanf("%d", &u);
  if (u == -1) exit(0);
  return u;
}
int vis[N];
vector<int> V;
int dfs(int u, int d) {
  if (!d) {
    V.push_back(u);
    return 1;
  }
  int rr = 0;
  for (auto &v : G[u]) {
    if (vis[v]) continue;
    vis[v] = u;
    if (dfs(v, d - 1)) {
      G2[u].push_back(v);
      rr = 1;
    }
  }
  return rr;
}
void re_dfs(int u, int d) {
  memset(vis, 0, sizeof(vis));
  vis[u] = -1;
  V.clear();
  for (int i = 1; i <= n; ++i) G2[i].clear();
  dfs(u, d);
  swap(G2, G);
}
int main() {
  srand(time(0) + 233);
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int dis = Q1(1), i = 1;
  re_dfs(1, dis);
  while (G[i].size() == 1) i = G[i][0], --dis;
  while (V.size() > 1) {
    i = Q2(i);
    --dis;
    re_dfs(i, dis);
    if (V.size() == 1) break;
    i = V[rand() % V.size()];
    dis = Q1(i) >> 1;
    for (int i = 0; i < dis; ++i) i = vis[i];
    re_dfs(i, dis);
  }
  return answer(V[0]);
}
