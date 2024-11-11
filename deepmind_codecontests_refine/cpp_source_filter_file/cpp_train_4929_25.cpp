#include <bits/stdc++.h>
using namespace std;
const int MAXN = 64;
const int MAXK = 1024;
int n, m, r;
int s, t, k;
int d[MAXN][MAXN][MAXN];
int dmin[MAXK][MAXN][MAXN];
int main() {
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) scanf("%d", &d[i][j][k]);
    for (int v = 1; v <= n; v++)
      for (int s = 1; s <= n; s++)
        for (int t = s + 1; t <= n; t++) {
          d[i][s][t] = min(d[i][s][t], d[i][s][v] + d[i][v][t]);
        };
  }
  for (int i = 1; i <= m; i++)
    for (int s = 1; s <= n; s++)
      for (int t = 1; t <= n; t++) dmin[i][s][t] = INT_MAX;
  for (int i = 1; i <= m; i++) {
    for (int s = 1; s <= n; s++)
      for (int t = 1; t <= n; t++) {
        dmin[1][s][t] = min(dmin[1][s][t], d[i][s][t]);
      }
  };
  for (int i = 2; i <= 1020; i++) {
    for (int s = 1; s <= n; s++)
      for (int t = 1; t <= n; t++) dmin[i][s][t] = dmin[i - 1][s][t];
    for (int s = 1; s <= n; s++)
      for (int t = 1; t <= n; t++)
        for (int v = 1; v <= n; v++)
          dmin[i][s][t] = min(dmin[i][s][t], dmin[i - 1][s][v] + dmin[1][v][t]);
    ;
  }
  for (int i = 0; i < r; i++) {
    scanf("%d%d%d", &s, &t, &k);
    cout << dmin[k + 1][s][t] << endl;
  };
}
