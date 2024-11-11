#include <bits/stdc++.h>
int main() {
  int i, n, m, ary[5][2] = {{0, 100}, {0, 0}, {100, 0}, {1, 1}, {1, 2}};
  scanf("%d%d", &n, &m);
  if (m == 3) {
    if (n == 6) {
      puts("-1");
    } else {
      for (m = 0; m < n; m++) printf("%d %d\n", ary[m][0], ary[m][1]);
    }
    return 0;
  }
  int X = 10000;
  for (i = 0; i < m; i++) printf("%d %d\n", i, i * i + X);
  for (i = 0; i < n - m; i++) printf("%d %d\n", i, -X - i * i);
}
