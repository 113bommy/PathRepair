#include <bits/stdc++.h>
using namespace std;
int n, m, k, b[155][2], f[155][155];
char a[155][155], ch;
void init() {
  int minx, maxx;
  for (int i = 1; i <= n; i++) {
    minx = -1;
    maxx = -1;
    for (int j = 1; j <= m; j++)
      if (a[i][j - 1] == 'W') {
        minx = j;
        k = max(k, i);
        break;
      }
    for (int j = m; j >= 1; j--)
      if (a[i][j - 1] == 'W') {
        maxx = j;
        break;
      }
    if (minx == -1) {
      b[i][0] = m;
      b[i][1] = 1;
    } else {
      b[i][0] = minx;
      b[i][1] = maxx;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) f[i][j] = 999999999;
  for (int j = b[1][1]; j <= m; j++) f[1][j] = j - 1;
}
void solve() {
  for (int i = 2; i <= k; i++)
    for (int j = 1; j <= m; j++)
      if (i % 2 == 0) {
        if (j > b[i][0]) break;
        for (int x = b[i][1]; x <= m; x++)
          f[i][j] = min(f[i][j], f[i - 1][x] + abs(x - j) + 1);
      } else {
        if (b[i][1] == -1) {
          continue;
        }
        if (j < b[i][1]) continue;
        for (int x = 1; x <= b[i][0]; x++)
          f[i][j] = min(f[i][j], f[i - 1][x] + abs(j - x) + 1);
      }
  if (k < 1)
    printf("0\n");
  else
    printf("%d\n", min(f[n][b[n][0]], f[n][b[n][1]]));
}
int main() {
  if (0) {
    freopen("a.inp", "r", stdin);
  };
  scanf("%d %d%c\n", &n, &m, &ch);
  for (int i = 1; i <= n; i++) scanf("%s", &a[i]);
  init();
  solve();
}
