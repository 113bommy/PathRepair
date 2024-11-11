#include <bits/stdc++.h>
using namespace std;
const int SZ = 1 << 6;
const int INF = 1 << 29;
int n, m;
int d[SZ][SZ];
int g1, g2, s1, s2;
long long res[SZ][SZ][SZ];
int v[SZ][SZ];
bool cang[SZ], cans[SZ], canb[SZ];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) d[i][j] = INF;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a, --b;
    d[b][a] = d[a][b] = min(d[a][b], c);
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i = 0; i < n; ++i) {
    int x = 0;
    for (int j = 0; j < n; ++j)
      if (i != j) v[i][x++] = d[i][j];
    sort(v[i], v[i] + n - 1);
    if (v[i][n - 1] == INF) throw -1;
  }
  scanf("%d%d", &g1, &g2);
  scanf("%d%d", &s1, &s2);
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      pair<int, int> a = make_pair(v[i][0], i);
      pair<int, int> b = make_pair(v[j][n - 2], j);
      memset(cang, 0, sizeof(cang));
      memset(cans, 0, sizeof(cans));
      memset(canb, 0, sizeof(canb));
      for (int k = 0; k < n; ++k) {
        if (k == i) {
          cang[k] = true;
          continue;
        }
        if (k == j) {
          canb[k] = true;
          continue;
        }
        if (make_pair(v[k][0], k) < a) cang[k] = true;
        if (make_pair(v[k][n - 2], k) > b) canb[k] = true;
        for (int l = 0; l < n - 1; ++l)
          if (make_pair(v[k][l], k) > a && make_pair(v[k][l], k) < b) {
            cans[k] = true;
            break;
          }
      }
      memset(res, 0, sizeof(res));
      res[0][0][0] = 1;
      for (int k = 0; k < n; ++k) {
        for (int g = 0; g < n + 1; ++g)
          for (int b = 0; b < n + 1 - g; ++b) {
            if (cang[k]) res[k + 1][g + 1][b] += res[k][g][b];
            if (cans[k]) res[k + 1][g][b] += res[k][g][b];
            if (canb[k]) res[k + 1][g][b + 1] += res[k][g][b];
          }
      }
      for (int g = 0; g < n + 1; ++g)
        for (int b = 0; b < n - g + 1; ++b) {
          int s = n - g - b;
          if (g1 <= g && g <= g2 && s1 <= s && s <= s2) ans += res[n][g][b];
        }
    }
  printf("%d\n", ans);
  return 0;
}
