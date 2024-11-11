#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, l, a[1000009], b[1000009], p[1000009], ans, cn, t, x, y, z,
    mx, mn, s;
char c[1000009], d[1000009], ch;
int main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    memset(b, 0, sizeof(b));
    mn = (1 << 30);
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      x = max(1, a[i] - k);
      b[x] += 1;
      b[a[i] + 1] -= 1;
      mn = min(mn, a[i]);
    }
    for (i = 1; i < 1000009; i++) {
      b[i] += b[i - 1];
    }
    for (i = mn; i >= 1; i--) {
      z = 0;
      for (j = i; j < 1000009; j += i) {
        z += b[j];
      }
      if (z == n) {
        ans = i;
        break;
      }
    }
    ans = i;
    printf("%d\n", ans);
  }
  return 0;
}
