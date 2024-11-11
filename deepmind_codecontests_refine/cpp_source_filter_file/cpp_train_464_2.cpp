#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, y, flag = 0, tt = 0, m, x;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &y);
    for (int j = 1; j <= y; j++) {
      scanf("%d", &x);
      if (j == x && j == 1) flag = 1;
      if (flag && !tt) {
        if (flag == j)
          flag = j;
        else
          tt = 1;
      }
    }
  }
  printf("%d", 2 * n - 2 * flag - m + 1);
  return 0;
}
