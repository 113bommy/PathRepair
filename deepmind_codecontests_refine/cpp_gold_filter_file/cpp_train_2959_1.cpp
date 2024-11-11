#include <bits/stdc++.h>
int main() {
  char c[100003];
  long long i, t = 0, s = 1;
  scanf("%s", c);
  for (i = 0; i <= strlen(c) - 1; i++) {
    if (c[i] + c[i - 1] - 2 * '0' == 9)
      t++;
    else {
      s *= 1 + !(t % 2) * ((t + 1) / 2);
      t = 0;
    }
  }
  if (t) s *= 1 + !(t % 2) * ((t + 1) / 2);
  printf("%I64d", s);
  return 0;
}
