#include <bits/stdc++.h>
using namespace std;
int a[100000 + 10];
int main() {
  int n, i, m;
  while (scanf("%d", &n) != EOF) {
    int x, y = 100000;
    for (i = 1; i <= n; i++) {
      scanf("%d", &x);
      y = min(x, y);
    }
    scanf("%d", &m);
    for (i = 1; i <= m; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + m);
    int sum = 0;
    int res = m;
    while (res > y) {
      for (i = res; i > res - y; i--) sum = sum + a[i];
      res = res - y;
      res = res - 2;
    }
    for (i = 1; i <= res; i++) sum = sum + a[i];
    printf("%d\n", sum);
  }
  return 0;
}
