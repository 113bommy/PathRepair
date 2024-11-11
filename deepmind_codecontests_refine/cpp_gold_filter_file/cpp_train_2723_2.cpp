#include <bits/stdc++.h>
const int P = 998244353, XN = 50 + 5;
int Pow(long long base, int v) {
  long long res = 1;
  for (; v; v >>= 1, (base *= base) %= P)
    if (v & 1) (res *= base) %= P;
  return res;
}
int Mul(long long x, int const &y) { return x * y % P; }
void AddBy(int &x, int const &y) { ((x += y) >= P) && (x -= P); }
int inv[XN * XN];
int Frac(int x, int y) { return (long long)x * inv[y] % P; }
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  static int f[XN][XN][XN];
  int n, m;
  std::cin >> n >> m;
  static int like[XN], w[XN];
  for (int i = 1; i <= n; ++i) std::cin >> like[i];
  int sum[] = {0, 0};
  for (int i = 1; i <= n; ++i) {
    std::cin >> w[i];
    sum[like[i]] += w[i];
  }
  for (int k = 1; k <= sum[1] + sum[0] + m; ++k) inv[k] = Pow(k, P - 2);
  for (int x = 1; x <= n; ++x) {
    sum[like[x]] -= w[x];
    for (int i = 1; i <= m; ++i)
      for (int j = 0; j <= m; ++j)
        for (int k = 0; k <= m; ++k) f[i][j][k] = 0;
    f[0][0][0] = 1;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j <= i; ++j)
        for (int k = 0; k <= i; ++k) {
          int a = like[x] ? w[x] + j : w[x] - j, b = sum[1] + k,
              c = sum[0] - (i - (j + k));
          if (a != 0)
            AddBy(f[i + 1][j + 1][k], Mul(f[i][j][k], Frac(a, a + b + c)));
          AddBy(f[i + 1][j][k + 1], Mul(f[i][j][k], Frac(b, a + b + c)));
          AddBy(f[i + 1][j][k], Mul(f[i][j][k], Frac(c, a + b + c)));
        }
    int Ans = 0;
    for (int j = 0; j <= m; ++j)
      for (int k = 0; k <= m; ++k)
        AddBy(Ans, Mul(like[x] ? w[x] + j : w[x] - j, f[m][j][k]));
    sum[like[x]] += w[x];
    std::cout << Ans << '\n';
  }
  return 0;
}
