#include <bits/stdc++.h>
using namespace std;
const int N = 500002;
int n, x, i, o, a[N], q[N], p[N], y, ok;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; i++) {
    x = a[i];
    for (y = 1; y < N; y <<= 1) {
      if (x & y) {
        if (!q[y]) {
          q[y] = x;
          p[y] = a[i];
          break;
        } else
          x ^= q[y];
      }
    }
  }
  for (o = 18; o >= 0; o--) {
    ok = 1;
    for (i = 0; i < o; i++)
      if (!p[1 << i] || p[1 << i] >= 1 << o) ok = 0;
    if (ok) {
      printf("%d\n", o);
      i = 0;
      x = 0;
      while (i < 1 << o) {
        i++;
        printf("%d ", x);
        x ^= p[i & -i];
      }
      return 0;
    }
  }
}
