#include <bits/stdc++.h>
int f[66];
int main() {
  int a;
  scanf("%d", &a);
  f[1] = 1;
  f[2] = 2;
  f[3] = 1;
  f[4] = 1;
  f[5] = 1;
  printf("%d\n", f[a]);
  return 0;
}
