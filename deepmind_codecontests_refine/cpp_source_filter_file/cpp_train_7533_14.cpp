#include <bits/stdc++.h>
using namespace std;
int u[102][102];
int* lable(int i, int j) {
  static int v[10];
  fill(v, v + 10, 0);
  v[u[i - 1][j]] = v[u[i - 1][j + 1]] = 1;
  v[u[i + 2][j]] = v[u[i + 2][j + 1]] = 1;
  v[u[i][j - 1]] = v[u[i + 1][j - 1]] = 1;
  v[u[i][j + 2]] = v[u[i + 1][j + 2]] = 1;
  return v;
}
int main() {
  int n, m, a, b, c;
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
  if (n * m % 2 || n % 2 && a < m / 2 || m % 2 && b < n / 2)
    return puts("IMPOSSIBLE");
  if (n % 2)
    for (int i = 1; i <= m; i += 2, a--) u[n][i] = u[n][i + 1] = i / 2 % 2 + 1;
  if (m % 2)
    for (int i = 1; i <= n; i += 2, b--) u[i][m] = u[i + 1][m] = i / 2 % 2 + 1;
  for (int i = 1; i < n; i += 2)
    for (int j = 1; j < m; j += 2) {
      int *v = lable(i, j), x = find(v, v + 10, 0) - v,
          y = find(v + x + 1, v + 10, 0) - v;
      if (c >= 1) {
        u[i + 0][j] = u[i + 0][j + 1] = x;
        u[i + 1][j] = u[i + 1][j + 1] = x;
        c--;
      } else if (a >= 2) {
        u[i + 0][j] = u[i + 0][j + 1] = x;
        u[i + 1][j] = u[i + 1][j + 1] = y;
        a -= 2;
      } else if (b >= 2) {
        u[i][j + 0] = u[i + 1][j + 0] = x;
        u[i][j + 1] = u[i + 1][j + 1] = y;
        b -= 2;
      } else
        return puts("IMPOSSIBLE");
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d", 'a' + u[i][j] - 1);
    puts("");
  }
}
