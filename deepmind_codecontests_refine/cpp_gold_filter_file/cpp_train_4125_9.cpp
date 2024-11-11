#include <bits/stdc++.h>
using namespace std;
struct matrix {
  long long a[100][100];
  void init() { memset(a, 0, sizeof(a)); }
  friend matrix operator*(matrix x, matrix y) {
    matrix ans;
    ans.init();
    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++) {
        for (int k = 0; k < 100; k++)
          ans.a[i][j] += (x.a[i][k] * y.a[k][j]) % 1000000007;
        ans.a[i][j] %= 1000000007;
      }
    return ans;
  }
  friend matrix operator^(matrix x, long long y) {
    matrix ans;
    if (y == 0) {
      memset(ans.a, 0, sizeof(ans.a));
      for (int i = 0; i < 100; i++) ans.a[i][i] = 1;
      return ans;
    } else
      while ((y & 1) == 0) y >>= 1, x = x * x;
    ans = x;
    y >>= 1;
    for (; y != 0; y >>= 1) {
      x = x * x;
      if ((y & 1) != 0) ans = ans * x;
    }
    return ans;
  }
} x;
int n, m, Mod, a[1000010];
int main() {
  x.init();
  matrix h, t;
  h.init();
  t.init();
  scanf("%d%d%d", &n, &m, &Mod);
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    h.a[0][v % Mod]++;
  }
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    a[i] = v;
    for (int j = 0; j < Mod; j++) x.a[j][(j + v) % Mod]++;
  }
  matrix ans = h * (x ^ (m - 2));
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    int d = (Mod - (v + a[i]) % Mod) % Mod;
    t.a[d][0]++;
  }
  ans = ans * t;
  printf("%I64d\n", ans.a[0][0]);
}
