#include <bits/stdc++.h>
using namespace std;
const int _ = 1e2;
const int maxn = 2e5 + _;
const int maxm = 3e3 + _;
const int mod = 998244353;
inline int ad(int x, int y) { return x >= mod - y ? x - mod + y : x + y; }
inline int re(int x, int y) { return x < y ? x - y + mod : x - y; }
inline int mu(int x, int y) { return (long long)x * y % mod; }
inline int qp(int x, long long y) {
  int r = 1;
  while (y) {
    if (y & 1) r = mu(r, x);
    x = mu(x, x);
    y >>= 1;
  }
  return r;
}
inline int iv(int x) { return qp(x, mod - 2); }
inline int dv(int x, int y) { return mu(x, qp(y, mod - 2)); }
int a[maxn], w[maxn];
int f[maxm][maxm], minv[maxm], st;
int inv(int x) {
  if (minv[x - st] == 0) minv[x - st] = iv(x);
  return minv[x - st];
}
int main() {
  int n, m, sd, Su = 0, Sv = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]), (a[i] ? Sv : Su) += w[i];
  st = Sv + Su - m + 3;
  f[0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= i; j++) {
      int S = Su + Sv - j + (i - j);
      S = inv(S);
      f[i + 1][j + 1] = ad(f[i + 1][j + 1], mu(f[i][j], mu(Su - j, S)));
      f[i + 1][j] = ad(f[i + 1][j], mu(f[i][j], mu(Sv + (i - j), S)));
    }
  }
  int Eu = 0, Ev = 0;
  for (int j = 0; j <= m; j++) {
    Eu = ad(Eu, mu(f[m][j], Su - j));
    Ev = ad(Ev, mu(f[m][j], Sv + (m - j)));
  }
  Su = iv(Su), Sv = iv(Sv);
  for (int i = 1; i <= n; i++)
    if (a[i])
      printf("%d\n", mu(mu(w[i], Sv), Ev));
    else
      printf("%d\n", mu(mu(w[i], Su), Eu));
  return 0;
}
