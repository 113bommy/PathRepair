#include <bits/stdc++.h>
int intcmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main() {
  int n, m, min, max, i, md[100], p;
  scanf("%d%d%d%d", &n, &m, &min, &max);
  for (i = 0; i < m; i++) {
    scanf("%d", &md[i]);
  }
  qsort(md, n, sizeof(int), intcmp);
  if (min <= md[0] && md[i - 1] <= max) {
    if (min == md[0] && md[i - 1] == max)
      p = 1;
    else {
      if (n - m >= 2)
        p = 1;
      else {
        if (n - m == 1 && (min == md[0] || md[i - 1] == max))
          p = 1;
        else
          p = 0;
      }
    }
  } else
    p = 0;
  if (p)
    printf("Correct\n");
  else
    printf("Incorrect\n");
  return 0;
}
