#include <bits/stdc++.h>
int n, m, k;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  bool b = 0;
  while (k--) {
    int mn = 5;
    int x, y;
    scanf("%d%d", &x, &y);
    if (mn > x - 1) mn = x - 1;
    if (mn > n - x) mn = n - x;
    if (mn > y - 1) mn = y - 1;
    if (mn > m - y) mn = m - y;
    b |= (mn < 5);
  }
  printf("%s\n", b ? "YES" : "NO");
  return 0;
}
