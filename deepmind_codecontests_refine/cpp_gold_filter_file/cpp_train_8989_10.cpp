#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 66;
const long long mod = 1e9 + 7;
int n, m, h, t;
int a[maxn];
vector<int> g[maxn];
int vis[maxn];
int check(int u, int v) {
  int h1 = 0;
  int t1 = 0;
  for (int i = 0; i < g[u].size(); i++) {
    int x = g[u][i];
    vis[x] = u;
    h1++;
  }
  h1--;
  vis[v] = -1;
  for (int i = 0; i < g[v].size(); i++) {
    int x = g[v][i];
    if (vis[x] != u) {
      t1++;
      vis[x] = v;
    }
  }
  t1--;
  for (int i = 0; i < g[v].size(); i++) {
    if (g[v][i] == u) continue;
    int x = g[v][i];
    if (vis[x] == u && h1 > h) {
      vis[x] = v;
      h1--;
      t1++;
    }
  }
  if (h1 >= h && t1 >= t) {
    printf("YES\n");
    printf("%d %d\n", u, v);
    for (int i = 0; i < g[u].size(); i++) {
      if (vis[g[u][i]] == u) {
        printf("%d ", g[u][i]);
        h--;
      }
      if (h == 0) break;
    }
    printf("\n");
    for (int i = 0; i < g[v].size(); i++) {
      if (vis[g[v][i]] == v && g[v][i] != u) {
        printf("%d ", g[v][i]);
        t--;
      }
      if (t == 0) break;
    }
    printf("\n");
    return 1;
  }
  return 0;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &h, &t);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size() > h) {
      for (int j = 0; j < g[i].size(); j++) {
        int v = g[i][j];
        if (g[v].size() > t) {
          if (check(i, v)) return 0;
        }
      }
    }
  }
  printf("NO\n");
  return 0;
}
