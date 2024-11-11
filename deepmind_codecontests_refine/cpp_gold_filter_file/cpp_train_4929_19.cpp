#include <bits/stdc++.h>
using namespace std;
int d[60][60][1001];
int t[60][60][60];
int n, m, r;
int main() {
  scanf("%d%d%d", &n, &m, &r);
  for (int l = 0; l < m; l++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) scanf("%d", &t[i][j][l]);
  for (int l = 0; l < m; l++)
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          t[i][j][l] = min(t[i][j][l], t[i][k][l] + t[k][j][l]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      d[i][j][0] = t[i][j][0];
      for (int l = 0; l < m; l++) d[i][j][0] = min(d[i][j][0], t[i][j][l]);
    }
  for (int k = 1; k <= 1000; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        d[i][j][k] = d[i][j][k - 1];
        for (int l = 0; l < n; l++)
          d[i][j][k] = min(d[i][j][k], d[i][l][0] + d[l][j][k - 1]);
      }
  for (int i = 0; i < r; i++) {
    int x, y, k;
    scanf("%d%d%d", &x, &y, &k);
    printf("%d\n", d[x - 1][y - 1][k]);
  }
  return 0;
}
