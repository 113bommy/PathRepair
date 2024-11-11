#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
int n, m, x, y, a, b;
int main() {
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
  int temp = gcd(a, b);
  a /= temp, b /= temp;
  int k = n / a < m / b ? n / a : m / b;
  a *= k, b *= k;
  int X = x - (a + 1) / 2;
  if (X < 0)
    X = 0;
  else if (X + a > n)
    X = n - a;
  int Y = y - (b + 1) / 2;
  if (Y < 0)
    Y = 0;
  else if (Y + b > m)
    Y = m - b;
  printf("%d %d %d %d\n", X, Y, X + a, Y + b);
  return 0;
}
