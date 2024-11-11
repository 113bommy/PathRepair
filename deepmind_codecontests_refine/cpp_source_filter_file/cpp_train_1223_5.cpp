#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int a[N][2], b[N][2], c[N][2], d[N][2];
int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < m; i++) cin >> b[i][0] >> b[i][1];
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
      if (a[i][0] > a[i][1]) swap(a[i][0], a[i][1]);
      for (int j = 0; j < m; j++) {
        if (b[j][0] > b[j][1]) swap(b[j][0], b[j][1]);
        if (b[j][0] == a[i][0] && b[j][1] == a[i][1]) continue;
        if (b[j][0] == a[i][0]) {
          c[i][0] = 1;
          d[j][0] = 1;
        }
        if (b[j][0] == a[i][1]) {
          c[i][1] = 1;
          d[j][0] = 1;
        }
        if (b[j][1] == a[i][0]) {
          c[i][0] = 1;
          d[j][1] = 1;
        }
        if (b[j][1] == a[i][1]) {
          c[i][1] = 1;
          d[j][1] = 1;
        }
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (c[i][0] == 1 && c[i][1] == 1) {
        res = -1;
        break;
      } else if (c[i][0] == 1) {
        if (res != 0 && res != a[i][0]) {
          res = 0;
          break;
        }
        res = a[i][0];
      } else if (c[i][1] == 1) {
        if (res != 0 && res != a[i][1]) {
          res = 0;
          break;
        }
        res = a[i][1];
      }
    }
    if (res >= 0)
      for (int i = 0; i < m; i++) {
        if (d[i][0] == 1 && d[i][1] == 1) {
          res = -1;
          break;
        } else if (d[i][0] == 1) {
          if (res != 0 && res != b[i][0]) {
            res = 0;
            break;
          }
          res = b[i][0];
        } else if (d[i][1] == 1) {
          if (res != 0 && res != b[i][1]) {
            res = 0;
            break;
          }
          res = d[i][1];
        }
      }
    printf("%d\n", res);
  }
}
