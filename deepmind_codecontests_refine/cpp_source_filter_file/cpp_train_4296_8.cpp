#include <bits/stdc++.h>
inline int Bitcount(int x) {
  int ret = 0;
  while (x) ret += x & 1, x >>= 1;
  return ret;
}
int n, k;
int main() {
  scanf("%d %d", &n, &k);
  if (n == 1 && k == 0) {
    printf("YES\n0\n");
    return 0;
  }
  if (!(n & 1) || n - 2 * k < 3) {
    puts("NO");
    return 0;
  }
  if (n == 9 && k == 2) {
    puts("NO");
    return 0;
  }
  if (k == 0 && Bitcount(n + 1) != 1) {
    puts("NO");
    return 0;
  }
  if (k == 1 && Bitcount(n + 1) == 1) {
    puts("NO");
    return 0;
  }
  puts("YES");
  if (k == 0 || k == 1) {
    for (int i = 1; i < n; i++) printf("%d ", i >> 1);
    printf("%d\n", n >> 1);
    return 0;
  }
  int lim = n - 2 * (k - 1);
  printf("%d", lim + 2);
  for (int i = 1; i <= lim - 2; i++) printf(" %d", i >> 1);
  if (Bitcount(lim + 1) == 1)
    printf(" %d %d", n - 1, n - 1);
  else
    printf(" %d %d", (lim - 1) >> 1, lim >> 1);
  for (int i = lim + 1; i < n - 1; i += 2) printf(" %d %d", i + 1, i + 3);
  printf(" %d 0\n", n);
  return 0;
}
