#include <bits/stdc++.h>
int perm[40320][8];
int factorial(int n) { return n == 0 ? 1 : factorial(n - 1) * n; }
void next(int *a, int *b, int n) {
  int i, j, k, imin, min, tmp;
  memcpy(b, a, n * sizeof(*a));
  for (i = n - 1; i >= 1; i--)
    if (b[i - 1] < b[i]) break;
  min = INT_MAX;
  for (j = n - 1; j >= i; j--)
    if (b[j] > b[i - 1] && min > b[j]) {
      imin = j;
      min = b[j];
    }
  tmp = b[i - 1], b[i - 1] = b[imin], b[imin] = tmp;
  for (j = i, k = n - 1; j < k; j++, k--) tmp = b[j], b[j] = b[k], b[k] = tmp;
}
int difference(char a[][9], int *perm, int n, int k) {
  int i, j, min, max, m;
  char s[9];
  max = 0;
  min = INT_MAX;
  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) s[j] = a[i][perm[j]];
    m = atoi(s);
    if (max < m) max = m;
    if (min > m) min = m;
  }
  return max - min;
}
int main() {
  int i, j, n, k, f, mindiff, diff;
  static char aa[8][9];
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) scanf("%s", aa[i]);
  for (i = 0; i < k; i++) perm[0][i] = i;
  f = factorial(k);
  for (i = 1; i < f; i++) next(perm[i - 1], perm[i], k);
  mindiff = INT_MAX;
  for (i = 0; i < f; i++) {
    diff = difference(aa, perm[i], n, k);
    if (mindiff > diff) mindiff = diff;
  }
  printf("%d\n", mindiff);
  return 0;
}
