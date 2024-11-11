#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
vector<int> g[maxn];
int chose[maxn], vis[maxn], ans;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      int sz = g[i].size();
      for (int j = 0; j < sz; j++) vis[g[i][j]] = 1;
      vis[i] = chose[i] = 1;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (chose[i]) {
      int sz = g[i].size();
      for (int j = 0; j < sz; j++) chose[g[i][j]] = 0;
    }
  }
  for (int i = 1; i <= n; i++)
    if (chose[i]) ans++;
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (chose[i]) printf("%d ", i);
  return 0;
}
