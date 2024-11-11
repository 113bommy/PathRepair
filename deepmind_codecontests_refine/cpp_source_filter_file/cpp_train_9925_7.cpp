#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x1, y1, x2, y2;
  while (scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2) != EOF) {
    int x = abs(x1 - x2);
    int y = abs(y1 - y2);
    if (x > y) swap(x, y);
    if (x >= 4)
      printf("Second\n");
    else if (x == 3 && y >= 4)
      printf("Second\n");
    else
      printf("First\n");
  }
  return 0;
}
