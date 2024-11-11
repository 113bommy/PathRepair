#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) != EOF) {
    getchar();
    char a[200][200];
    int i, j, t, flag1 = 2, flag2 = 2;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%c", &a[i][j]);
      }
      getchar();
    }
    if (m % 3 == 0) {
      if (a[0][0] != a[n / 3][0] && a[0][0] != a[n / 3 * 2][0] &&
          a[n / 3][0] != a[n / 3 * 2][0]) {
        flag1 = 0;
        for (i = 0; i < 3; i++) {
          for (j = 0; j < n / 3; j++) {
            for (t = 0; t < m; t++) {
              if (a[j + i * n / 3][t] != a[i * n / 3][0]) flag1 = 1;
            }
          }
        }
      }
    }
    if (n % 3 == 0) {
      if (a[0][0] != a[0][m / 3] && a[0][0] != a[0][m / 3 * 2] &&
          a[0][m / 3] != a[0][m / 3 * 2]) {
        flag2 = 0;
        for (i = 0; i < 3; i++) {
          for (j = 0; j < m / 3; j++) {
            for (t = 0; t < n; t++) {
              if (a[t][j + i * m / 3] != a[0][i * m / 3]) flag2 = 1;
            }
          }
        }
      }
    }
    if (flag1 == 0 || flag2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
