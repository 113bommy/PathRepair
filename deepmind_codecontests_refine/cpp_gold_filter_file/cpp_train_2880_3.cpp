#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
inline long long rd() {
  long long x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
double g[2][N << 1][N << 1], p[N];
int n, pre[N << 1];
namespace task1 {
int main() {
  printf("%.10lf\n", p[0]);
  return 0;
}
}  // namespace task1
namespace task2 {
int main() {
  printf("%.10lf\n", (p[0] + p[n]) / 2);
  return 0;
}
}  // namespace task2
int main() {
  n = rd();
  for (int i = 0; i <= n; i++) scanf("%lf", &p[i]);
  bool no1 = false, no2 = false;
  for (int i = 1; i <= n; i++) no1 |= (fabs(p[i] - p[i - 1]) > (1e-7));
  for (int i = 0; i <= n; i++) no2 |= (fabs(p[i] - p[1] * i) > (1e-7));
  if (!no1)
    task1::main();
  else if (!no2)
    task2::main();
  else {
    memset(g[0], -63, sizeof(g[0]));
    for (int j = 0; j <= n << 1; j++) {
      for (int x = 0, y = n; x <= n && x <= j; x++, y--)
        if (j - x + y <= n << 1) {
          g[0][j][j - x + y] = p[x];
        }
    }
    int nw = 1, la = 0;
    for (int h = 1; h <= 22; h++) {
      memset(g[nw], -63, sizeof(g[nw]));
      for (int k = 0; k <= n << 1; k++)
        for (int i = 0; i <= n << 1; i++)
          for (int j = 0; j <= n << 1; j++)
            g[nw][i][j] = max(g[nw][i][j], g[la][i][k] + g[la][k][j]);
      nw ^= 1, la ^= 1;
    }
    double ans = 0;
    for (int j = 0; j <= n << 1; j++) ans = max(ans, p[0] + g[la][n][j]);
    printf("%.10lf\n", ans / (double)((1ll << 22) + 1));
  }
  return 0;
}
