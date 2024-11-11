#include <bits/stdc++.h>
int main() {
  int *N;
  int i, j, n, m, count;
  scanf("%d%d", &n, &m);
  N = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  int tmp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (N[j] < N[i]) {
        tmp = N[j];
        N[j] = N[i];
        N[i] = tmp;
      }
    }
  }
  count = 0;
  for (i = 0; i < n; i++) {
    m = m - N[i];
    count++;
    if (m <= 0) break;
  }
  printf("%d", count);
  return 0;
}
