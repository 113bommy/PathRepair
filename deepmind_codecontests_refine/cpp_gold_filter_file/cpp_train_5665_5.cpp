#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int xx[111][2];
    int i, j, a = 0, b = 0;
    for (i = 0; i < n; i++)
      scanf("%d %d", &xx[i][0], &xx[i][1]), a += xx[i][0], b += xx[i][1];
    if ((a + b) & 1)
      printf("-1\n");
    else if (a % 2 == 0)
      printf("0\n");
    else {
      bool flag = 0;
      for (i = 0; i < n; i++) {
        if ((xx[i][0] + xx[i][1]) & 1) {
          flag = 1;
          break;
        }
      }
      printf("%d\n", flag ? 1 : -1);
    }
  }
}
