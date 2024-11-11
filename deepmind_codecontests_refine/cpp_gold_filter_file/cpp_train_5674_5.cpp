#include <bits/stdc++.h>
int count[103];
int main() {
  int n, m, i, j, ans, x;
  long long int max, v;
  scanf("%d %d", &n, &m);
  max = 0;
  for (i = 0; i < m; i++) {
    max = -1;
    for (j = 0; j < n; j++) {
      scanf("%I64d", &v);
      if (v > max) {
        max = v;
        x = j;
      }
    }
    count[x]++;
  }
  max = -1;
  for (i = 0; i < n; i++) {
    if (count[i] > max) {
      max = count[i];
      ans = i + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
