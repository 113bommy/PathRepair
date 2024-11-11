#include <bits/stdc++.h>
using namespace std;
template <typename tp>
inline void read(tp& x) {
  x = 0;
  char tmp;
  bool key = 0;
  for (tmp = getchar(); !isdigit(tmp); tmp = getchar()) key = (tmp == '-');
  for (; isdigit(tmp); tmp = getchar()) x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}
const int N = 1010;
double dp[N][N];
double calc(int n, int m) {
  if (m == 0) return 1;
  if (dp[n][m] != -1) return dp[n][m];
  double ret = 1.0 / (m + 1.0), a, b, c, d;
  if (n == 0) return dp[n][m] = ret;
  a = calc(m, n - 1), b = 1 - calc(m, n - 1);
  c = -1 / (m + 1.0), d = m / (m + 1.0) * (1 - calc(m - 1, n)) + 1 / (m + 1.0);
  double per = (d - b) / (a - c + 0.0);
  if (per < 0) per = 0;
  if (per > 1) per = 1;
  ret = max(a * per + b, ret);
  ret = max(c * per + d, ret);
  return dp[n][m] = ret;
}
int main() {
  int n, m;
  read(n), read(m);
  for (int i = 0; i <= max(n, m); ++i)
    for (int j = 0; j <= max(n, m); ++j) dp[i][j] = -1;
  printf("%.6lf %.6lf\n", calc(n, m), 1 - calc(n, m));
  return 0;
}
