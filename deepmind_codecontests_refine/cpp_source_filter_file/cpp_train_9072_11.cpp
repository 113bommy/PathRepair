#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  int m = (n + 1) / 2;
  printf("%d\n", m);
  int x = 1, y = 1;
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", x, y);
    if (x == m)
      y++;
    else
      x++;
  }
  return 0;
}
