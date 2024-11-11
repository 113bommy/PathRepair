#include <bits/stdc++.h>
int main() {
  int n, i, p = 0;
  char c[1000];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", c);
    if ((c[0] == '-' && c[1] == '-') || (c[1] == '-' && c[2] == '-')) p--;
    if ((c[0] == '+' && c[1] == '+') || (c[1] == '+' && c[2] == '+')) p++;
  }
  printf("%d", p);
  return 0;
}
