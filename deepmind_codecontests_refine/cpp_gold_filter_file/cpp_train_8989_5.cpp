#include <bits/stdc++.h>
using namespace std;
const int maxn = 111111;
int n, m;
vector<int> g[maxn];
int chk[maxn];
int h, t;
int tail[maxn], head[maxn];
void prin(int u, int v) {
  printf("YES\n%d %d\n", u, v);
  for (int i = 1; i <= n; ++i)
    if (head[i]) printf("%d ", i);
  printf("\n");
  for (int i = 1; i <= n; ++i)
    if (tail[i]) printf("%d ", i);
  printf("\n");
  exit(0);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &h, &t);
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int u = 1; u <= n; ++u)
    if (g[u].size() > h) {
      for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (g[v].size() <= t) continue;
        if (g[u].size() > h + t) {
          for (int cur = 0, j = 0; j < g[v].size() && cur < t; ++j)
            if (g[v][j] != u) {
              tail[g[v][j]] = 1;
              ++cur;
            }
          for (int cur = 0, j = 0; j < g[u].size() && cur < h; ++j)
            if (!tail[g[u][j]] && i != j) {
              head[g[u][j]] = 1;
              ++cur;
            }
          prin(u, v);
        }
        for (int j = 0; j < g[u].size(); ++j)
          if (i != j) {
            chk[g[u][j]] = 1;
          }
        vector<int> pen;
        for (int j = 0; j < g[v].size(); ++j)
          if (g[v][j] != u) {
            if (chk[g[v][j]]) pen.push_back(g[v][j]), chk[g[v][j]] = 0;
          }
        if (g[v].size() + g[u].size() - pen.size() - 2 >= h + t) {
          int cur = 0;
          for (int j = 0; j < g[u].size(); ++j)
            if (cur < h && chk[g[u][j]]) ++cur, head[g[u][j]] = 1;
          for (int j = 0; j < pen.size(); ++j)
            if (cur < h) ++cur, head[pen[j]] = chk[pen[j]] = 1;
          cur = 0;
          for (int j = 0; j < g[v].size(); ++j)
            if (cur < t && !chk[g[v][j]] && g[v][j] != u)
              ++cur, tail[g[v][j]] = 1;
          prin(u, v);
        }
        for (int j = 0; j < g[u].size(); ++j) chk[g[u][j]] = 0;
      }
    }
  printf("NO");
  return 0;
}
