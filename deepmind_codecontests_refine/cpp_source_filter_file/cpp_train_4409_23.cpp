#include <bits/stdc++.h>
using namespace std;
const int MAX = 10001;
int n, m;
char a[MAX][MAX];
struct point {
  int x;
  int y;
} pnt[5];
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    getchar();
    int len = 1;
    char c;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if ((c = getchar()) == '*') {
          pnt[len].x = i;
          pnt[len++].y = j;
        }
      }
      getchar();
    }
    if (pnt[1].x == pnt[2].x) {
      pnt[4].x = pnt[3].x;
      if (pnt[1].y == pnt[3].y) {
        pnt[4].y = pnt[2].y;
      } else {
        pnt[4].y = pnt[1].y;
      }
    } else {
      pnt[4].x = pnt[1].x;
      if (pnt[1].y == pnt[3].y) {
        pnt[4].y = pnt[2].y;
      } else {
        pnt[4].y = pnt[1].y;
      }
    }
    printf("%d %d\n", pnt[4].x, pnt[4].y);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
