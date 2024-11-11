#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
} p[5];
int main() {
  int n, i, res = 0, j;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  if (n == 1) {
    printf("-1\n");
  } else if (n == 2) {
    if (p[0].x == p[1].x || p[0].y == p[1].y) {
      printf("-1\n");
    } else {
      printf("%d\n", abs(p[0].y - p[1].y) * abs(p[0].x - p[1].x));
    }
  } else {
    for (i = 0; i < n && res == 0; ++i) {
      for (j = 0; j < n && res == 0; ++j) {
        if (p[i].x != p[j].x && p[i].y != p[j].y) {
          res = abs(p[i].y - p[j].y) * abs(p[i].x - p[j].x);
          break;
        }
      }
    }
    printf("%d\n", res);
  }
}
