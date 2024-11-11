#include <bits/stdc++.h>
int main() {
  int n, m, a, b, res = 0;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  if ((b - 1) / m - (a - 1) / m == 1) {
    res = 2;
  }
  if ((b % m - a % m == -1) || (b % m - (a % m + 3) == -1)) {
    res = 2;
  }
  if (b == n) {
    res = 2;
  }
  if (b % m == 0) {
    res = 2;
  }
  if (a - 1 % m == 0) {
    res = 2;
  }
  if ((b - 1) / m - (a - 1) / m == 0) {
    res = 1;
  }
  if (((a - 1) % m == 0) && (b % m == 0)) {
    res = 1;
  }
  if (b == n && ((a - 1) % m == 0)) {
    res = 1;
  }
  if (res == 0) {
    res = 3;
  }
  printf("%d", res);
  return 0;
}
