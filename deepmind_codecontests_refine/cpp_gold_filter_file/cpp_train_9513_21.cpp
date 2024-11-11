#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  int x, y, dx, i;
  scanf("%d%d", &n, &m);
  if (m == 3) {
    if (n == 3) printf("0 0\n1 0\n0 1");
    if (n == 4) printf("0 0\n3 0\n0 3\n1 1");
    if (n > 4) printf("-1");
    return 0;
  }
  x = y = (int)1e+8;
  dx = 1;
  for (i = 1; i <= m; i++) {
    cout << x << ' ' << y << "\n";
    x -= dx;
    y--;
    dx++;
  }
  x = (int)1e+8;
  y = -x;
  dx = 1;
  for (i = m + 1; i <= n; i++) {
    cout << x << ' ' << y << "\n";
    x -= dx;
    y++;
    dx++;
  }
  return 0;
}
