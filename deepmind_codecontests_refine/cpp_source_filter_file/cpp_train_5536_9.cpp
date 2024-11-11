#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long q, x, y;
long long a[200001];
long long op[200001], lst[200001];
long long maxn;
int main() {
  maxn = 0;
  memset(lst, 0, sizeof(lst));
  memset(op, 0, sizeof(op));
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  scanf("%lld", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%lld", &q);
    if (q == 1) {
      scanf("%lld%lld", &x, &y);
      a[x] = y;
      lst[x] = i;
    } else {
      scanf("%lld", &x);
      op[i] = x;
    }
  }
  for (int i = q; i >= 0; i--) {
    op[i] = max(op[i], op[i + 1]);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] < op[lst[i] + 1]) {
      a[i] = op[lst[i] + 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != n)
      printf("%d ", a[i]);
    else
      printf("%d\n", a[i]);
  }
  return 0;
}
