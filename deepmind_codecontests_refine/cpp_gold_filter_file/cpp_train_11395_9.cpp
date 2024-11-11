#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a = 0, b = 0, c[101][101] = {0};
  scanf("%d %d", &n, &m);
  if (n == 1 && m == 1) {
    printf("1");
    return 0;
  }
  if (n + m < 5) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i + j) % 2) {
        a++;
        c[i][j] = a;
      } else {
        b++;
        c[i][j] = b + n * m / 2;
      }
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = m; j > 0; j--) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}
