#include <bits/stdc++.h>
int main(void) {
  int t;
  long int a, b, k, p, s;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%ld ", &a);
    scanf("%ld ", &b);
    scanf("%ld ", &k);
    s = k / 2;
    if ((k % 2) == 0) {
      p = (a - b) * (s);
    }
    if ((k % 2) == 1) {
      p = ((a - b) * (s) + a);
    }
    printf("%ld \n", p);
  }
  return 0;
}
