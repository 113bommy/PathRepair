#include <bits/stdc++.h>
int x[2050] = {0};
int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else
    return gcd(b, a % b);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  if (n == 1 && x[0] == 1) {
    printf("0\n");
    return 0;
  }
  int ans = 1000000;
  int ggg = 0;
  for (int j = 0; j < n - 1; j++) {
    int g = x[j], fin = 1, gg = 0;
    for (int i = j; i < n - 1; i++) {
      g = gcd(g, x[i + 1]);
      if (g == 1) {
        gg = 1;
        ggg = 1;
        break;
      }
      fin++;
    }
    if (gg) {
      if (fin < ans) ans = fin;
    }
  }
  if (ggg) {
    ans = ans + n - 1;
    for (int i = 0; i < n; i++)
      if (x[i] == 1) ans--;
    printf("%d\n", ans);
  } else
    printf("-1\n");
  return 0;
}
