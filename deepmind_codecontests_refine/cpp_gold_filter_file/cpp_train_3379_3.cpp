#include <bits/stdc++.h>
int main(void) {
  int n, np, nq, *p, *q, flag = 0, i;
  scanf("%d", &n);
  scanf("%d", &np);
  p = (int*)calloc(np, sizeof(int));
  for (i = 0; i < np; i++) scanf("%d", &p[i]);
  scanf("%d", &nq);
  q = (int*)calloc(nq, sizeof(int));
  for (i = 0; i < nq; i++) scanf("%d", &q[i]);
  for (i = 1; i <= n; i++) {
    for (int j = 0; j < np; j++) {
      if (p[j] == i) {
        flag = 1;
        break;
      }
    }
    if (flag != 1)
      for (int j = 0; j < nq; j++)
        if (q[j] == i) {
          flag = 1;
          break;
        }
    if (flag != 1) {
      printf("Oh, my keyboard!");
      return 0;
    }
    flag = 0;
  }
  printf("I become the guy.");
}
