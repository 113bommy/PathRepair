#include <bits/stdc++.h>
using namespace std;
int n, m, sum, cnt, q[100010], a[100010];
int main() {
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%d", q + i);
  sort(q, q + m);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int i = n - 1;
  sum = 0;
  while (i >= 0) {
    cnt = 0;
    while (i >= 0 and cnt < q[0]) {
      sum += a[i];
      i--;
      cnt++;
    }
    i -= 2;
  }
  printf("%d\n", sum);
  return 0;
}
