#include <bits/stdc++.h>
using namespace std;
int n, m, h, t;
vector<vector<int> > g;
vector<int> intersect(100 * 1000, -1);
int sizes[100 * 1000];
void init() {
  scanf("%d %d %d %d", &n, &m, &h, &t);
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    int from, to;
    scanf("%d %d", &from, &to);
    --from, --to;
    g[from].push_back(to);
    g[to].push_back(from);
  }
  for (int i = 0; i < n; ++i) sizes[i] = g[i].size();
}
int main() {
  init();
  int isAns = false;
  int v1, v2;
  for (int i = 0; i < n && !isAns; ++i) {
    v1 = i;
    for (int c = 0; c < sizes[i]; ++c) intersect[g[i][c]] = i;
    for (int j = 0; j < sizes[i] && !isAns; ++j) {
      if (g[i][j] > i) {
        v2 = g[i][j];
        int u1 = sizes[v1] - 1;
        int u2 = sizes[v2] - 1;
        if (min(u1, u2) < min(h, t) || max(u1, u2) < max(h, t)) continue;
        int k = 0;
        for (int r = 0; r < sizes[v2]; ++r) k += intersect[g[v2][r]] == i;
        if (u1 + u2 - k < h + t) continue;
        if (h < t != u1 < u2) swap(v1, v2);
        isAns = true;
      }
    }
  }
  if (!isAns)
    printf("NO\n");
  else {
    printf("YES\n%d %d\n", v1 + 1, v2 + 1);
    vector<bool> isUse(100 * 1000, false);
    for (int c = 0; c < sizes[v1]; ++c) intersect[g[v1][c]] = -2;
    for (int r = 0; r < sizes[v2]; ++r) --intersect[g[v2][r]];
    int k = 0;
    for (int j = 0; j < g[v1].size() && k < h; ++j)
      if (intersect[g[v1][j]] > -2 && g[v1][j] != v2)
        printf("%d ", g[v1][j] + 1), ++k;
    for (int j = 0; j < g[v1].size() && k < h; ++j)
      if (intersect[g[v1][j]] == -2 && g[v1][j] != v2)
        printf("%d ", g[v1][j] + 1), ++k, isUse[g[v1][j]] = true;
    printf("\n");
    k = 0;
    for (int i = 0; i < g[v2].size() && k < t; ++i)
      if (!isUse[g[v2][i]] && g[v2][i] != v1) printf("%d ", g[v2][i] + 1), ++k;
  }
  return 0;
}
