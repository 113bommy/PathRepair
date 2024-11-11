#include <bits/stdc++.h>
using namespace std;
int n, m, h, t;
vector<int> a[111111];
int fl[111111];
inline void gethydra(const int u, const int v) {
  if ((a[u].size() <= a[v].size()) == (h <= t)) {
    printf("YES\n%d %d\n", u, v);
    memset(fl, 0, sizeof fl);
    for (int i = 0; i < a[v].size(); i++) fl[a[v][i]] = -1;
    fl[v] = 1;
    fl[u] = 1;
    for (int i = 0; h && i < a[u].size(); i++)
      if (fl[a[u][i]] != -1 && fl[a[u][i]] != 1) {
        h--;
        printf("%d ", a[u][i]);
        fl[a[u][i]] = 1;
      }
    for (int i = 0; h && i < a[u].size(); i++)
      if (fl[a[u][i]] == -1) {
        h--;
        printf("%d ", a[u][i]);
        fl[a[u][i]] = 1;
      }
    printf("\n");
    for (int i = 0; t && i < a[v].size(); i++)
      if (fl[a[v][i]] != 1) {
        t--;
        printf("%d ", a[v][i]);
      }
  } else
    gethydra(v, u);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &h, &t);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int u = 1; u <= n; u++)
    if (a[u].size() > h + t)
      for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (a[v].size() > min(h, t)) {
          gethydra(u, v);
          return 0;
        }
      }
  for (int u = 1; u <= n; u++)
    if (a[u].size() > min(h, t)) {
      for (int i = 0; i < a[u].size(); i++) fl[a[u][i]] = u;
      for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        int red = 0;
        for (int j = 0; j < a[v].size(); j++)
          if (fl[a[v][j]] == u) red++;
        if (a[u].size() + a[v].size() - red >= h + t + 2 &&
            max(a[u].size(), a[v].size()) > max(h, t) &&
            min(a[u].size(), a[v].size()) > max(h, t)) {
          gethydra(u, v);
          return 0;
        }
      }
    }
  printf("NO\n");
  return 0;
}
