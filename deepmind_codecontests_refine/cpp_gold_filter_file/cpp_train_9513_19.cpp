#include <bits/stdc++.h>
using namespace std;
int cond = 1;
int points[500][2];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (m == 3) {
    if (n >= 5) {
      printf("-1\n");
      return 0;
    }
    if (n == 4) {
      printf("0 0\n10 0\n0 10\n1 1\n");
      return 0;
    }
    if (n == 3) {
      printf("0 0\n10 0\n0 10\n");
      return 0;
    }
  } else {
    points[0][0] = 0;
    points[0][1] = 0;
    for (int i = 1; i < (m + 2) / 2; ++i) {
      points[2 * i - 1][0] = points[2 * i - 2][0] + i;
      points[2 * i - 1][1] = i;
      points[2 * i][0] = points[2 * i - 1][0];
      points[2 * i][1] = -points[2 * i - 1][1];
    }
    int maxx = points[m - 1][0];
    for (int i = 0; i < m; ++i) {
      printf("%d %d\n", points[i][0] - maxx + 100000000, points[i][1]);
    };
    for (int i = 0; i < n - m; ++i) {
      printf("%d %d\n", maxx - points[i][0] + -100000000, points[i][1]);
    }
  }
}
