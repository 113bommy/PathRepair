#include <bits/stdc++.h>
int minn(int a, int b) {
  if (a > b)
    return b;
  else
    return a;
}
int main() {
  int m, n, ji1, ji2, ou1, ou2, i, a, j;
  while (scanf("%d %d", &m, &n) != EOF) {
    ji1 = 0;
    ji2 = 0;
    ou1 = 0;
    ou2 = 0;
    for (i = 0; i < m; i++) {
      scanf("%d", &a);
      if (a % 2)
        ji1++;
      else
        ou1++;
    }
    for (j = 0; j < n; j++) {
      scanf("%d", &a);
      if (a % 2 == 0)
        ou2++;
      else
        ji2++;
    }
    printf("%d\n", minn(ji1, ou2) + minn(ji2, ou1));
  }
}
