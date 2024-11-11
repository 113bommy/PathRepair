#include <bits/stdc++.h>
int main() {
  int n, m, A[100005], i, cas, pos, val, y, Y = 0;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &A[i]);
  while (m--) {
    scanf("%d", &cas);
    if (cas == 1) {
      scanf("%d %d", &pos, &val);
      A[pos] = val;
    } else if (cas == 2) {
      scanf("%d", &y);
      Y += y;
    } else {
      scanf("%d", &pos);
      printf("%d\n", A[pos] + Y);
    }
  }
  return 0;
}
