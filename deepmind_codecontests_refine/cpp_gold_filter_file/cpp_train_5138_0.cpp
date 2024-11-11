#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
int n, m, rb, x, y, mo;
int a[N], b[N], f[N][N][2], s[N][N][2];
void print(int x, int y, int z) {
  if (x == 0 && y == 0) return;
  if (z == 0) {
    print(x - 1, y, s[x][y][z]);
    printf("%d 1\n", a[x]);
  } else {
    print(x, y - 1, s[x][y][z]);
    printf("%d 2\n", b[y]);
  }
}
int main() {
  memset(f, 63, sizeof(f));
  scanf("%d", &rb);
  f[0][0][0] = 0;
  f[0][0][1] = 0;
  a[0] = -1;
  b[0] = -1;
  f[1][0][0] = 0;
  f[0][1][1] = 0;
  scanf("%d %d %d %d %d", &n, a + 1, &x, &y, &mo);
  for (int i = 2; i <= n; i++) {
    a[i] = ((long long)a[i - 1] * x + y) % mo;
    f[i][0][0] = f[i - 1][0][0] + (a[i] < a[i - 1]);
  }
  scanf("%d %d %d %d %d", &m, b + 1, &x, &y, &mo);
  for (int i = 2; i <= m; i++) {
    b[i] = ((long long)b[i - 1] * x + y) % mo;
    f[0][i][1] = f[0][i - 1][1] + (b[i] < b[i - 1]);
    s[0][i][1] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      f[i][j][0] = f[i - 1][j][0] + (a[i] < a[i - 1]);
      int tmp = f[i - 1][j][1] + (a[i] < b[j]);
      if (f[i][j][0] > tmp) {
        f[i][j][0] = tmp;
        s[i][j][0] = 1;
      }
      f[i][j][1] = f[i][j - 1][0] + (b[j] < a[i]);
      tmp = f[i][j - 1][1] + (b[j] < b[j - 1]);
      if (f[i][j][1] > tmp) {
        f[i][j][1] = tmp;
        s[i][j][1] = 1;
      }
    }
  printf("%d\n", min(f[n][m][0], f[n][m][1]));
  if (f[n][m][0] < f[n][m][1])
    print(n, m, 0);
  else
    print(n, m, 1);
}
