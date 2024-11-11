#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 105;
int n, m, p;
int f[N][M][2];
int pw[N], ans;
int main() {
  scanf("%d%d%d", &n, &p, &m);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 10 % p;
  f[0][0][0] = 1;
  for (int i = 0; i <= n - 1; ++i)
    for (int j = 0; j <= p - 1; ++j)
      for (int k = (i == n - 1); k <= 9; ++k) {
        int down = (j + k * pw[i]) % p;
        int &t = f[i + 1][down][down == 0 && k];
        (t += f[i][j][0]) %= m;
        (f[i + 1][down][1] += f[i][j][1]) %= m;
      }
  for (int i = 0; i <= p - 1; ++i) (ans += f[n][i][1]) %= m;
  printf("%d\n", ans);
  return 0;
}
