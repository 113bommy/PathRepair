#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
int d[10][2];
double f[10][3];
double ans = 0;
void dfs(int p, int t, double g, int flag, int o);
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &d[i][0], &d[i][1]);
  for (int t = 1; t <= 10000; t++) {
    for (int i = 1; i <= n; i++) {
      if (t > d[i][1])
        f[i][0] = 0;
      else if (t <= d[i][1] && t >= d[i][0])
        f[i][0] = (d[i][1] - t) * 1.0 / (d[i][1] - d[i][0] + 1);
      else
        f[i][0] = 1;
      if (t >= d[i][0] && t <= d[i][1])
        f[i][1] = 1.0 / (d[i][1] - d[i][0] + 1);
      else
        f[i][1] = 0;
      if (t > d[i][1])
        f[i][2] = 1;
      else if (t <= d[i][1] && t >= d[i][0])
        f[i][2] = (t - d[i][0]) * 1.0 / (d[i][1] - d[i][0] + 1);
      else
        f[i][2] = 0;
    }
    dfs(1, t, 1, 0, 0);
  }
  printf("%.15lf", ans);
  return 0;
}
void dfs(int p, int t, double g, int flag, int o) {
  if (p == n + 1) {
    if ((o == 1 && flag != 0) || (o == 0 && flag >= 2)) ans += t * g;
    return;
  }
  for (int i = 0; i < 3; i++) {
    int a = flag, b = o;
    if (i == 0) b++;
    if (i == 1) a++;
    dfs(p + 1, t, g * f[p][i], a, b);
  }
}
