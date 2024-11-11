#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, t, n, m, i, j, k, a, b, c, d;
  scanf("%d%d", &n, &k);
  printf("%d\n", (n * 6 - 1) * k);
  for (i = 1; i <= n; i++) {
    a = ((i - 1) * 3 + 1) * 2 - 1;
    b = ((i - 1) * 3 + 2) * 2 - 1;
    c = ((i - 1) * 3 + 3) * 2 - 1;
    d = a + 1;
    printf("%d %d %d %d\n", a * k, b * k, c * k, d * k);
  }
}
