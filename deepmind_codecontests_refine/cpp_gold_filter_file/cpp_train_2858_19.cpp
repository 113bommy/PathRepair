#include <bits/stdc++.h>
int main() {
  int i, n, x = 0, y;
  char str[10], *mon[12] = {"January",   "February", "March",    "April",
                            "May",       "June",     "July",     "August",
                            "September", "October",  "November", "December"};
  scanf("%s%d", &str, &y);
  for (i = 0; i < 12 && x == 0; i++) {
    n = strcmp(str, mon[i]);
    if (n == 0) x = i + 1;
  }
  x = x + y;
  x = x % 12;
  if (x == 0)
    printf("%s", mon[11]);
  else
    printf("%s", mon[x - 1]);
  return 0;
}
