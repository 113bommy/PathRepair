#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}
int main() {
  int n, m;
  int a[100005], b[100005], c[100005];
  int x, y, z, l, e, d, mi;
  int max = 0;
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  for (i = n; i < m + n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  for (i = 0; i < n; i++) {
    for (j = n; j < m + n; j++) {
      if (a[j] <= a[i] && a[i] <= a[j] + c[j] && b[i] <= b[j] &&
          b[j] <= b[i] + c[i]) {
        x = abs(b[i] - b[j] + c[i]);
        y = abs(b[i] - b[j]);
        z = abs(a[i] - a[j]);
        l = abs(a[i] - a[j] + c[j]);
        e = min(x, y);
        d = min(l, z);
        mi = min(d, e);
        if (max < mi) max = mi;
      }
    }
  }
  printf("%d", max);
  return 0;
}
