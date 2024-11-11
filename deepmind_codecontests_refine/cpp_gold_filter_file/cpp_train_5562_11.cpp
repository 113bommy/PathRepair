#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, f[35][35][2], pw[35];
void Add(int &x, int y) {
  x = (x + y) % mod;
  return;
}
int main() {
  scanf("%d", &n);
  pw[0] = 1;
  for (int i = 1; i <= 30; i++) pw[i] = 1ll * pw[i - 1] * 2 % mod;
  f[30][0][1] = 1;
  for (int i = 30; i >= 1; i--)
    for (int j = 0; j <= 30; j++) {
      Add(f[i - 1][j + 1][0], f[i][j][0]);
      Add(f[i - 1][j][0], 1ll * pw[j] * f[i][j][0] % mod);
      int even = j ? pw[j - 1] : 1, odd = j ? pw[j - 1] : 0;
      if (!(n & (1 << (i - 1))))
        Add(f[i - 1][j][1], 1ll * even * f[i][j][1] % mod);
      else {
        Add(f[i - 1][j + 1][1], f[i][j][1]);
        Add(f[i - 1][j][0], 1ll * f[i][j][1] * even % mod);
        Add(f[i - 1][j][1], 1ll * f[i][j][1] * odd % mod);
      }
    }
  int ans = 0;
  for (int i = 0; i <= 30; i++) Add(ans, f[0][i][0]), Add(ans, f[0][i][1]);
  printf("%d\n", ans);
  return 0;
}
