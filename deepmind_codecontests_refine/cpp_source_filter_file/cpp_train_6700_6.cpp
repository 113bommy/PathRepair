#include <bits/stdc++.h>
using namespace std;
char cs[10005];
int n, m;
int mi[105][10005];
int main() {
  int i, j, k, t1, t2, t3;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 0; i != n; ++i)
      for (j = 0; j != m; ++j) mi[i][j] = 99999;
    for (i = 0; i != n; ++i) {
      scanf("%s", cs);
      for (j = 0; j != m; ++j) {
        if (cs[j] == '1') mi[i][j] = 0;
      }
      for (j = 0; j != m * 2; ++j) {
        if (mi[i][(j + 1) % m] > mi[i][j % m] + 1) {
          mi[i][(j + 1) % m] = mi[i][j % m] + 1;
        }
      }
      for (j = m * 2 - 1; j != -1; --j) {
        if (mi[i][(j - 1 + m) % m] > mi[i][j % m] + 1) {
          mi[i][(j - 1 + m) % m] = mi[i][j % m] + 1;
        }
      }
    }
    t3 = 9999999;
    for (j = 0; j != m; ++j) {
      t2 = 0;
      for (i = 0; i != n; ++i) {
        if (mi[i][j] == 9999999) break;
        t2 += mi[i][j];
      }
      if (i != n) break;
      if (t2 < t3) t3 = t2;
    }
    if (j != m) {
      printf("-1\n");
    } else {
      printf("%d\n", t3);
    }
  }
  return 0;
}
