#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int m = (n + 2) / 2;
  bool point = 0;
  int x = 1, y = 1;
  printf("%d", m);
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", x, y);
    if (point == 0) {
      y++;
    } else {
      x++;
    }
    point = 1 - point;
  }
  return 0;
}
