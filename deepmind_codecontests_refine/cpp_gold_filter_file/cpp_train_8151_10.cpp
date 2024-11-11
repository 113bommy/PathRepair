#include <bits/stdc++.h>
int main() {
  int n, k, l, c, d, p, n_l, n_p;
  int Q, R, S, T;
  scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &n_l, &n_p);
  Q = k * l;
  R = Q / n_l;
  S = c * d;
  T = p / n_p;
  if (R <= S && R <= T) {
    int U = R / n;
    printf("%d\n", U);
  } else if (S <= R && S <= T) {
    int U = S / n;
    printf("%d\n", U);
  } else {
    int U = T / n;
    printf("%d\n", U);
  }
  return 0;
}
