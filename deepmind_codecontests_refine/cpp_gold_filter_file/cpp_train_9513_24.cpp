#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  int T, i, j, k, x, y, t;
  while (~scanf("%d%d", &n, &m)) {
    if (m == 3) {
      if (n == 3) {
        printf("0 0\n0 1\n1 1\n");
        continue;
      }
      if (n == 4) {
        printf("-1 0\n1 0\n0 1\n0 2\n");
        continue;
      }
      puts("-1");
      continue;
    }
    for (i = 1; i <= m; i++) printf("%d %d\n", i, -(n - i) * (n - i));
    for (i = 1; i <= n - m; i++) printf("%d %d\n", -i, (n - i) * (n - i));
  }
  return 0;
}
