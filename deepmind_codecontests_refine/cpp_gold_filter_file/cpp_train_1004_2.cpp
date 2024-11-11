#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
const int MO = 1e9 + 7;
int n, p, c[500010];
long long f[500010][2][2][2], g[500010], ans, fac[500010], p2[500010],
    inv[500010];
long long C(int x, int y) { return fac[x] * inv[y] % MO * inv[x - y] % MO; }
int main() {
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) getint(c[i]);
  p2[0] = 1;
  for (int i = 1; i <= n; ++i) p2[i] = p2[i - 1] * 2 % MO;
  if (c[1] != 1) f[1][1][0][1] = 1;
  if (c[1] != 0) f[1][0][1][1] = 1;
  for (int i = 1; i <= n - 1; ++i)
    for (int j = 0; j <= 1; ++j)
      for (int k = 0; k <= 1; ++k)
        for (int l = 0; l <= 1; ++l) {
          long long t = f[i][j][k][l];
          if (!t) continue;
          if (c[i + 1] != 1) {
            if (k) {
              (f[i + 1][j][k][l] += t * p2[i - 1]) %= MO;
              (f[i + 1][j | 1][k][l ^ 1] += t * p2[i - 1]) %= MO;
            } else {
              (f[i + 1][j | 1][k][l ^ 1] += t * p2[i]) %= MO;
            }
          }
          if (c[i + 1] != 0) {
            if (j) {
              (f[i + 1][j][k][l] += t * p2[i - 1]) %= MO;
              (f[i + 1][j][k | 1][l ^ 1] += t * p2[i - 1]) %= MO;
            } else {
              (f[i + 1][j][k | 1][l ^ 1] += t * p2[i]) %= MO;
            }
          }
        }
  for (int j = 0; j <= 1; ++j)
    for (int k = 0; k <= 1; ++k) (ans += f[n][j][k][p]) %= MO;
  ans = (ans % MO + MO) % MO;
  cout << ans << endl;
  return 0;
}
