#include <bits/stdc++.h>
using namespace std;
struct edge {
  int a, b;
  bool inTree;
};
int n, m;
edge e[100010];
vector<int> v[100010], deg[100010], child[100010];
bool vis[100010];
void dfs1(int x) {
  vis[x] = true;
  for (int i = 0; i < v[x].size(); i++) {
    int y = e[v[x][i]].a;
    if (y == x) y = e[v[x][i]].b;
    if (!vis[y]) {
      e[v[x][i]].inTree = true;
      child[x].push_back(y);
      dfs1(y);
    }
  }
}
void dfs2(int x) {
  for (int i = 0; i < child[x].size(); i++) {
    dfs2(child[x][i]);
    if (deg[child[x][i]].size() % 2 == 0)
      deg[x].push_back(child[x][i]);
    else
      deg[child[x][i]].push_back(x);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> e[i].a >> e[i].b;
    v[e[i].a].push_back(i);
    v[e[i].b].push_back(i);
  }
  dfs1(1);
  for (int i = 0; i < m; i++) {
    if (!e[i].inTree) {
      deg[e[i].a].push_back(e[i].b);
    }
  }
  dfs2(1);
  if (deg[1].size() % 2 != 0)
    cout << "No solution";
  else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < deg[i].size(); j++) {
        cout << deg[i][j - 1] << ' ' << i << ' ' << deg[i][j] << '\n';
      }
    }
  }
}
