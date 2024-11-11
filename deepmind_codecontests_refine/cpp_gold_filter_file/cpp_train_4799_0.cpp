#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, a[5005], f[5005][5005][3];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  memset(f, 0x3f, sizeof(f));
  f[1][1][1] = f[1][0][0] = 0;
  int up = (n + 1) / 2;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= up; j++) {
      f[i][j][0] = min(f[i - 1][j][0], f[i - 1][j][2]);
      if (j > 0)
        f[i][j][1] = min(f[i - 1][j - 1][0] + max(0, a[i - 1] - a[i] + 1),
                         f[i - 1][j - 1][2] +
                             max(0, min(a[i - 1], a[i - 2] - 1) - a[i] + 1));
      f[i][j][2] = f[i - 1][j][1] + max(0, a[i] - a[i - 1] + 1);
    }
  }
  for (int i = 1; i <= up; i++)
    printf("%d ", min(f[n][i][0], min(f[n][i][1], f[n][i][2])));
}
