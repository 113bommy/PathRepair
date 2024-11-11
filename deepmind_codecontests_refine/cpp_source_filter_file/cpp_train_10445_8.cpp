#include <bits/stdc++.h>
using namespace std;
double d[210][210][410];
int pro[210];
int cap[210];
int main() {
  int n, l, k;
  scanf("%d%d%d", &n, &l, &k);
  for (int i = 0; i < n; i++) scanf("%d", pro + i);
  for (int i = 0; i < n; i++) {
    scanf("%d", cap + i);
  }
  memset(d, 0, sizeof(d));
  d[0][0][200 + k] = 1;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      for (int m = 0; m <= 400; m++) {
        d[i + 1][j + 1][min(200, m + cap[i])] += d[i][j][m] * pro[i] / 100.0;
        d[i + 1][j][m] += d[i][j][m] * (1 - pro[i] / 100.0);
      }
  double ans = 0;
  for (int m = 200; m <= 400; m++)
    for (int j = l; j <= n; j++) ans += d[n][j][m];
  printf("%.10lf\n", ans);
  return 0;
}
