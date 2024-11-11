#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, q;
int s[2][N][N], Pow[N];
char inp[N];
int DaC(int x) {
  int j = 29, ret = 1;
  while (x > 1) {
    while (j >= 0 && x <= Pow[j]) j--;
    x -= Pow[j];
    ret ^= 1;
  }
  return ret;
}
int cell(int x, int y) { return (DaC(x) ^ DaC(y)); }
long long get(int x, int y) {
  if (!x || !y) return 0;
  int xx = x / n, yy = y / m;
  long long ret = 1ll * xx * yy / 2ll * 1ll * n * m;
  ret += (1ll * xx * yy & 1ll ? s[cell(xx, yy)][n][m] : 0);
  ret += 1ll * (xx / 2) * n * (y % m) + 1ll * (yy / 2) * (x % n) * m;
  if (xx & 1) ret += 1ll * s[cell(xx, yy + 1)][n][y % m];
  if (yy & 1) ret += 1ll * s[cell(xx + 1, yy)][x % n][m];
  ret += 1ll * s[cell(xx + 1, yy + 1)][x % n][y % m];
  return ret;
}
int main() {
  if (fopen("exam.inp", "r"))
    freopen("exam.inp", "r", stdin), freopen("exam.out", "w", stdout);
  Pow[0] = 1;
  for (int i = 1; i < 30; i++) Pow[i] = Pow[i - 1] * 2;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%s", inp + 1);
    for (int j = 1; j <= m; j++)
      s[0][i][j] =
          s[0][i - 1][j] + s[0][i][j - 1] - s[0][i - 1][j - 1] + inp[j] - '0',
      s[1][i][j] = i * j - s[0][i][j];
  }
  while (q--) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%lld\n", get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) +
                         get(x1 - 1, y1 - 1));
  }
}
