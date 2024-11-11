#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, p;
int can[10004][2];
int main() {
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p);
  for (int i = 0; i < p; ++i) {
    scanf("%d%d", &can[i][0], &can[i][1]);
  }
  x %= 4;
  y %= 2;
  z %= 4;
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < p; ++j) {
      int ti, tj;
      ti = can[j][1];
      tj = n - can[j][0] + 1;
      can[j][0] = ti;
      can[j][1] = tj;
    }
    int tmp = n;
    n = m;
    m = tmp;
  }
  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < p; ++j) {
      int ti, tj;
      ti = can[j][0];
      tj = m - can[j][1] + 1;
      can[j][0] = ti;
      can[j][1] = tj;
    }
  }
  for (int i = 0; i < z; ++i) {
    for (int j = 0; j < p; ++j) {
      int ti, tj;
      ti = n - can[j][1] + 1;
      tj = can[j][0];
      can[j][0] = ti;
      can[j][1] = tj;
    }
    int tmp = n;
    n = m;
    m = tmp;
  }
  for (int i = 0; i < p; ++i) {
    printf("%d %d\n", can[i][0], can[i][1]);
  }
  return 0;
}
