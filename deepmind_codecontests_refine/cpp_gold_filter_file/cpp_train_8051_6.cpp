#include <bits/stdc++.h>
int main() {
  int n, a;
  float t = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    t += a / 100.0;
  }
  printf("%f\n", t * 100 / n);
  return 0;
}
