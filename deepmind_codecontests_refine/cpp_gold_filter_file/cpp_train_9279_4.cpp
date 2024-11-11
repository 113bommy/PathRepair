#include <bits/stdc++.h>
int main() {
  long long x, n, y;
  while (~scanf("%I64d %I64d %I64d", &n, &x, &y)) {
    if (n > y)
      puts("-1");
    else {
      if ((y - n + 1) * (y - n + 1) + n - 1 < x)
        puts("-1");
      else {
        for (int i = 1; i <= n - 1; ++i) puts("1");
        printf("%d\n", y - n + 1);
      }
    }
  }
  return 0;
}
