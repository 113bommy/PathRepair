#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005], m, n;
int main() {
  int i, j;
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (i = 1; i <= m; i++) scanf("%d", &b[i]);
    b[0] = 0;
    int maxx = -1111111, ll, rr;
    j = 1;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (i = 1; i <= n; i++) {
      for (; j <= m; j++) {
        if (b[j] >= a[i]) break;
      }
      int l = (i - 1) * 2 + (n - i + 1) * 3;
      int r = (j - 1) * 2 + (m - j + 1) * 3;
      if (maxx < l - r) {
        ll = l;
        rr = r;
        maxx = l - r;
      }
    }
    if (2 * n - 2 * m > maxx) {
      ll = 2 * n;
      rr = 2 * m;
    }
    printf("%d:%d\n", ll, rr);
  }
  return 0;
}
