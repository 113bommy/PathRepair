#include <bits/stdc++.h>
using namespace std;
int ans = 1 << 30;
int x = 0, y = 0, z = 0, n, s, a, b, c;
void check(const int A, const int B, const int C) {
  int q = A * x, w = B * y, e = C * z;
  if (abs(q - w) + abs(w - e) < ans)
    ans = abs(q - w) + abs(w - e), a = A, b = B, c = C;
}
int gcd(const int x, const int y) { return x % y == 0 ? y : gcd(y, x % y); }
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 1, X; i <= n; ++i) {
    scanf("%d", &X);
    if (X == 3)
      ++x;
    else if (X == 4)
      ++y;
    else
      ++z;
  }
  int R = gcd(x, z);
  for (int i = 0; i * (y + z) <= s; ++i)
    if ((s - i * y) % R == 0) {
      int p = (i * (x + y + z) <= s ? i : (s - i * (y + z)) / x);
      if (p * x <= i * y) {
        for (int j = p; j >= 0; --j)
          if ((s - i * y - x * j) % z == 0) {
            check(j, i, (s - i * y - x * j) / z);
            break;
          }
      } else {
        for (int j = i * y / x + 1; j <= p; ++j)
          if ((s - i * y - x * j) % z == 0) {
            check(j, i, (s - i * y - x * j) / z);
            break;
          }
        for (int j = i * y / x; j >= 0; --j)
          if ((s - i * y - x * j) % z == 0) {
            check(j, i, (s - i * y - x * j) / z);
            break;
          }
      }
    }
  if (ans > s)
    puts("-1");
  else
    printf("%d %d %d\n", a, b, c);
  return 0;
}
