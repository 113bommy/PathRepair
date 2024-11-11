#include <bits/stdc++.h>
int main() {
  int i, j, k, n, l, m, t1, t2, t3, c = 0;
  ;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    scanf("%d", &k);
    scanf("%d", &l);
    scanf("%d", &m);
    t1 = j / k;
    t2 = (l - 1) / k;
    t3 = m / k;
    c = t1 - (t3 - t2);
    printf("%d\n", c);
  }
}
