#include <bits/stdc++.h>
using namespace std;
int tast[210];
vector<int> g[210], p, pp;
int num[210], tmp[210];
int main() {
  int n, m, u;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &tast[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
      scanf("%d", &u);
      g[u].push_back(i);
      num[i]++;
    }
  }
  int ans = 1000000000;
  memcpy(tmp, num, sizeof(tmp));
  for (int i = 1; i <= 3; i++) {
    memcpy(num, tmp, sizeof(tmp));
    p.clear();
    for (int j = 1; j <= n; j++) {
      if (!num[j]) p.push_back(j);
    }
    int k = i;
    int tim = 0;
    while (!p.empty()) {
      bool ok = true;
      while (ok) {
        ok = false;
        pp.clear();
        for (int j = (int)p.size() - 1; j >= 0; j--) {
          u = p[j];
          if (tast[u] == k) {
            tim++;
            for (int v = (int)g[u].size() - 1; v >= 0; v--) {
              num[g[u][v]]--;
              if (!num[g[u][v]]) {
                ok = true;
                pp.push_back(g[u][v]);
              }
            }
          } else
            pp.push_back(u);
        }
        p = pp;
      }
      if (k == 3)
        k = 1;
      else if (k == 1)
        k = 2;
      else
        k = 3;
      if (p.empty()) break;
      tim++;
    }
    ans = min(ans, tim);
  }
  printf("%d\n", ans);
  return 0;
}
