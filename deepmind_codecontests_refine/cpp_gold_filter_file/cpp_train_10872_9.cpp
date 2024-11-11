#include <bits/stdc++.h>
using namespace std;
const int MAX = 110;
int mx[MAX][MAX];
int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) == 2) {
    if (n == 1)
      mx[0][1] = 1;
    else if (n == 2)
      mx[0][1] = 3, mx[0][2] = 4;
    else {
      for (int i = 1; i < n; i++) mx[0][i] = 2;
      mx[0][n] = n - 2;
    }
    if (m == 1)
      mx[1][1] = 1;
    else if (m == 2)
      mx[1][1] = 3, mx[1][2] = 4;
    else {
      for (int i = 1; i < m; i++) mx[1][i] = 2;
      mx[1][m] = m - 2;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        printf("%d ", mx[0][i] * mx[1][j]);
      }
      printf("\n");
    }
  }
}
