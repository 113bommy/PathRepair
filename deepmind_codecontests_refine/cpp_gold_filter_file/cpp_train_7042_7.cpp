#include <bits/stdc++.h>
int n, m, s, e;
int solve() {
  s--, e--;
  if (s / m == e / m) return 1;
  if (s % m == 0 && (e % m == m - 1 || e + 1 == n)) return 1;
  if (s / m + 1 == e / m) return 2;
  if (s % m == 0 || e % m == m - 1 || e + 1 == n) return 2;
  if (s % m == e % m + 1) return 2;
  return 3;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &e);
  printf("%d\n", solve());
  return 0;
}
