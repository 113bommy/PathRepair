#include <bits/stdc++.h>
using namespace std;
const int N = 160;
int f[2][N][N * N];
int a[N], n, m, s;
int main() {
  scanf("%d%d%d", &n, &m, &s);
  s += m * (m + 1) / 2;
  s = min(s, (n + n - m + 1) * m / 2);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  memset(f, 0x3f3f3f3f, sizeof(f));
  f[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int e = min(i, m);
    for (int j = 1; j <= e; j++) {
      for (int k = i; k <= s; k++)
        f[i & 1][j][k] =
            min(f[(i & 1) ^ 1][j][k], f[(i & 1) ^ 1][j - 1][k - i] + a[i]);
      for (int k = 0; k < i; k++) f[i & 1][j][k] = f[(i & 1) ^ 1][j][k];
    }
    for (int j = 0, k = 0; k <= s; k++) f[i & 1][j][k] = f[(i & 1) ^ 1][j][k];
  }
  int ans = 0x7f7f7f7f;
  for (int i = m * (m + 1) / 2; i <= s; i++) ans = min(ans, f[n & 1][m][i]);
  printf("%d", ans);
  return 0;
}
