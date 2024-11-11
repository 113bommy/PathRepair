#include <bits/stdc++.h>
using namespace std;
int n, data[100005], in[100005];
double g[100005][105];
double ans;
double sum[100005 * 105];
inline double C(int x, int y) {
  double ret = sum[x] - sum[x - y] - sum[y];
  return ret;
}
int main() {
  scanf("%d", &n);
  int tol = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
    in[i] = data[i];
    tol += data[i];
    g[i][data[i]] = 1.0;
    ans += g[i][0];
  }
  for (int i = 1; i <= tol; i++) sum[i] = sum[i - 1] + log(i);
  int m;
  scanf("%d", &m);
  while (m--) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    x--, y--;
    ans -= g[x][0];
    for (int i = 1; i <= in[x]; i++) {
      if (fabs(g[x][i]) < 1e-10) continue;
      double tmp = log(g[x][i]);
      g[x][i] = 0;
      for (int k = 0; k <= w; k++)
        if (i >= k && data[x] - i >= w - k) {
          double h = tmp + C(i, k) + C(data[x] - i, w - k) - C(data[x], w);
          g[x][i - k] += exp(h);
        }
    }
    ans += g[x][0];
    printf("%.12f\n", ans);
    data[x] -= w;
    data[y] += w;
  }
  return 0;
}
