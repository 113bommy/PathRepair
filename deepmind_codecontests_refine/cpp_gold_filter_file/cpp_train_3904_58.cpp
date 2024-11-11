#include <bits/stdc++.h>
int n, m, k, flag, x, y;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &x, &y);
    flag |= (x < 6) | (y < 6) | (x + 5 > n) | (y + 5 > m);
  }
  puts(flag ? "YES" : "NO");
}
