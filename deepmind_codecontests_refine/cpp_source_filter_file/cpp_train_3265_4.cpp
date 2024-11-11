#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, ex, ey, l;
int dist[102][102];
char cmap[102][102];
char str[1003];
pair<int, int> plc[30];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", cmap[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (cmap[i][j] >= 'a' && cmap[i][j] <= 'z') {
        plc[cmap[i][j] - 'a'] = {i, j};
        dist[i][j] = 1;
      } else if (cmap[i][j] >= '1' && cmap[i][j] <= '9')
        dist[i][j] = cmap[i][j] - '0';
  scanf("%d%d", &x, &y);
  scanf("%s", str);
  scanf("%d%d", &ex, &ey);
  x--;
  y--;
  ex--;
  ey--;
  l = strlen(str);
  str[l++] = 'a' + 26;
  plc[26] = {ex, ey};
  for (int i = 0; i < l; i++) {
    int tx, ty;
    tx = plc[str[i + 1] - 'a'].first;
    ty = plc[str[i + 1] - 'a'].second;
    while (x != tx || y != ty) {
      k -= dist[x][y];
      if (k < 0) {
        printf("%d %d\n", x + 1, y + 1);
        return 0;
      }
      if (x > tx)
        x--;
      else if (x < tx)
        x++;
      else if (y > ty)
        y--;
      else
        y++;
    }
  }
  printf("%d %d\n", ex + 1, ey + 1);
  return 0;
}
