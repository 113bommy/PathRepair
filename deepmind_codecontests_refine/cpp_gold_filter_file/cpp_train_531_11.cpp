#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, l, a, b, c, d, e, f, g, h, arr[101][101], x;
int main() {
  scanf("%d %d", &n, &m);
  x = (m + 1) / 2;
  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    l = 0;
    j = 0;
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    for (a = 1; a <= m; a++) {
      for (b = 1; b <= m - k + 1; b++) {
        d = 0;
        h = 0;
        for (c = b; c < b + k; c++) {
          if (arr[a][c] == 1) {
            d = 1;
            break;
          }
          h += (abs(a - x)) + (abs(c - x));
        }
        if (d == 0 && c == b + k) {
          if (l == 0) {
            l = 1;
            e = h;
            f = b;
            g = a;
          } else if (h < e) {
            e = h;
            f = b;
            g = a;
          }
        }
      }
    }
    if (l == 0)
      printf("-1\n");
    else {
      printf("%d %d %d\n", g, f, f + k - 1);
      for (a = f; a < f + k; a++) arr[g][a] = 1;
    }
  }
}
