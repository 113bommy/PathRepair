#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3ffffff;
const int MAXN = 100005;
int a[MAXN];
int main() {
  int m, n, q, minq;
  minq = INF;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &q);
    if (minq > q) minq = q;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  reverse(a, a + n);
  int i = 0;
  int ans = 0;
  while (i < n) {
    if (q <= n - i) {
      for (int k = 0; k < q; k++, i++) ans += a[i];
      for (int k = 0; k < 2 && i < n; i++, k++)
        ;
    } else
      for (; i < n; i++) ans += a[i];
  }
  printf("%d\n", ans);
  return 0;
}
