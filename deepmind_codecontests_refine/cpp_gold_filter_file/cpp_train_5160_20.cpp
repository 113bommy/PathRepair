#include <bits/stdc++.h>
using namespace std;
int a[5003];
int main() {
  int n, x, y, z, i;
  scanf("%d", &n);
  printf("? 1 2\n? 2 3\n? 3 1\n");
  fflush(stdout);
  scanf("%d%d%d", &x, &y, &z);
  a[1] = (x + z - y) / 2;
  a[2] = x - a[1];
  a[3] = y - a[2];
  for (i = 4; i <= n; i++) {
    printf("? 1 %d\n", i);
    fflush(stdout);
    scanf("%d", &x);
    a[i] = x - a[1];
  }
  printf("!");
  for (i = 1; i <= n; i++) printf(" %d", a[i]);
  printf("\n");
  fflush(stdout);
  return 0;
}
