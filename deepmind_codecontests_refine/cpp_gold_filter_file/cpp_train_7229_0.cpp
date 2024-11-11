#include <bits/stdc++.h>
int main() {
  int m, n, t;
  scanf("%d %d", &m, &n);
  if (m > n) {
    t = n - 1;
    m -= n - 1;
    t++;
  } else {
    t = m - 1;
    n -= m - 1;
    t++;
  }
  if (t % 2 == 0)
    printf("Malvika\n");
  else
    printf("Akshat\n");
}
