#include <bits/stdc++.h>
using namespace std;
int a[1][1][1][1], B[401][401][401];
int main() {
  int r, c, n, b, ans = 0;
  memset(B, 42300103, sizeof B);
  scanf("%d%d%d%d", &r, &c, &n, &b);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= x; i++) {
      for (int j = 1; j <= y; j++) {
        for (int k = x; k <= r; k++) {
          for (int l = y; l <= c; l++) {
            a[i][j][k][l]++;
          }
        }
      }
    }
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      for (int k = i; k <= r; k++) {
        for (int l = j; l <= c; l++) {
          if (a[i][j][k][l] >= b) {
            ans++;
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
