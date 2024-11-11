#include <bits/stdc++.h>
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main() {
  int n, k, l, c, d, p, nl, np;
  int s[3];
  int j;
  while (scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np) != EOF) {
    j = 0;
    int t1 = k * l / nl;
    int t2 = c * d;
    int t3 = p / np;
    s[j++] = t1;
    s[j++] = t2;
    s[j++] = t3;
    qsort(s, j, sizeof(s[0]), cmp);
    printf("%d\n", s[0] / n);
  }
  return 0;
}
