#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
  int n, m, k, i, j, r, c;
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    for (i = 1; i <= m; i++) a[i] = 0x3ffff;
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &r, &c);
      a[r] = min(a[r], c);
    }
    int sum = 0;
    for (i = 1; i <= m; i++) sum += a[i];
    printf("%d\n", min(k, sum));
  }
  return 0;
}
