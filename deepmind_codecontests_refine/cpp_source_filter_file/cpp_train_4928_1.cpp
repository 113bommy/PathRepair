#include <bits/stdc++.h>
int s[2005];
int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int main() {
  int n, a, b, i;
  while (scanf("%d %d %d", &n, &a, &b) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &s[i]);
    qsort(s, n, sizeof(s[0]), cmp);
    printf("%d\n", s[a - 1] - s[b - 1]);
  }
  return 0;
}
