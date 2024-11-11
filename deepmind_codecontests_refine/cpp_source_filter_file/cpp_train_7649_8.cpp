#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const double eps = 1e-10;
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
double a[2][2], range[2][2][2];
inline int sgn(double x) { return x < -eps ? -1 : x > eps; }
inline bool judge(double x) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      range[i][j][0] = -a[i][j] - x;
      range[i][j][1] = -a[i][j] + x;
    }
  double Range[2][2];
  for (int i = 0; i < 2; i++) {
    Range[i][0] = 1e20;
    Range[i][1] = -1e20;
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      Range[0][0] = min(Range[0][0], range[0][0][i] * range[1][1][j]);
      Range[0][1] = max(Range[0][1], range[0][0][i] * range[1][1][j]);
      Range[1][0] = min(Range[1][0], range[1][0][i] * range[0][1][j]);
      Range[1][1] = max(Range[1][1], range[1][0][i] * range[0][1][j]);
    }
  if (sgn(Range[0][0] - Range[1][0]) > 0)
    return sgn(Range[1][1] - Range[0][0]) >= 0;
  return sgn(Range[0][1] - Range[1][0]) >= 0;
}
signed main() {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) scanf("%lf", &a[i][j]);
  double l = 0, r = 1e9;
  int T = 6000000;
  while (T--) {
    double mid = (l + r) / 2;
    if (judge(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%lf", l);
  return 0;
}
