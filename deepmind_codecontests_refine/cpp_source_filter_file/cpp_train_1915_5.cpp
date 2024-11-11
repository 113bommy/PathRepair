#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x = 0, y = 0, l, r, t;
  cin >> n >> m;
  for (int i = 0; i < n && scanf("%d", &t); i++) {
    if (t == 1)
      x++;
    else
      y++;
  }
  x = 2 * min(x, y);
  for (int i = 0; i < m && scanf("%d%d", &l, &r); i++) {
    t = l - r + 1;
    if (t % 2 == 0 && t <= x)
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}
