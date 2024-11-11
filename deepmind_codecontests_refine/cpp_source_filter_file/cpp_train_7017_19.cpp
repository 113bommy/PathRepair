#include <bits/stdc++.h>
int er[100005], dac[100005][3];
void fp(int val, int i1, int i2) {
  if (val == 1) {
    er[i1] = 2;
    er[i2] = 3;
  } else if (val == 2) {
    er[i1] = 1;
    er[i2] = 3;
  } else if (val == 3) {
    er[i1] = 2;
    er[i2] = 1;
  }
}
int main() {
  int m, n;
  int i, j, k, t0, t1, t2;
  while (scanf("%d%d", &m, &n) != EOF) {
    for (i = 1; i <= n; i++)
      scanf("%d%d%d", &dac[i][0], &dac[i][1], &dac[i][2]);
    memset(er, -1, sizeof(er));
    for (i = 1; i <= n; i++) {
      t0 = dac[i][0];
      t1 = dac[i][1];
      t2 = dac[i][2];
      if (er[t0] > 0)
        fp(er[t0], t1, t2);
      else if (er[t1] > 0)
        fp(er[t1], t0, t2);
      else if (er[t2] > 0)
        fp(er[t2], t1, t2);
      else {
        er[t0] = 1;
        er[t1] = 2;
        er[t2] = 3;
      }
    }
    for (i = 1; i <= m; i++) printf("%d ", er[i]);
    printf("\n");
  }
  return 0;
}
