#include <bits/stdc++.h>
int main() {
  int i, a;
  double n, ans = 0;
  scanf("%f", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    ans = ans + a / n;
  }
  printf("%f", ans);
}
