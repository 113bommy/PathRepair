#include <bits/stdc++.h>
using namespace std;
int getint(int x = 0) {
  scanf("%d", &x);
  return x;
}
long long int getll(long long int x = 0) {
  scanf("%lld", &x);
  return x;
}
int n;
int a[105000];
int main() {
  n = getint();
  int sx, sy, sz;
  printf("? 1 2\n");
  fflush(stdout);
  sx = getint();
  printf("? 2 3\n");
  fflush(stdout);
  sy = getint();
  printf("? 3 1\n");
  fflush(stdout);
  sz = getint();
  a[2] = (sx + sy - sz) / 2;
  a[1] = sx - a[2];
  a[3] = sz - a[2];
  for (int i = 4; i <= n; i++) {
    printf("? 1 %d\n", i);
    fflush(stdout);
    a[i] = getint() - a[1];
  }
  printf("!");
  for (int i = 1; i <= n; i++) {
    printf(" %d", a[i]);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}
