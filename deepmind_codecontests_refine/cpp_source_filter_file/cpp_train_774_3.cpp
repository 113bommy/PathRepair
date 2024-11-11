#include <bits/stdc++.h>
int b[102];
int g[102];
int n, m;
int used[102] = {0};
int difference(int a, int b) { return abs(a - b); }
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int cmp(const void* ap, const void* bp) {
  if (*(int*)ap > *(int*)bp)
    return 1;
  else if (*(int*)ap == *(int*)bp)
    return 0;
  else
    return -1;
}
int main() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d", &b[i]);
  scanf("%d", &m);
  for (i = 0; i < m; ++i) scanf("%d", &g[i]);
  qsort(b, n, sizeof(int), cmp);
  qsort(g, m, sizeof(int), cmp);
  int j, k;
  int count = 0;
  int maxi = 0;
  for (k = 0; k < n; ++k) {
    for (j = 0; j < m; ++j) {
      if ((difference(g[j], b[i]) <= 1) && (used[j] != 1)) {
        used[j] = 1;
        ++count;
        break;
      }
    }
    for (i = 0; i < n; ++i) {
      if (i == k) continue;
      for (j = 0; j < m; ++j) {
        if ((difference(g[j], b[i]) <= 1) && (used[j] != 1)) {
          used[j] = 1;
          ++count;
          break;
        }
      }
    }
    maxi = max(maxi, count);
    count = 0;
    memset(used, 0, sizeof(used));
  }
  printf("%d\n", maxi);
  return 0;
}
