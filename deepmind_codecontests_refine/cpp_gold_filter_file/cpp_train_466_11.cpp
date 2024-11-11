#include <bits/stdc++.h>
int max(int a, int b) { return a > b ? a : b; }
int s[5] = {500, 1000, 1500, 2000, 2500};
int m[5], w[5], h1, h2;
int main() {
  for (int i = 0; i < 5; i++) scanf("%d", &m[i]);
  for (int i = 0; i < 5; i++) scanf("%d", &w[i]);
  scanf("%d%d", &h1, &h2);
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    ans += max(3 * s[i] / 10, s[i] - s[i] * m[i] / 250 - 50 * w[i]);
  }
  printf("%d\n", ans + h1 * 100 - h2 * 50);
  return 0;
}
