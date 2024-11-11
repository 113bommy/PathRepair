#include <bits/stdc++.h>
int main() {
  int t, a, p = 0, c = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &a);
    if (a > 0)
      p = p + a;
    else if (a < 0) {
      if (p + a >= 0)
        p--;
      else
        c++;
    }
  }
  printf("%d", c);
  return 0;
}
