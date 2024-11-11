#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, siz[5], sum[5], jc[55], njc[55], f[5][55][2505],
    g[55][55][2505], u[55][55][2505], h[55][55][55][2];
vector<int> v[5];
int rd() {
  int x = 0, tp = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') tp = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x * 10 + c - '0');
    c = getchar();
  }
  return x * tp;
}
long long quick_mod(long long a, long long x) {
  long long res = 1;
  while (x) {
    if (x & 1) (res *= a) %= 1000000007;
    (a *= a) %= 1000000007, x >>= 1;
  }
  return res;
}
long long C(int n, int m) {
  if (n < m) return 0;
  return jc[n] * njc[m] % 1000000007 * njc[n - m] % 1000000007;
}
int main() {
  int x, y;
  n = rd(), m = rd();
  jc[0] = njc[0] = 1;
  for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % 1000000007;
  njc[n] = quick_mod(jc[n], 1000000007 - 2);
  for (int i = n - 1; i >= 1; i--) njc[i] = njc[i + 1] * (i + 1) % 1000000007;
  for (int i = 1; i <= n; i++) {
    x = rd(), y = rd();
    v[y].push_back(x);
  }
  if (v[1].size() > v[2].size()) swap(v[1], v[2]);
  if (v[1].size() > v[3].size()) swap(v[1], v[3]);
  if (v[2].size() > v[3].size()) swap(v[2], v[3]);
  for (int k = 1; k <= 3; k++) {
    f[k][0][0] = 1;
    siz[k] = v[k].size();
    for (int i = 0; i < siz[k]; i++) sum[k] += v[k][i];
    for (int i = 0; i < siz[k]; i++)
      for (int j = i + 1; j >= 1; j--)
        for (int s = v[k][i]; s <= sum[k]; s++)
          (f[k][j][s] += f[k][j - 1][s - v[k][i]]) %= 1000000007;
  }
  h[1][0][0][0] = h[0][1][0][1] = h[0][0][0][0] = 1;
  for (int i = 0; i <= siz[1]; i++)
    for (int j = 0; j <= siz[2]; j++)
      for (int k = 0; k <= i + j; k++) {
        if (!h[i][j][k][0])
          h[i][j][k][0] = ((i > 0 ? h[i - 1][j][k][1] : 0) +
                           (i > 1 && k > 0 ? h[i - 1][j][k - 1][0] : 0)) %
                          1000000007;
        if (!h[i][j][k][1])
          h[i][j][k][1] = ((j > 0 ? h[i][j - 1][k][0] : 0) +
                           (j > 1 && k > 0 ? h[i][j - 1][k - 1][1] : 0)) %
                          1000000007;
      }
  for (int i = 0; i <= siz[1]; i++) {
    for (int j = 0; j <= sum[1]; j++) u[i][0][j] = f[1][i][j];
    for (int j = 0; j < siz[2]; j++)
      for (int k = j + 1; k >= 1; k--)
        for (int s = v[2][j]; s <= sum[1] + sum[2]; s++)
          (u[i][k][s] += u[i][k - 1][s - v[2][j]]) %= 1000000007;
  }
  for (int i = 0; i <= siz[1]; i++)
    for (int j = 0; j <= siz[2]; j++)
      for (int k = 0; k <= sum[1] + sum[2]; k++)
        if (u[i][j][k])
          for (int p = 0; p <= i + j; p++)
            (g[i + j][p][k] += u[i][j][k] * (h[i][j][p][0] + h[i][j][p][1]) %
                               1000000007 * jc[i] % 1000000007 * jc[j] %
                               1000000007) %= 1000000007;
  int S = min(sum[3], m);
  for (int i = 0; i <= S; i++)
    for (int j = 0; j <= siz[3]; j++)
      if (f[3][j][i]) {
        (f[3][j][i] *= jc[j]) %= 1000000007;
        for (int k = max(0, j - 1); k <= siz[1] + siz[2]; k++)
          for (int p = 0; p <= min(j, k); p++)
            if (g[k][p][m - i])
              (ans += g[k][p][m - i] * f[3][j][i] % 1000000007 *
                      C(k + 1 - p, j - p) % 1000000007) %= 1000000007;
      }
  printf("%lld\n", ans);
  return 0;
}
