#include <bits/stdc++.h>
using namespace std;
const int MAXN = 25005;
int n, x[MAXN], y[MAXN], dx[MAXN], dy[MAXN], s[MAXN];
double d[MAXN], ans = 1e29;
signed main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d%d%d%d", x + i, y + i, dx + i, dy + i, s + i),
        d[i] = sqrt(dx[i] * dx[i] + dy[i] * dy[i]) / s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      if (dx[i] * dy[j] == dy[i] * dx[j]) {
        if (dx[i] * (y[j] - y[i]) - dy[i] * (x[j] - x[i])) continue;
        if (dx[i] * (x[j] - x[i]) > 0 && dx[j] * (x[i] - x[j]) > 0)
          ans = min(ans, (x[j] - x[i]) * d[i] / dx[i] * s[i] / (s[i] + s[j]));
        else if (dx[i] * (x[j] - x[i]) > 0)
          ans = min(ans, (x[j] - x[i]) * d[i] / dx[i]);
        else if (dx[j] * (x[i] - x[j]) > 0)
          ans = min(ans, (x[i] - x[j]) * d[j] / dx[j]);
      } else {
        double c = dx[i] * dy[j] - dx[j] * dy[i];
        double t1 = -(dy[j] * (x[i] - x[j]) - dx[j] * (y[i] - y[j])) / c;
        double t2 = (dy[i] * (x[j] - x[i]) - dx[i] * (y[j] - y[i])) / c;
        if (t1 >= 0 && t2 >= 0) ans = min(ans, max(t1 * d[i], t2 * d[j]));
      }
    }
  if (ans > 1e28)
    puts("No show :(");
  else
    printf("%.6f", ans);
}
