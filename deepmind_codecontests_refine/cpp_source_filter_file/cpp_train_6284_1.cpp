#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<pair<int, int> > rebro;
vector<int> ans;
int main() {
  int n, m, h, t, a, b;
  scanf("%d %d %d %d", &n, &m, &h, &t);
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
    rebro.push_back(make_pair(a, b));
    rebro.push_back(make_pair(b, a));
  }
  for (int r = 0; r < rebro.size(); r++) {
    int v = rebro[r].first, u = rebro[r].second;
    if (g[v].size() >= h + 1 && g[u].size() >= t + 1) {
      vector<int> ans(n + 1, 0);
      int all = 0;
      for (int i = 0; i < g[v].size(); i++)
        if (!ans[g[v][i]]) ans[g[v][i]] = 1;
      for (int i = 0; i < g[u].size(); i++)
        if (!ans[g[u][i]])
          ans[g[u][i]] = 2;
        else {
          ans[g[u][i]] = 3;
          all++;
        }
      if ((g[v].size() + g[u].size() - all) >= (h + t + 2)) {
        printf("YES\n");
        printf("%d %d\n", v, u);
        if ((g[v].size() - 1 - all) >= h + 1) {
          for (int i = 0, k = 0; i < g[v].size() && k <= h; i++)
            if (ans[g[v][i]] == 1 && g[v][i] != u) {
              printf("%d ", g[v][i]);
              k++;
            }
        } else {
          int d = all - (g[v].size() - 1 - h);
          for (int i = 0, k = 0; i < g[v].size() && k <= h; i++) {
            if (ans[g[v][i]] == 1 && g[v][i] != u) {
              printf("%d ", g[v][i]);
              k++;
            } else if (ans[g[v][i]] == 3 && d > 0) {
              printf("%d ", g[v][i]);
              d--;
              ans[g[v][i]] = 1;
              k++;
            }
          }
        }
        printf("\n");
        for (int i = 0, k = 0; i < g[u].size() && k <= t; i++)
          if (ans[g[u][i]] > 1 && g[u][i] != v) {
            printf("%d ", g[u][i]);
            k++;
          }
        return 0;
      }
    }
  }
  printf("NO");
  return 0;
}
