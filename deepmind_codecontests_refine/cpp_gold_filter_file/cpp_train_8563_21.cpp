#include <bits/stdc++.h>
int main() {
  int pp, qq, t, i, j, k, count = 0;
  scanf("%d", &t);
  for (i = 2; i < t; i++) {
    k = t;
    while (k != 0) {
      count += k % i;
      k = k / i;
    }
  }
  qq = t - 2;
  for (pp = 2; pp < 1000; pp++) {
    if (count % pp == 0 && qq % pp == 0) {
      count = count / pp;
      qq = qq / pp;
      pp = 1;
    }
  }
  printf("%d/%d\n", count, qq);
  return 0;
}
