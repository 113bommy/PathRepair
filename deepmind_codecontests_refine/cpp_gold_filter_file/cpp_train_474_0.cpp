#include <bits/stdc++.h>
int v[100000];
int main() {
  int n, k, i, z = 0, d = 0;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  for (i = 0; i < n; i++) {
    z += v[i] / (2 * k);
    v[i] %= 2 * k;
    if (v[i] / k + (v[i] % k > 0) > 1) {
      z++;
      v[i] = 0;
    }
  }
  for (i = 0; i < n; i++)
    if (v[i]) d++;
  z += d / 2 + (d % 2 > 0);
  printf("%d\n", z);
  return 0;
}
