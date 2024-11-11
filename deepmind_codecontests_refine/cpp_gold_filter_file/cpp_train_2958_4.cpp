#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  while (scanf("%d %d", &n, &m) != EOF) {
    int a[n], b[m];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + m);
    if ((2 * a[0] < b[0]) && (a[n - 1] < b[0]))
      printf("%d\n", max(a[n - 1], 2 * a[0]));
    else
      printf("-1\n");
  }
  return 0;
}
