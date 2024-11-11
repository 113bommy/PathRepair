#include <bits/stdc++.h>
using namespace std;
int g(int x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  int a, b, c, d, e, f, X, Y;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  int ans = 1e9;
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      int x = g(i - a) + g(i - c) + g(i - e) + g(j - b) + g(j - d) + g(j - f);
      if (ans > x) {
        ans = x;
        X = i, Y = j;
      }
    }
  }
  printf("%d\n%d %d\n", ans + 1, X, Y);
  for (int i = X + 1; i <= a; i++) printf("%d %d\n", i, Y);
  for (int i = X - 1; i >= a; i--) printf("%d %d\n", i, Y);
  for (int i = Y + 1; i <= b; i++) printf("%d %d\n", X, i);
  for (int i = Y - 1; i >= b; i--) printf("%d %d\n", X, i);
  for (int i = X + 1; i <= c; i++) printf("%d %d\n", i, Y);
  for (int i = X - 1; i >= c; i--) printf("%d %d\n", i, Y);
  for (int i = Y + 1; i <= d; i++) printf("%d %d\n", X, i);
  for (int i = Y - 1; i >= d; i--) printf("%d %d\n", X, i);
  for (int i = X + 1; i <= e; i++) printf("%d %d\n", i, Y);
  for (int i = X - 1; i >= e; i--) printf("%d %d\n", i, Y);
  for (int i = Y + 1; i <= f; i++) printf("%d %d\n", X, i);
  for (int i = Y - 1; i >= f; i--) printf("%d %d\n", X, i);
  return 0;
}
