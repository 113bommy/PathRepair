#include <bits/stdc++.h>
using namespace std;
int p[1100][1100];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &p[i][j]);
  while (k--) {
    char s;
    int x, y;
    scanf(" %s %d %d", &s, &x, &y);
    if (s == 'c')
      for (int i = 1; i <= n; i++) swap(p[i][x], p[i][y]);
    if (s == 'r')
      for (int i = 1; i <= m; i++) swap(p[x][i], p[y][i]);
    if (s == 'g') printf("%d\n", p[x][y]);
  }
  return 0;
}
