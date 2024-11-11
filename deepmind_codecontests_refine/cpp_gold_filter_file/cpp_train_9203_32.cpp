#include <bits/stdc++.h>
using namespace std;
int a[4][2], b[4][2], sum[4];
int main() {
  int n, t, j, k;
  while (scanf("%d", &n) != EOF) {
    k = -1;
    for (j = 0; j < 4; ++j) {
      scanf("%d%d%d%d", &a[j][0], &b[j][0], &a[j][1], &b[j][1]);
      sum[j] = min(a[j][0], b[j][0]) + min(a[j][1], b[j][1]);
      if (n >= sum[j]) {
        k = j + 1;
        t = j;
      }
    }
    if (k == -1) {
      printf("%d\n", k);
      continue;
    }
    printf("%d %d %d\n", k, min(a[t][0], b[t][0]), n - min(a[t][0], b[t][0]));
  }
  return 0;
}
