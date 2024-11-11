#include <bits/stdc++.h>
int main(void) {
  int n, m, a, b, c;
  scanf("%d %d", &n, &m);
  if (!m)
    printf("1");
  else {
    if (!(n % m)) {
      if ((n / m) >= 2)
        printf("%d", m);
      else if ((n / m) == 1)
        printf("0");
    } else {
      if ((n / m) < 2)
        printf("%d", m - 1);
      else
        printf("%d", m);
    }
  }
  return 0;
}
