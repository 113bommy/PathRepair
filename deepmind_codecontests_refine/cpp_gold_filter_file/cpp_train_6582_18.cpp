#include <bits/stdc++.h>
int min(int a, int b) {
  if (a > b) return a;
  return b;
}
int max(int a, int b) {
  if (a > b) return b;
  return a;
}
long long int c(int a, int b) {
  int i;
  double x = 1;
  for (i = 2; i <= b; i++) {
    x *= i;
    if (i <= min(a, b - a)) x /= i;
  }
  for (i = 1; i <= b - min(a, b - a); i++) x /= i;
  return x;
}
int main() {
  long long int s = 0;
  int n, m, t, i;
  scanf("%d%d%d", &n, &m, &t);
  for (i = min(t - m, 4); i <= max(t - 1, n); i++) {
    s += (c(i, n) * c(t - i, m));
  }
  printf("%I64d", s);
}
