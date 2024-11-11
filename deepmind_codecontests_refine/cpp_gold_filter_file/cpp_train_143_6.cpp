#include <bits/stdc++.h>
using namespace std;
struct Query {
  int t, l, r, x;
};
int n, m;
int incr[5555];
long long a[5555], b[5555];
Query q[5555];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) a[i] = 1e9;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &q[i].t, &q[i].l, &q[i].r, &q[i].x);
    if (q[i].t == 1)
      for (int j = q[i].l; j <= q[i].r; j++) incr[j] += q[i].x;
    else
      for (int j = q[i].l; j <= q[i].r; j++)
        a[j] = min(a[j], (long long)q[i].x - incr[j]);
  }
  for (int i = 1; i <= n; i++) b[i] = a[i];
  for (int i = 1; i <= m; i++) {
    if (q[i].t == 1)
      for (int j = q[i].l; j <= q[i].r; j++) a[j] += q[i].x;
    else {
      long long m = -1e18;
      for (int j = q[i].l; j <= q[i].r; j++) m = max(m, a[j]);
      if (m != q[i].x) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%I64d ", b[i]);
  return 0;
}
