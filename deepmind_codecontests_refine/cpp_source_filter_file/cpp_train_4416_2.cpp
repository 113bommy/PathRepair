#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const int mo = 1e9 + 7;
int n, m, f[N][N];
bool a[N][N];
int ask(int x1, int y1, int x2, int y2) {
  if (x1 > x2 or y1 > y2) return 0;
  for (int i = x1; i <= x2; i++)
    for (int j = y1; j <= y2; j++) {
      f[i][j] = 0;
      if (a[i][j]) continue;
      if (i == x1 && j == y1) f[i][j] = 1;
      if (i > x1) (f[i][j] += f[i - 1][j]) %= mo;
      if (j > y1) (f[i][j] += f[i][j - 1]) %= mo;
    }
  return f[x2][y2];
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) a[i][j] = getchar() == '#';
    getchar();
  }
  int Ans = (1ll * ask(1, 2, n - 1, m) * ask(2, 1, n, m - 1) +
             1ll * ask(1, 2, n, m - 1) * ask(2, 1, n - 1, m)) %
            mo;
  printf("%d\n", (Ans + mo) % mo);
}
