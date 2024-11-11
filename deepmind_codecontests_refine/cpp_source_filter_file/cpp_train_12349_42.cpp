#include <bits/stdc++.h>
inline int getint() {
  register char ch;
  while (!isdigit(ch = getchar()))
    ;
  register int x = ch ^ '0';
  while (isdigit(ch = getchar())) x = (((x << 2) + x) << 1) + (ch ^ '0');
  return x;
}
const int N = 51, M = 5001;
const double eps = 1e-9;
int n, m, a[N], b[N], p[N];
double f[N][M];
inline bool check(const double &k) {
  for (register int i = n - 1; ~i; i--) {
    for (register int j = m + 1; j < M; j++) f[i + 1][j] = k;
    for (register int j = 0; j <= m; j++) {
      f[i][j] = std::min((f[i + 1][j + a[i]] + a[i]) * p[i] / 100 +
                             (f[i + 1][j + b[i]] + b[i]) * (100 - p[i]) / 100,
                         k);
    }
  }
  return f[0][0] < k;
}
int main() {
  n = getint(), m = getint();
  for (register int i = 0; i < n; i++) {
    a[i] = getint(), b[i] = getint(), p[i] = getint();
  }
  double l = 0, r = m;
  while (r - l > eps) {
    const double mid = (l + r) / 2;
    (check(mid) ? r : l) = mid;
  }
  printf("%.10f\n", r);
  return 0;
}
