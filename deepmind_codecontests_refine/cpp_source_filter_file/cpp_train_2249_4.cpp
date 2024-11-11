#include <bits/stdc++.h>
using namespace std;
char v[111][111];
int main() {
  int n, m, xl = INT_MAX, xr = -INT_MAX, yu = INT_MAX, yd = -INT_MAX;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf(" %c", &v[i][j]);
      if (v[i][j] == 'B') {
        xl = min(xl, j);
        xr = max(xr, j);
        yu = min(yu, i);
        yd = max(yd, i);
      }
    }
  }
  if (xl == INT_MAX && yu == INT_MAX && xr == -INT_MAX && yd == -INT_MAX) {
    printf("1\n");
    return 0;
  }
  int ans = 0;
  for (int i = yu; i <= yd; i++) {
    for (int j = xl; j <= xr; j++) {
      if (v[i][j] == 'W') {
        ans++;
      }
    }
  }
  if (xr - xl == yd - yu) {
    printf("%d\n", ans);
    return 0;
  }
  int need = abs(yd - yu - (xr - xl));
  if (xr - xl > yd - yu) {
    for (int i = 1; i <= yu; i++) {
      for (int r = m; r >= yd; r--) {
        int dist1 = yu - i;
        int dist2 = yd - r;
        if (dist1 + yd - yu + dist2 == xr - xl) {
          printf("%d\n", ans + (xr - xl + 1) * need);
          return 0;
        }
      }
    }
  } else {
    for (int i = 1; i <= xl; i++) {
      for (int r = m; r >= xr; r--) {
        int dist1 = xl - i;
        int dist2 = xr - r;
        if (dist1 + xr - xl + dist2 == yd - yu) {
          printf("%d\n", ans + (yd - yu + 1) * need);
          return 0;
        }
      }
    }
  }
  printf("-1\n");
  return 0;
}
