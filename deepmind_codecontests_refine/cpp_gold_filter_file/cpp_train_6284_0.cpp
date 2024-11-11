#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n, m, H, T;
vector<int> g[N];
pair<int, int> e[N];
bool vis[2][N];
int main() {
  scanf("%d%d%d%d", &n, &m, &H, &T);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &e[i].first, &e[i].second);
    --e[i].first;
    --e[i].second;
    g[e[i].first].push_back(e[i].second);
    g[e[i].second].push_back(e[i].first);
  }
  pair<int, int> res = make_pair(-1, -1);
  vector<int> a, b;
  for (int i = 0; i < m; ++i) {
    int u = e[i].first, v = e[i].second;
    for (int it = 0; it < 2; ++it) {
      swap(u, v);
      if ((int)g[u].size() - 1 < H || (int)g[v].size() - 1 < T) continue;
      if ((int)g[u].size() - 1 >= H + T && (int)g[v].size() - 1 >= H + T) {
        res = make_pair(u, v);
        for (size_t j = 0; j < g[u].size(); ++j)
          if (g[u][j] != v) {
            a.push_back(g[u][j]);
            vis[0][g[u][j]] = true;
            if ((int)a.size() == H) break;
          }
        for (size_t j = 0; j < g[v].size(); ++j)
          if (g[v][j] != u && !vis[0][g[v][j]]) {
            b.push_back(g[v][j]);
            if ((int)b.size() == T) break;
          }
        break;
      }
      a.clear();
      b.clear();
      for (size_t j = 0; j < g[u].size(); ++j) vis[0][g[u][j]] = true;
      for (size_t j = 0; j < g[v].size(); ++j)
        if (!vis[0][g[v][j]] && g[v][j] != u) {
          b.push_back(g[v][j]);
          vis[1][g[v][j]] = true;
          if ((int)b.size() == T) break;
        }
      for (size_t j = 0; j < g[v].size(); ++j) {
        if ((int)b.size() == T) break;
        if (!vis[1][g[v][j]] && g[v][j] != u) {
          b.push_back(g[v][j]);
          vis[1][g[v][j]] = true;
        }
      }
      for (size_t j = 0; j < g[u].size(); ++j)
        if (!vis[1][g[u][j]] && g[u][j] != v) {
          a.push_back(g[u][j]);
          if ((int)a.size() == H) break;
        }
      for (size_t j = 0; j < g[u].size(); ++j) vis[0][g[u][j]] = false;
      for (size_t j = 0; j < g[v].size(); ++j) vis[1][g[v][j]] = false;
      if ((int)a.size() == H && (int)b.size() == T) {
        res = make_pair(u, v);
        break;
      }
    }
    if (res.first != -1) break;
  }
  if (res.first == -1)
    puts("NO");
  else {
    printf("YES\n%d %d\n", res.first + 1, res.second + 1);
    for (int i = 0; i < H; ++i) printf("%s%d", i ? " " : "", a[i] + 1);
    puts("");
    for (int i = 0; i < T; ++i) printf("%s%d", i ? " " : "", b[i] + 1);
    puts("");
  }
  return 0;
}
