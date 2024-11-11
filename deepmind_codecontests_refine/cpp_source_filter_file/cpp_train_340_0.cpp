#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305;
int c[MAXN][MAXN];
int n, m;
int mar[15][MAXN][MAXN];
int now[MAXN][MAXN];
int tmp[MAXN][MAXN];
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) c[i][j] = -100000000;
  for (int i = 1; i <= n; i++) c[i][i] = 0;
  while (m--) {
    int p, q;
    scanf("%d%d", &p, &q);
    scanf("%d%d", &c[p][q], &c[q][p]);
  }
  memset(mar, -20, sizeof(mar));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) mar[0][i][j] = c[i][j];
  for (int t = 1; t <= 10; t++) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
          if (mar[t - 1][i][j] + mar[t - 1][j][k] > mar[t][i][k])
            mar[t][i][k] = mar[t - 1][i][j] + mar[t - 1][j][k];
  }
  bool flag = false;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (mar[10][i][j] > 0) flag = true;
  if (!flag) {
    printf("0\n");
    return 0;
  }
  memset(now, -20, sizeof(now));
  int ans = 0;
  for (int i = 1; i <= n; i++) now[i][i] = 0;
  for (int t = 10; t >= 0; t--) {
    bool flag = false;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (mar[t][i][j] + now[j][i] > 0) flag = true;
    if (flag) continue;
    ans += (1 << t);
    memset(tmp, -20, sizeof(tmp));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
          if (mar[t][i][j] + now[j][k] > tmp[i][k])
            tmp[i][k] = mar[t][i][j] + now[j][k];
    memcpy(now, tmp, sizeof(now));
  }
  printf("%d\n", ans + 1);
  return 0;
}
