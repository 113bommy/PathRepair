#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m;
int a[N][2];
void work(int x, int c) {
  if (x == 1)
    a[1][c] = 1;
  else if (x == 2)
    a[1][c] = 3, a[2][c] = 4;
  else if (x % 2) {
    a[1][c] = 2;
    for (int i = 2; i < x; ++i) a[i][c] = 1;
    a[x][c] = (x + 1) / 2;
  } else {
    for (int i = 1; i < x; ++i) a[i][c] = 1;
    a[x][c] = (x - 2) / 2;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  work(n, 0);
  work(m, 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%d ", a[i][0] * a[j][1]);
    printf("\n");
  }
  return 0;
}
