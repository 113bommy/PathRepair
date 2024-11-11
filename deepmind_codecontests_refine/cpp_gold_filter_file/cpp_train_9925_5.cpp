#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x1, y1, x2, y2;
  scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
  n = abs(x1 - x2) + 1;
  m = abs(y1 - y2) + 1;
  if (n > m) swap(n, m);
  puts((n <= 3 && n + m <= 6) || (n == 3 && m == 4) || (n == 2 && m == 5) ||
               (n == 4 && m == 4) || (n == 3 && m == 5)
           ? "First"
           : "Second");
  return 0;
}
