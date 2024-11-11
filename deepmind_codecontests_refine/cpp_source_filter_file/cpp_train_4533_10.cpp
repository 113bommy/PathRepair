#include <bits/stdc++.h>
using namespace std;
const int MaxN = 22, MaxS = 1 << 20, MaxM = 100010;
int f[MaxN][MaxS];
int n, m, col[MaxM];
int main() {
  static char s[MaxM];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; ++j)
      if (s[i] == '1') col[i] |= (1 << i);
  }
  for (int i = 1; i <= m; ++i) f[0][col[i]] = 1;
  int full = 1 << n;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < full; ++j) {
      if (i >= 2) f[i][j] = (i - 2 - n) * f[i - 2][j];
      for (int k = 0; k < n; ++k) f[i][j] += f[i - 1][j ^ (1 << k)];
      f[i][j] /= i;
    }
  int ans = n * m;
  for (int j = 0; j < full; ++j) {
    int now = 0;
    for (int i = 0; i <= n; ++i) now += f[i][j] * min(i, n - i);
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
