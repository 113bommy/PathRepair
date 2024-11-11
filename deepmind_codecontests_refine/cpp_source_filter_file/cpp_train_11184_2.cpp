#include <bits/stdc++.h>
using namespace std;
const int eps = 1e-8;
bool ok(int x1, int y1, int x2, int y2) {
  if (x1 == 0 || x2 == 0 || x1 == x2)
    return false;
  else if (y1 == 0 || y2 == 0 || y1 == y2)
    return false;
  return true;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int x1, y1, x2, y2;
  for (int i = 0; i <= n; i++) {
    x1 = i;
    y1 = (int)sqrt(n * n - i * i);
    if (sqrt(n * n - i * i) - y1 <= eps) {
      if (m * y1 % n != 0 || m * x1 % n != 0) continue;
      x2 = m * y1 / n, y2 = m * x1 / n;
      if (ok(x1, y1, -x2, y2)) {
        printf("YES\n0 0\n");
        printf("%d %d\n%d %d\n", x1, y1, x2, y2);
        return 0;
      }
    }
  }
  printf("NO\n");
  return 0;
}
