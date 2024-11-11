#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
int n, m;
int a[3][maxn];
void solve(int n, int d) {
  if (n == 1)
    a[d][n] = 1;
  else if (n == 2)
    a[d][1] = 3, a[d][2] = 4;
  else {
    for (int i = 1; i <= n - 1; i++) a[d][i] = 2;
    a[d][n] = n - 2;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  solve(n, 1);
  solve(m, 2);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", a[1][i] * a[2][j]);
    printf("\n");
  }
  return 0;
}
