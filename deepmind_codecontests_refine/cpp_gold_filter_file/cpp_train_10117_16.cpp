#include <bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int id[500010];
int x[500010];
int y[500010];
int d[701][701];
int main() {
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) scanf("%d%d%d", &id[i], &x[i], &y[i]);
  for (int i = 1; i <= q; i++) {
    if (id[i] == 1) {
      b[x[i]] += y[i];
      for (int j = 1; j <= 700; j++) {
        d[j][x[i] % j] += y[i];
      }
    } else {
      int tmp = 0;
      if (x[i] > 700) {
        for (int j = y[i]; j <= 500000; j += x[i]) {
          tmp += b[j];
        }
      } else {
        tmp = d[x[i]][y[i]];
      }
      printf("%d\n", tmp);
    }
  }
  return 0;
}
