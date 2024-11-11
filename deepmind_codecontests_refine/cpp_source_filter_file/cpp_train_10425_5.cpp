#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  n /= 2;
  if (x == n || x == n + 1) {
    if ((y == 1 || y == 2 || y == 2 * n || y == 2 * n - 1) && n >= 3)
      printf("Yes\n");
    else if (y < n && 6 + 2 * (y - 2) <= 2 * n)
      printf("Yes\n");
    else if (y >= n && 6 + 2 * (2 * n - y - 1) <= 2 * n)
      printf("Yes\n");
    else
      printf("NO\n");
  } else
    printf("Yes\n");
  return 0;
}
