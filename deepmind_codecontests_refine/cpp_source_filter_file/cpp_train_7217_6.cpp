#include <bits/stdc++.h>
using namespace std;
int n;
float a[18][18], f[1 << 18];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%f", &a[i][j]);
  f[(1 << n) - 1] = 1;
  for (int i = (1 << n) - 1; i; i--)
    for (int u = 0; u < n; u++)
      if (i & (1 << u))
        for (int v = u + 1; v < n; v++)
          if (i & (1 << v))
            f[i ^ (1 << v)] +=
                f[i] * a[u][v] /
                (__builtin_popcount(i) * (__builtin_popcount(i) - 1) * .5),
                f[i ^ (1 << u)] +=
                f[i] * a[v][u] /
                (__builtin_popcount(i) * (__builtin_popcount(i) - 1) * .5);
  for (int i = 0; i < n; i++) printf("%.6f ", f[1 << i]);
  puts("");
  return 0;
}
