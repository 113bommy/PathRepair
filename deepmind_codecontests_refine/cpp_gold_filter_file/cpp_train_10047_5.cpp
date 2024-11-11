#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
struct ioi {
  int u, v, vt;
};
int n1, n2, m, c[maxn][maxn], res, bac[maxn], d[maxn][maxn];
vector<int> a[maxn];
ioi canh[100010];
inline void nhap() {
  scanf("%d%d%d", &n1, &n2, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &canh[i].u, &canh[i].v);
    ++bac[canh[i].u];
    res = max(res, bac[canh[i].u]);
    ++bac[n1 + n2 - canh[i].v + 1];
    res = max(res, bac[n1 + n2 - canh[i].v + 1]);
    a[canh[i].u].push_back(n1 + n2 - canh[i].v + 1);
    ;
    a[n1 + n2 - canh[i].v + 1].push_back(canh[i].u);
  }
}
inline void gan(int u, int v, int k1, int k2, int no) {
  while (true) {
    if (no == 1) {
      int uu = d[v][k1];
      int co = c[u][v];
      d[v][co] = 0;
      d[u][k1] = v;
      d[v][k1] = u;
      c[u][v] = k1;
      u = uu;
      no = 2;
      if (u == 0) break;
    } else {
      int vv = d[u][k2];
      int co = c[u][v];
      d[u][co] = 0;
      d[u][k2] = v;
      d[v][k2] = u;
      c[u][v] = k2;
      v = vv;
      no = 1;
      if (v == 0) break;
    }
  }
}
inline void xl() {
  for (int u = 1; u <= n1; ++u) {
    for (int i = 0; i < (int)a[u].size(); ++i) {
      int v = a[u][i];
      if (c[u][v]) continue;
      bool yes = false;
      for (int k = 1; k <= res; ++k) {
        if (d[u][k] == 0 && d[v][k] == 0) {
          d[u][k] = v;
          d[v][k] = u;
          c[u][v] = k;
          yes = true;
          break;
        }
      }
      if (yes) continue;
      int k1, k2;
      for (k1 = 1; k1 <= res; ++k1)
        if (d[u][k1] == 0) break;
      for (k2 = 1; k2 <= res; ++k2)
        if (d[v][k2] == 0) break;
      gan(u, v, k1, k2, 1);
    }
  }
}
int main() {
  nhap();
  xl();
  printf("%d\n", res);
  for (int i = 1; i <= m; ++i) {
    int u = canh[i].u;
    int v = n1 + n2 - canh[i].v + 1;
    printf("%d ", c[u][v]);
  }
  return 0;
}
