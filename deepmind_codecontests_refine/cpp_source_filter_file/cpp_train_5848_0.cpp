#include <bits/stdc++.h>
using namespace std;
int n, m;
int h[55][55][55][2], s1[4];
int f[4][55][2005], g[55][55][2005], f1[55][55][2005];
vector<int> v[4];
inline long long Pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return res;
}
long long fac[200005], inv[200005], ff[200005];
inline long long C(long long a, long long b) {
  return fac[a] * inv[b] % 1000000007 * inv[a - b] % 1000000007;
}
inline void init() {
  for (int i = 0; i <= 1; i++) fac[i] = inv[i] = ff[i] = 1;
  for (int i = 2; i < 200005; i++) {
    fac[i] = fac[i - 1] * i % 1000000007;
    ff[i] = (1000000007 - 1000000007 / i) * ff[1000000007 % i] % 1000000007;
    inv[i] = inv[i - 1] * ff[i] % 1000000007;
  }
}
inline void H() {
  h[1][0][0][0] = h[0][1][0][1] = h[0][0][0][0] = 1;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
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
}
inline void F() {
  for (int l = 1; l <= 3; l++) {
    for (int i = 0; i < v[l].size(); i++) s1[l] += v[l][i];
    f[l][0][0] = 1;
    for (int i = 0; i < v[l].size(); i++)
      for (int j = i + 1; j >= 1; j--)
        for (int k = v[l][i]; k <= s1[l]; k++)
          (f[l][j][k] += f[l][j - 1][k - v[l][i]]) %= 1000000007;
  }
}
inline void G() {
  for (int i = 0; i <= v[1].size(); i++) {
    for (int j = 0; j <= s1[1]; j++) f1[i][0][j] = f[1][i][j];
    for (int j = 0; j < v[2].size(); j++)
      for (int k = j + 1; k >= 1; k--)
        for (int l = v[2][j]; l <= s1[1] + s1[2]; l++)
          (f1[i][k][l] += f1[i][k - 1][l - v[2][j]]) %= 1000000007;
  }
  for (int i = 0; i <= v[1].size(); i++)
    for (int j = 0; j <= v[2].size(); j++)
      for (int k = 0; k <= s1[1] + s1[2]; k++) {
        if (!f1[i][j][k]) continue;
        for (int l = 0; l <= i + j; l++)
          (g[i + j][l][k] += (long long)f1[i][j][k] *
                             (h[i][j][l][0] + h[i][j][l][1]) % 1000000007 *
                             fac[i] % 1000000007 * fac[j] % 1000000007) %=
              1000000007;
      }
}
int main() {
  init();
  scanf("%d%d", &n, &m);
  H();
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[y].push_back(x);
  }
  if (v[1].size() > v[2].size()) swap(v[1], v[2]);
  if (v[1].size() > v[3].size()) swap(v[1], v[3]);
  if (v[2].size() > v[3].size()) swap(v[2], v[3]);
  F();
  G();
  long long ans = 0;
  for (int i = 0; i <= min(s1[3], m); i++)
    for (int j = 0; j <= v[3].size(); j++) {
      if (!f[3][j][i]) continue;
      f[3][j][i] = (long long)f[3][j][i] * fac[j] % 1000000007;
      for (int k = max(0, j - 1); k <= v[1].size() + v[2].size(); k++)
        for (int l = 0; l <= min(j, k); l++)
          (ans += (long long)g[k][l][m - i] * f[3][j][i] % 1000000007 *
                  C(k + 1 - l, j - l) % 1000000007) %= 1000000007;
    }
  printf("%lld", ans);
}
