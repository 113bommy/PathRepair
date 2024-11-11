#include <bits/stdc++.h>
using namespace std;
int a[610][610];
int main() {
  int q, i, h, w, j, l, x, y;
  scanf("%d", &q);
  for (i = 1; i <= q; i++) {
    scanf("%d%d", &h, &w);
    for (j = 1; j <= h; j++)
      for (l = 1; l <= w; l++) scanf("%d", &a[j][l]);
    x = 0;
    for (j = 1; j <= w; j++) x += abs(a[1][j] - a[h][j]);
    y = 0;
    for (j = 1; j <= w; j++) y += abs(a[h / 2][j] - a[h / 2 + 1][j]);
    if (x < y)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
