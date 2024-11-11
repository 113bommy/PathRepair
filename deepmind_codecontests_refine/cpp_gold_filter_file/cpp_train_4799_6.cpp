#include <bits/stdc++.h>
using namespace std;
const int N = 5009;
int f[N][N][2], n, a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  memset(f, 0x3f, sizeof f);
  f[0][0][0] = f[1][0][0] = f[1][1][1] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= (i + 1) / 2; j++) {
      if (!j) {
        f[i][j][0] = f[i - 1][j][0];
        continue;
      }
      f[i][j][0] =
          min(f[i - 1][j][0], f[i - 1][j][1] + max(0, a[i] - a[i - 1] + 1));
      if (i > 1)
        f[i][j][1] =
            min(f[i - 2][j - 1][0] + max(a[i - 1] - a[i] + 1, 0),
                f[i - 2][j - 1][1] +
                    max(0, max(a[i - 1] - a[i] + 1, a[i - 1] - a[i - 2] + 1)));
    }
  for (int i = 1; i <= (n + 1) / 2; i++)
    printf("%d ", min(f[n][i][1], f[n][i][0]));
  return 0;
}
