#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n / 2 & 1) {
    puts("! -1");
    fflush(stdout);
    return 0;
  }
  int s, so;
  printf("? %d\n", 1);
  fflush(stdout);
  scanf("%d", &s);
  printf("? %d\n", 1 + n / 2);
  fflush(stdout);
  scanf("%d", &so);
  if (s == so) {
    printf("! %d\n", s);
    fflush(stdout);
    return 0;
  }
  int lo = 2, hi = n / 2, mi;
  while (true) {
    mi = lo + hi >> 1;
    int q, qo;
    printf("? %d\n", mi);
    fflush(stdout);
    scanf("%d", &q);
    printf("? %d\n", mi + n / 2);
    fflush(stdout);
    scanf("%d", &qo);
    if (q == qo) {
      printf("! %d\n", q);
      fflush(stdout);
      return 0;
    }
    if ((s < so && q < qo) || (s > so && q > qo)) {
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  return 0;
}
