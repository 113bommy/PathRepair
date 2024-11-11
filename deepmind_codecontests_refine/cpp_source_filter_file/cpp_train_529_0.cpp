#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, m, n, t, start[200000], end[120000], a, l;
  scanf("%d %d %d", &n, &l, &a);
  for (i = 0; i < n; i++) scanf("%d %d", &start[i], &end[i]);
  if (n == 0) {
    k = l / a;
    printf("%d\n", k);
    return 0;
  } else if (n == 1) {
    k = start[0] / a;
    k += (l - end[0] - start[0]) / a;
    printf("%d\n", k);
    return 0;
  }
  j = 0;
  for (i = 0; i < n; i++) {
    k += (start[i] - j) / a;
    j = end[i] + start[i];
  }
  j = l - (start[n - 1] + end[n - 1]);
  k += j / a;
  printf("%d\n", k);
  return 0;
}
