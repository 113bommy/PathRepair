#include <bits/stdc++.h>
int main() {
  int a, b, c, n, res = 0;
  scanf("%i %i %i\n%i\n", &a, &b, &c, &n);
  for (int i = 0; i < n; ++i) {
    int pos;
    scanf("%i", &pos);
    if (pos > b && pos < c) res++;
  }
  printf("%i\n", res);
  return 0;
}
