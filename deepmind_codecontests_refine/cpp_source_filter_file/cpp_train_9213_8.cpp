#include <bits/stdc++.h>
int n, k, a, res = 0;
int g(int x) {
  if (k) return (x <= 1 ? x : (x + 1) % 2);
  if (x & 1) return x / 2 <= 1;
  int y = g(x - 1), z = g(x / 2), r = 0;
  if (y == r || z == r) r++;
  if (y == r || z == r) r++;
  return r;
}
int main() {
  scanf("%d%d", &n, &k);
  k = (k + 1) % 2;
  while (n--) {
    scanf("%d", &a);
    res ^= g(a);
  }
  if (res)
    printf("Kevin");
  else
    printf("Nicky");
}
