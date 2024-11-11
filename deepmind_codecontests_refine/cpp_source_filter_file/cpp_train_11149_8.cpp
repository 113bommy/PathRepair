#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l, r, v1, v2, d1, d2;
  int d3;
  scanf("%d", &n);
  l = 1, r = 1 + n / 2;
  printf("?%d\n", l);
  fflush(stdout);
  scanf("%d", &v1);
  printf("?%d\n", r);
  fflush(stdout);
  scanf("%d", &v2);
  d1 = v1 - v2;
  d2 = v2 - v1;
  while (1) {
    if (d1 % 2) {
      printf("-1\n");
      return 0;
    }
    printf("?%d\n", (l + r) / 2);
    fflush(stdout);
    scanf("%d", &v1);
    printf("?%d\n", (l + r) / 2 + n / 2);
    fflush(stdout);
    scanf("%d", &v2);
    d3 = v1 - v2;
    if (d3 == 0) {
      printf("!%d\n", (l + r) / 2);
      fflush(stdout);
      return 0;
    }
    if ((d3 > 0 && d1 > 0) || (d3 < 0 && d1 < 0)) {
      l = (l + r) / 2;
    } else {
      r = (l + r) / 2;
    }
  }
  return 0;
}
