#include <bits/stdc++.h>
int main() {
  int d, e, f, i, j, k, m, c1, c2, flag, n, a[200001], b[200001];
  scanf("%d %d", &n, &m);
  c1 = 0;
  c2 = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1)
      c1++;
    else
      c2++;
  }
  for (i = 0; i < m; i++) {
    scanf("%d %d", &e, &f);
    b[i] = f - e + 1;
  }
  for (i = 0; i < m; i++) {
    if ((b[i] % 2) != 0)
      printf("0\n");
    else {
      k = b[i] / 2;
      if ((c1 >= k) && (c2 >= k))
        printf("1\n");
      else
        printf("0\n");
    }
  }
  return 0;
}
