#include <bits/stdc++.h>
using namespace std;
const int N = 1000050, M = 5050;
int g[M][M], f[2][M], L, l[N], ml[N], v[N], n, m, mo;
inline void cal(int &x, int y) {
  x += y;
  if (x >= mo) x -= mo;
  return;
}
int main() {
  cin >> n >> m >> mo;
  for (int i = 1; i <= n; ++i) scanf("%d", &l[i]), L = (l[i] > L ? l[i] : L);
  ml[0] = 1, v[0] = 1;
  for (int i = 1; i <= m; ++i)
    ml[i] = 1ll * ml[i - 1] * (m - i + 1) % mo, v[i] = 1ll * v[i - 1] * i % mo;
  g[0][0] = g[1][1] = 1;
  for (int i = 2; i <= L; ++i)
    for (int j = 1; j <= m && j <= i; ++j)
      cal(g[i][j], (1ll * g[i - 1][j] * (j - 1) + g[i - 1][j - 1]) % mo);
  f[0][0] = 1;
  int t = 0, s;
  for (int i = 1; i <= n; ++i) {
    t ^= 1, s = 0;
    if (i > 1)
      for (int j = 0; j <= l[i - 2]; ++j) f[t][j] = 0;
    for (int j = 0; j <= m && j <= l[i]; ++j) cal(s, f[t ^ 1][j]);
    for (int j = 1; j <= m && j <= l[i]; ++j) {
      cal(f[t][j], 1ll * ml[j] * g[l[i]][j] % mo * s % mo);
      cal(f[t][j], mo - 1ll * v[j] * g[l[i]][j] % mo * f[t ^ 1][j] % mo);
    }
  }
  s = 0;
  for (int j = 1; j <= m; ++j) cal(s, f[t][j]);
  cout << s;
  return 0;
}
