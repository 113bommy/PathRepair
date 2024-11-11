#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e10 + 7, Maxn = 10000;
int i, n, j, a, ans, f[1000 + 10][Maxn * 2 + 10];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a);
    f[i][a + Maxn] = f[i][-a + Maxn] = 1;
    for (j = 0; j <= Maxn * 2; j++)
      if (f[i - 1][j]) {
        (f[i][j + a] += f[i - 1][j]) %= Mod;
        (f[i][j - a] += f[i - 1][j]) %= Mod;
      }
    (ans += f[i][Maxn]) %= Mod;
  }
  printf("%d\n", ans);
}
