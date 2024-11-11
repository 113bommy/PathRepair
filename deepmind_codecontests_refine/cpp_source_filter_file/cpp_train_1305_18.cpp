#include <bits/stdc++.h>
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (!c)
    if (a ^ b)
      printf("NO\n");
    else
      printf("YES\n");
  else if (c > 0)
    if ((b - a) % c == 0 && a < b)
      printf("YES\n");
    else
      printf("NO\n");
  else if (c < 0) {
    c = -c;
    if ((a - b) % c == 0 && a > b)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
