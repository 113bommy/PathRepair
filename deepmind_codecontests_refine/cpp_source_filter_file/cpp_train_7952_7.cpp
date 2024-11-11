#include <bits/stdc++.h>
int compare(const void *a, const void *b) { return (*(int *)a, *(int *)b); }
int main() {
  int n, m, i, j, k, cnt = 1;
  scanf("%d %d", &n, &m);
  int a[m * 2];
  for (i = 0; i < m * 2; i++) {
    scanf("%d", &a[i]);
  }
  qsort(a, m * 2, sizeof(int), compare);
  for (i = 0; i < m * 2; i++) {
    if (a[i] == cnt) {
      cnt++;
    }
  }
  printf("%d\n", n - 1);
  for (i = 1; i <= n; i++) {
    if (i != cnt) {
      printf("%d %d\n", i, cnt);
    }
  }
  return 0;
}
