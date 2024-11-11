#include <bits/stdc++.h>
using namespace std;
struct v {
  int i, n, x;
} a[111111];
bool cmp(v a, v b) { return a.n < b.n; }
bool cmp1(v a, v b) { return a.i < b.i; }
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
int main() {
  int i, j, n, k, h;
  while (~scanf("%d%d", &n, &h)) {
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i].n);
      a[i].i = i;
      a[i].x = 2;
    }
    if (n == 2) {
      printf("1 1\n");
      continue;
    }
    sort(a + 1, a + n + 1, cmp);
    a[1].x = 1;
    int ma, mi;
    ma = max(a[n].n + a[n - 1].n, a[1].n + a[n].n + h);
    mi = min(a[1].n + a[2].n + h, a[2].n + a[3].n);
    ma = ma - mi;
    if (a[n].n + a[n - 1].n - a[1].n - a[2].n < ma) {
      ma = a[n].n + a[n - 1].n - a[1].n - a[2].n;
      a[1].x = 2;
    }
    printf("%d\n", ma);
    sort(a + 1, a + n + 1, cmp1);
    for (i = 1; i <= n; i++) printf("%d ", a[i].x);
    printf("\n");
  }
  return 0;
}
