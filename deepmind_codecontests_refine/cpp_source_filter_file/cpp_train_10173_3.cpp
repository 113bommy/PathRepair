#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int n, m;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
double f[MAXN][MAXN];
inline double dp(int n, int m) {
  if (!n) return 1.0 / (m + 1);
  if (!m) return 1;
  if (f[n][m]) return f[n][m];
  double A, B, C, D;
  A = 1.0 * m / (m + 1) * (1 - dp(m - 1, n));
  B = 1.0 / (m + 1) + 1.0 * m / (m + 1) * (1 - dp(m - 1, n));
  C = 1;
  D = 1 - dp(m, n - 1);
  double p = (D - B) / (A + D - B - C);
  return f[n][m] = p * A + (1 - p) * B;
}
int main() {
  n = read();
  m = read();
  printf("%lg %lg\n", dp(n, m), 1 - dp(n, m));
  return 0;
}
