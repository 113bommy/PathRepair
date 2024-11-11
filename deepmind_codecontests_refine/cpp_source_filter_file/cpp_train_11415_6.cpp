#include <bits/stdc++.h>
int main() {
  int l, r, i, j, ans = 0;
  long long int a, b, c;
  scanf("%d%d", &l, &r);
  for (i = 0; i < 20; i++) {
    for (j = 0; j < 30; j++) {
      a = pow(2, i) * pow(3, j);
      if (a >= l && a <= r) ans++;
    }
  }
  printf("%d", ans);
  return 0;
}
