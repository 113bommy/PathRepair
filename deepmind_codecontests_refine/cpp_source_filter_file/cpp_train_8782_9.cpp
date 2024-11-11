#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, m, n, q[100001], a[100001];
  scanf("%d", &m);
  for (i = 0; i < m; i++) scanf("%d", &q[i]);
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(q, q + m);
  sort(a, a + n);
  int sum = 0;
  for (i = n - 1; i >= 0; i--) {
    int cnt = q[0];
    if (cnt >= i) {
      sum += a[i];
      continue;
    }
    while (cnt--) sum += a[i--];
    i--;
  }
  printf("%d", sum);
  return 0;
}
