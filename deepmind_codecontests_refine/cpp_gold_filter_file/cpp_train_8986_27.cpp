#include <bits/stdc++.h>
const int N = 1050;
const double eps = 1e-5;
using namespace std;
inline int gi() {
  char ch = getchar();
  int x = 0, q = 0;
  while (ch < '0' || ch > '9') ch == '-' ? q = 1 : 0, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return q ? (-x) : x;
}
double f[2][N], b[2], g[N];
int a[2], hp[2], dt[2], l[2], r[2], p[2];
void dp(int t) {
  for (int i = 0; i <= hp[t]; ++i) g[i] = f[t][i], f[t][i] = 0;
  for (int i = 1; i <= hp[t]; ++i)
    for (int j = l[t ^ 1]; j <= r[t ^ 1]; ++j) {
      f[t][(i - j > 0 ? i - j : 0)] +=
          g[i] * p[t ^ 1] / 100 / (r[t ^ 1] - l[t ^ 1] + 1);
      f[t][i] += g[i] * (100 - p[t ^ 1]) / 100 / (r[t ^ 1] - l[t ^ 1] + 1);
    }
  return;
}
int main() {
  for (int i = 0; i < 2; ++i)
    hp[i] = gi(), dt[i] = gi(), l[i] = gi(), r[i] = gi(), p[i] = gi();
  if (p[0] == 100) return puts("0"), 0;
  if (p[1] == 100) return puts("1"), 0;
  for (int i = 0; i < 2; ++i) p[i] = 100 - p[i];
  b[0] = b[1] = f[0][hp[0]] = f[1][hp[1]] = 1;
  int t;
  double ans = 0;
  for (; b[0] > eps && b[1] > eps;) {
    if (a[0] <= a[1])
      t = 0;
    else
      t = 1;
    dp(t ^ 1), b[t ^ 1] = 0, a[t] += dt[t];
    for (int i = 1; i <= hp[t ^ 1]; ++i) b[t ^ 1] += f[t ^ 1][i];
    if (t == 0) ans += f[t ^ 1][0] * b[0];
  }
  printf("%.7lf", ans);
  return 0;
}
