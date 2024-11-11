#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
int T;
int main() {
  scanf("%d", &T);
  while (T--) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if (x > y) swap(x, y);
    int mx, mi;
    if (x - 1 <= n - y)
      mx = x + y - 1;
    else
      mx = n;
    if (x == 1 && y == 1)
      mi = 1;
    else if (x == n && y == n)
      mi = n;
    else if (x == 1 && y == n)
      mi = 2;
    else if (x == 1)
      mi = 1;
    else if (y == n)
      mi = n - x;
    else if (max(0, n - y - 1) >= x - 1)
      mi = 1;
    else
      mi = x - 1 - max(n - y - 1, 0) + 1;
    printf("%d %d\n", mi, mx);
  }
}
