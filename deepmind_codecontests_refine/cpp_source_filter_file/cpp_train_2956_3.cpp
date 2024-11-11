#include <bits/stdc++.h>
int n, m;
int v;
int c, t;
struct node {
  int s, f;
} a[10005];
int main() {
  int i, l, r, mid;
  a[0].s = 0;
  a[0].f = 0;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &c, &t);
    a[i].s = a[i - 1].f + 1;
    a[i].f = a[i - 1].f + c * t;
  }
  for (i = 1; i <= m; i++) {
    scanf("%d", &v);
    l = 1;
    r = n;
    while (l <= r) {
      mid = (l + r) / 2;
      if (v < a[mid].s) {
        r = mid - 1;
      } else if (a[mid].s <= v && v <= a[mid].f) {
        printf("%d\n", mid);
        break;
      } else {
        l = mid + 1;
      }
    }
  }
  return 0;
}
