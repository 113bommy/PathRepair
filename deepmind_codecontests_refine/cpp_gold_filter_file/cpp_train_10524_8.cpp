#include <bits/stdc++.h>
int main() {
  int a, sum1, sum, t = 0, p, q, r, s;
  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
    scanf("%d%d%d%d", &p, &q, &r, &s);
    if (i == 0)
      sum1 = p + q + r + s;
    else
      sum = p + q + r + s;
    if (sum > sum1) {
      t++;
    }
  }
  printf("%d", t + 1);
  return 0;
}
