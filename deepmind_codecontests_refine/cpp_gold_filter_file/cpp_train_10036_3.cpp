#include <bits/stdc++.h>
int n, m, x, y;
int func(int x, int y) { return (x % y == 0 ? y : func(y, x % y)); }
int main() {
  scanf("%d %d %d %d", &n, &m, &x, &y);
  int k = n * m / (m > n ? func(m, n) : func(n, m));
  printf("%d\n", y / k - ((x - 1) / k + 1) + 1);
  scanf("\n");
}
