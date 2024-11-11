#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0;
  char ch = 0;
  while (ch < 48 || ch > 57) ch = getchar();
  while (ch >= 48 && ch <= 57) X = X * 10 + (ch ^ 48), ch = getchar();
  return X;
}
int f[90500];
int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }
bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return 0;
  f[u] = v;
  return 1;
}
int n, m, q;
struct Data {
  int x, y, p;
};
vector<Data> g[2005000], g2[2005000];
int s[305][305], ans[2005000];
bool e[305][305];
int main() {
  n = read();
  m = read();
  q = read();
  for (int i = 1, x, y, c; i <= q; i++) {
    x = read();
    y = read();
    c = read();
    g[c].push_back((Data){x, y, i});
    g2[s[x][y]].push_back((Data){x, y, i});
    s[x][y] = c;
  }
  for (int c = 0; c <= 1000; c++) {
    if (g[c].empty()) continue;
    for (int i = 1; i <= n * m; i++) f[i] = i;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) e[i][j] = 0;
    for (int i = 0; i < g[c].size(); i++) {
      int x = g[c][i].x, y = g[c][i].y, p = g[c][i].p;
      int sav = ans[p];
      e[x][y] = 1;
      ans[p]++;
      if (e[x][y - 1]) ans[p] -= merge(((x)*m + (y)-m), ((x)*m + (y - 1) - m));
      if (e[x][y + 1]) ans[p] -= merge(((x)*m + (y)-m), ((x)*m + (y + 1) - m));
      if (e[x - 1][y]) ans[p] -= merge(((x)*m + (y)-m), ((x - 1) * m + (y)-m));
      if (e[x + 1][y]) ans[p] -= merge(((x)*m + (y)-m), ((x + 1) * m + (y)-m));
    }
  }
  for (int c = 0; c <= 1000; c++) {
    if (g2[c].empty()) continue;
    for (int i = 1; i <= n * m; i++) f[i] = i;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) e[i][j] = (s[i][j] == c);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (e[i][j] && e[i][j + 1])
          merge(((i)*m + (j)-m), ((i)*m + (j + 1) - m));
        if (e[i][j] && e[i + 1][j])
          merge(((i)*m + (j)-m), ((i + 1) * m + (j)-m));
      }
    reverse(g2[c].begin(), g2[c].end());
    for (int i = 0; i < g2[c].size(); i++) {
      int x = g2[c][i].x, y = g2[c][i].y, p = g2[c][i].p;
      int sav = ans[p];
      e[x][y] = 1;
      ans[p]--;
      if (e[x][y - 1]) ans[p] += merge(((x)*m + (y)-m), ((x)*m + (y - 1) - m));
      if (e[x][y + 1]) ans[p] += merge(((x)*m + (y)-m), ((x)*m + (y + 1) - m));
      if (e[x - 1][y]) ans[p] += merge(((x)*m + (y)-m), ((x - 1) * m + (y)-m));
      if (e[x + 1][y]) ans[p] += merge(((x)*m + (y)-m), ((x + 1) * m + (y)-m));
    }
  }
  ans[0] = 1;
  for (int i = 1; i <= q; i++) {
    ans[i] += ans[i - 1];
    printf("%d\n", ans[i]);
  }
  return 0;
}
