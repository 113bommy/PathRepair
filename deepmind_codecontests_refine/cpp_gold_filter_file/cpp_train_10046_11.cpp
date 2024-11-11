#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  if ((a == c && (abs(b - d) != n)) || (b == d && abs(a - c) != n))
    printf("%d\n", abs(a - c) + abs(b - d));
  else if (abs(a - c) == n)
    printf("%d\n", n + b + d < 3 * n - b - d ? n + b + d : 3 * n - b - d);
  else if (abs(b - d) == n)
    printf("%d\n", n + a + c < 3 * n - a - c ? n + a + c : 3 * n - a - c);
  else
    printf("%d\n", abs(a - c) + abs(b - d) < 4 * n - abs(a - c) - abs(b - d)
                       ? abs(a - c) + abs(b - d)
                       : 4 * n - abs(a - c) - abs(b - d));
  return 0;
}
