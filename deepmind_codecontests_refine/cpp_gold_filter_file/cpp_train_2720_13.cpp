#include <bits/stdc++.h>
int main(int argc, char** argv) {
  int i = 0, n = 0, res = 0;
  scanf("%d", &n);
  n = n % 1000;
  for (i = n; i > 0; i--) res = abs(res - i);
  printf("%d\n", res);
  return 0;
}
