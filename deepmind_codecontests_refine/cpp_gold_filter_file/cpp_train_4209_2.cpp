#include <bits/stdc++.h>
int a[110];
int f[110];
int main() {
  int n, k, i, j;
  while (scanf("%d%d", &n, &k) != EOF) {
    memset(f, 0, sizeof(f));
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == 1) f[i % k]++;
    }
    int ans = 0;
    int z = n / k;
    int min;
    for (i = 0; i < k; i++) {
      min = f[i] < (z - f[i]) ? f[i] : (z - f[i]);
      ans += min;
    }
    printf("%d\n", ans);
  }
  return 0;
}
