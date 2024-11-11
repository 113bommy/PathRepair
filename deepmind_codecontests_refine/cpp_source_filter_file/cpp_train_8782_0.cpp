#include <bits/stdc++.h>
using namespace std;
int i, n, m, q[10004], a[10004];
long long maxs;
int main() {
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d", &q[i]);
  }
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    maxs += a[i];
  }
  sort(q + 1, q + m + 1);
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  for (i = 1; i <= n; i++) {
    if ((i - 1) % (q[1] + 2) == q[1] + 1) {
      maxs -= a[i];
    }
    if ((i - 1) % (q[1] + 2) == q[1]) {
      maxs -= a[i];
    }
  }
  printf("%I64d\n", maxs);
}
