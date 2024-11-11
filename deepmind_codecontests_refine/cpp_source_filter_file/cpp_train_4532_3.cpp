#include <bits/stdc++.h>
using namespace std;
int a[17][17];
int main() {
  int n, m, k, need;
  scanf("%d%d%d%d", &n, &m, &k, &need);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x, y;
      scanf("%d%d", &x, &y);
      a[x][y] = 1;
    }
  }
  int ans = 0;
  for (int x1 = 1; x1 <= n; x1++) {
    for (int y1 = 1; y1 <= n; y1++) {
      for (int x2 = x1; x2 <= n; x2++) {
        for (int y2 = 1; y2 <= n; y2++) {
          int tot = 0;
          for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
              tot += a[x][y];
            }
          }
          if (tot >= need) ans++;
        }
      }
    }
  }
  printf("%d\n", ans);
}
