#include <bits/stdc++.h>
using namespace std;
inline long long pow(long long a, long long b, long long mo) {
  if (!a) return 0;
  long long tmp = 1;
  for (; b; b >>= 1) {
    if (b & 1) tmp = (long long)tmp * a % mo;
    a = (long long)a * a % mo;
  }
  return tmp;
}
template <class T>
inline void R(T &xx) {
  xx = 0;
  char ch = getchar();
  bool F = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') F = 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
  if (F) xx = -xx;
}
double p[1011], f[1011][1011];
int n, m, S, T, d[1011];
bool c[1011][1011];
inline int g(int i, int j) { return (i - 1) * n + j; }
inline double posi(int i, int j) {
  if (i == j) return p[i];
  if (!c[i][j]) return 0;
  return (1. - p[i]) / d[i];
}
int main() {
  R(n), R(m), R(S), R(T);
  int x, y, N = n * n;
  for (int i = (1); i <= (m); i++)
    R(x), R(y), c[x][y] = c[y][x] = 1, d[x]++, d[y]++;
  for (int i = (1); i <= (n); i++) scanf("%lf", &p[i]);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (i != S || j != T) {
        for (int k = (1); k <= (n); k++)
          for (int l = (1); l <= (n); l++)
            if (k != l) f[g(i, j)][g(k, l)] = -posi(k, i) * posi(l, j);
        f[g(i, j)][g(i, j)] += 1.;
      } else
        f[g(i, j)][g(i, j)] = f[g(i, j)][N + 1] = 1.;
  for (int i = (1); i <= (N); i++) {
    if (fabs(f[i][i]) < (1e-7))
      for (int j = (i + 1); j <= (N); j++)
        if (fabs(f[j][i]) > (1e-7)) {
          swap(f[i], f[j]);
          break;
        }
    for (int k = (N + 1); k >= (i); k--) f[i][k] /= f[i][i];
    for (int j = (1); j <= (N); j++)
      if (i != j)
        for (int k = (N + 1); k >= (i); k--) f[j][k] -= f[i][k] * f[j][i];
  }
  double al = 0.;
  for (int i = (1); i <= (n); i++) al += f[g(i, i)][N + 1];
  for (int i = (1); i <= (n); i++) printf("%.10f ", f[g(i, i)][N + 1] / al);
  return 0;
}
