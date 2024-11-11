#include <bits/stdc++.h>
int main(void) {
  int n, k, p, x, c = 0, y, i, s = 0;
  scanf("%d %d %d %d  %d", &n, &k, &p, &x, &y);
  int m[1000];
  for (i = 0; i < k; i++) {
    scanf("%d", &m[i]);
    s += m[i];
    if (m[i] < y) c++;
  }
  if ((s + (n - k) > x) || (c > (n - 1) / 2)) {
    printf("-1");
  } else {
    int a = 1;
    for (i = k; i < n; i++) {
      if (c == (n - 1) / 2) {
        a = y;
      } else if (c < (n - 1) / 2)
        c++;
      m[i] = a;
      s += m[i];
    }
    int l = 0;
    for (i = 0; i < n; i++) {
      if (m[i] <= y) l++;
    }
    if ((s <= x) && (l >= (n - 1) / 2)) {
      for (i = k; i < n; i++) printf("%d ", m[i]);
    } else
      printf("-1 ");
  }
  return 0;
}
