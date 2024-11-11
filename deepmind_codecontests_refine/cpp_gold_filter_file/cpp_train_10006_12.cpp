#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;
int n, m, k, t;
int main() {
  int i, j;
  scanf("%d", &n);
  int x = 0, y = 0;
  for (i = 1; i <= n; i++) {
    printf("%d %d\n", x, y);
    if (i % 3 == 1)
      x++;
    else if (i % 3 == 2)
      y += 3;
    else
      x++, y -= 3;
  }
  return 0;
}
