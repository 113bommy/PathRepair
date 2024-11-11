#include <bits/stdc++.h>
int mx(int a, int b) {
  if (a > b) return a;
  return b;
}
int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  int a = x + 1;
  int b = (n - y);
  int ss = mx(a, b);
  printf("%d\n", ss);
  return 0;
}
