#include <bits/stdc++.h>
using namespace std;
bool mat[12][12];
int main() {
  int r, c, n, k, a, b, d, i, e, j, x, y;
  scanf("%d", &r);
  scanf("%d", &c);
  scanf("%d", &n);
  scanf("%d", &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    scanf("%d", &y);
    mat[x - 1][y - 1] = 1;
  }
  int cnt = 0;
  int ans = 0;
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      for (a = j; a < c; a++) {
        for (b = i; b < r; b++) {
          cnt = 0;
          for (c = i; c < b + 1; c++) {
            for (d = j; d < a + 1; d++) {
              if (mat[c][d] == 1) cnt++;
            }
          }
          if (cnt >= k) {
            ans++;
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
