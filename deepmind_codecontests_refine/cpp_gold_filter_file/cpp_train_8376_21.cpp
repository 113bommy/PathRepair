#include <bits/stdc++.h>
using namespace std;
int a[400][400], o, b[310];
void scan() {
  scanf("%d", &o);
  for (int i = 0; i < o; i++) scanf("%d", &b[i]);
}
void out() {
  int p = 1, n;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < o; i++) {
    int e = b[i];
    n = 0;
    if (a[i][p - 1] < e) {
      if ((e - a[i][p - 1] - 1) > (9 * (p - 1))) {
        while (e) {
          a[i + 1][n++] = min(e, 9);
          e -= min(e, 9);
        }
      } else {
        n = p;
        int u = 0, pos = -1;
        for (int j = p - 1; j >= 0; j--) {
          if ((b[i] - u - a[i][j]) > 0 && ((j + 1) * 9) >= (e - u)) {
            u += a[i][j];
            if (a[i][j] != 9) pos = j;
          } else
            break;
        }
        if (pos != -1) {
          if (b[i] <= b[i - 1]) {
            a[i + 1][pos] = a[i][pos] + 1;
            u = a[i][pos] + 1;
            for (int j = p - 1; j >= pos + 1; j--) {
              a[i + 1][j] = a[i][j];
              u += a[i][j];
            }
            u = e - u;
            for (int j = 0; j < pos; j++) {
              a[i + 1][j] = min(u, 9);
              u -= a[i + 1][j];
            }
          } else {
            a[i + 1][pos] = a[i][pos];
            u = a[i][pos];
            for (int j = p - 1; j >= pos + 1; j--) {
              a[i + 1][j] = a[i][j];
              u += a[i][j];
            }
            u = e - u;
            for (int j = 0; j < pos; j++) {
              a[i + 1][j] = min(u, 9);
              u -= a[i + 1][j];
            }
            a[i + 1][pos] += u;
          }
        } else {
          a[i + 1][p] = 1;
          u = b[i] - 1;
          for (int j = 0;; j++) {
            a[i + 1][j] = min(u, 9);
            u -= min(u, 9);
            if (u == 0) break;
          }
          ++n;
        }
      }
    } else {
      a[i + 1][p] = 1;
      a[i + 1][0] = e - 1;
      n = p + 1;
    }
    p = n;
    for (int j = n - 1; j >= 0; j--) cout << a[i + 1][j];
    cout << '\n';
  }
}
int main() {
  scan();
  out();
  return 0;
}
