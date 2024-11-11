#include <bits/stdc++.h>
using namespace std;
int n, a, b, g[110][110];
int main() {
  scanf("%d%d%d", &n, &a, &b);
  if (n > a * b)
    puts("-1");
  else {
    int x = 1, y = 0, dy = 1;
    for (int i = 1; i <= n; i++) {
      y += dy;
      if (y == 0 || y == b + 1) {
        x++;
        y -= dy;
        dy = -dy;
      }
      g[x][y] = i;
    }
    for (int i = 1; i <= a; i++) {
      for (int j = 1; j < b; j++) printf("%d ", g[i][j]);
      printf("%d\n", g[i][b]);
    }
  }
  return 0;
}
