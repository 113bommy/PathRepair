#include <bits/stdc++.h>
int n, k;
int v[1005], sol[1005], f[1005];
int main() {
  scanf("%d %d", &n, &k);
  int i, j, ind, nr, l;
  for (i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (i = n; i >= 1; i--) {
    if (v[i]) break;
    for (j = sol[0]; j >= 1; j--) sol[j + 1] = sol[j];
    sol[1] = i;
    sol[0]++;
  }
  for (; i >= 1; i--) {
    nr = 0;
    for (j = 1; j <= sol[0]; j++) {
      if (sol[j] >= i + k) nr++;
      if (nr == v[i]) {
        for (l = sol[0]; l > j; l--) sol[l + 1] = sol[l];
        sol[j + 1] = i;
        sol[0]++;
        break;
      }
    }
  }
  for (i = 1; i <= n; i++) printf("%d ", sol[i]);
  return 0;
}
