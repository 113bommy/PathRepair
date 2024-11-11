#include <bits/stdc++.h>
int d[1005][11];
int main() {
  int n, k, e = 1;
  scanf("%d%d", &n, &k);
  for (int p = k; p < n; p *= k, ++e)
    ;
  printf("%d\n", e);
  for (int i = 1; i <= n; ++i)
    for (int j = 0, t = i - 1; j < e; ++j) d[i][j] = t % k, t /= k;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      for (int k = e - 1; k >= 0; --k)
        if (d[i][k] != d[j][k]) {
          printf("%d ", k + 1);
          break;
        }
    }
  puts("");
  return 0;
}
