#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int x[128], y[128], w[128];
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    scanf("%d%d", x + i, y + i), w[i] = i, x[i + n] = y[i], y[i + n] = x[i],
                                 w[i + n] = i;
  n *= 2;
  int r = 0;
  for (int i = 0, ThxDem = n; i < ThxDem; ++i)
    for (int j = i + 1, ThxDem = n; j < ThxDem; ++j)
      if (w[i] != w[j]) {
        if (max(x[i], x[j]) <= a && max(y[i], y[j]) <= b)
          if (x[i] + x[j] <= a || y[i] + y[j] <= b)
            r = max(r, x[i] * y[i] + x[j] * y[j]);
      }
  printf("%d\n", r);
  return 0;
}
