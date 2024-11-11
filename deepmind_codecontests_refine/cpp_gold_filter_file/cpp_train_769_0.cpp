#include <bits/stdc++.h>
using namespace std;
int a[500005], n;
int check(int m) {
  int i;
  for (i = 1; i <= m; i++)
    if (2 * a[i] > a[n - m + i]) return 0;
  return 1;
}
int main() {
  int i, l, r, m;
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    l = 1, r = n / 2;
    while (l <= r) {
      m = (l + r) >> 1;
      if (check(m))
        l = m + 1;
      else
        r = m - 1;
    }
    printf("%d\n", n - r);
  }
  return 0;
}
