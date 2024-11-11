#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000005;
struct A {
  int x, y, z;
};
vector<A> res;
vector<pair<int, int> > G[MAXN];
int n, m;
int mark[MAXN], vis[MAXN];
void dfs(int u, int pe, int fa) {
  vis[u] = 1;
  for (int i = (0); i < (G[u].size()); i++) {
    int v = G[u][i].first, id = G[u][i].second;
    if (vis[v]) continue;
    dfs(v, id, u);
  }
  vector<pair<int, int> > vec;
  for (int i = (0); i < (G[u].size()); i++) {
    int id = G[u][i].second;
    if (!mark[id] && id != pe) vec.push_back(G[u][i]);
  }
  for (int i = 0; i < vec.size() / 2; i++) {
    mark[vec[i * 2].second] = mark[vec[i * 2 + 1].second] = 1;
    res.push_back((A){vec[i].first, u, vec[i + 1].first});
  }
  if (vec.size() & 1 && pe != -1) {
    mark[pe] = mark[vec[vec.size() - 1].second] = 1;
    res.push_back((A){vec[vec.size() - 1].first, u, fa});
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(make_pair(v, i));
    G[v].push_back(make_pair(u, i));
  }
  dfs(1, -1, -1);
  if (m & 1)
    puts("No solution");
  else
    for (int i = (0); i < (res.size()); i++) {
      printf("%d %d %d\n", res[i].x, res[i].y, res[i].z);
    }
  return 0;
}
