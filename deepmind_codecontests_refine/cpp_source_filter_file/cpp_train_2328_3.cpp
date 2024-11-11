#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, v, i, j;
  scanf("%d%d%d", &n, &m, &v);
  if (m > (n * n - 3 * n + 4) / 2 || m < n - 1)
    printf("-1\n");
  else {
    int last;
    for (i = 1; i <= n; i++)
      if (i != v) {
        printf("%d %d\n", i, v);
        m--;
        last = i;
      }
    for (i = 1; i < last && m; i++)
      for (j = i + 1; j <= last && m; j++)
        if (i != v && j != v) {
          printf("%d %d\n", i, j);
          m--;
        }
  }
  return 0;
}
