#include <bits/stdc++.h>
using namespace std;
inline int Readint() {
  int ret = 0;
  int f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f *= -1;
  } while (ch >= 0 && (ch < '0' || ch > '9'));
  while ('0' <= ch && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
void open() {
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
}
void close() {
  fclose(stdin);
  fclose(stdout);
}
int n, k;
int x[100030];
int sx, sy;
int xk;
double dis(int x) { return sqrt(1.0 * sy * sy + 1.0 * (sx - x) * (sx - x)); }
void init() {
  n = Readint(), k = Readint();
  for (int i = 1, _END_ = n; i <= _END_; i++) x[i] = Readint();
  xk = x[k];
  sort(x + 1, x + 1 + n);
  sx = Readint(), sy = Readint();
}
double A(int l, int r) { return min(dis(x[l]), dis(x[r])) + x[r] - x[l]; }
double B(int l, int r) {
  return x[r] - x[l] +
         min(dis(x[l]) + fabs(xk - x[r]), dis(x[r]) + fabs(xk - x[l]));
}
void work() {
  double ans = B(1, n);
  for (int i = 2, _END_ = n; i <= _END_; i++)
    ans = min(ans, min(A(1, i - 1) + B(i, n), B(1, i - 1) + A(i, n)));
  printf("%.15lf\n", ans);
}
int main() {
  int _ = 0;
  init();
  if (k == n + 1)
    printf("%.15lf\n", min(dis(x[1]), dis(x[n])) + x[n] - x[1]);
  else
    work();
  close();
  return 0;
}
