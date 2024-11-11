#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int n;
  scanf("%d", &n);
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1)
      x++;
    else
      y++;
  }
  if (y == 0 || x == 0) {
    for (int i = 1; i <= x; i++) printf("%d ", a[i]);
    return 0;
  }
  printf("%d %d ", 2, 1);
  x--;
  y--;
  while (y--) printf("%d ", 2);
  while (x--) printf("%d ", 1);
  return 0;
}
