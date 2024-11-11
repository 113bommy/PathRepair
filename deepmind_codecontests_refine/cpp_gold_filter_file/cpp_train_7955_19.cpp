#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m;
inline void pr(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
inline void pri(int x, int y) { printf("%d %d\n", x, y); }
int main() {
  scanf("%d", &n);
  if (n == 5) {
    pr(1, 3, 1), pr(1, 2, 2), pr(2, 4, 1), pr(4, 5, 1);
    pri(3, 4), pri(3, 5);
    return 0;
  }
  m = n / 2;
  for (i = 1; i <= m; i++) pr(i, i + m, 1);
  pr(m + 1, m + 2, 1);
  for (i = 2; i <= m - 1; i++) pr(i + m, i + m + 1, i + 1);
  if (n & 1) pr(n - 1, n, 1);
  pri(2, 3);
  for (i = 2; i <= m; i++) pri(1, i);
  return 0;
}
