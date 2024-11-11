#include <bits/stdc++.h>
int abs(int x) {
  if (x < 0)
    return -x;
  else
    return x;
}
int main() {
  int n, m, s;
  scanf("%d %d", &n, &m);
  s = abs(n) + abs(m);
  if (n < 0 && m < 0)
    printf("%d 0 0 %d", -s, -s);
  else if (n < 0 && m > 0)
    printf("%d 0 0 %d", -s, s);
  else if (n > 0 && m < 0)
    printf("0 %d %d 0", -s, s);
  else if (n > 0 && m > 0)
    printf("0 %d %d 0", s, s);
  printf("\n");
  return 0;
}
