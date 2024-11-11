#include <bits/stdc++.h>
using namespace std;
const int N = 111;
int Tc, n;
double pw[N], f[N][N][10 * N], T, C;
pair<int, int> p[N];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
int main(void) {
  scanf("%d", &Tc);
  pw[0] = 10. / 9;
  for (int i = 1; i <= 100; i++) {
    pw[i] = pw[i - 1] * pw[0];
  }
  while (Tc--) {
    scanf("%d%lf%lf", &n, &C, &T);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k <= 10 * j; k++) {
          f[i][j][k] = 1e15;
        }
      }
    }
    f[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k <= 10 * j; k++) {
          f[i + 1][j][k] = min(f[i + 1][j][k], f[i][j][k]);
          f[i + 1][j + 1][k + p[i + 1].second] =
              min(f[i + 1][j + 1][k + p[i + 1].second],
                  f[i][j][k] + pw[j] * p[i + 1].first);
        }
      }
    }
    int ans = 0;
    for (int j = 1; j <= n; j++) {
      double t = T - j * 10;
      for (int k = 0; k <= 10 * j; k++) {
        double delta = (t * C - 1) * (t * C - 1) + 4 * C * (t - f[n][j][k]);
        if (delta >= 0) {
          double x = ((1 - t * C) - sqrt(delta)) / (2 * -C);
          double y = ((1 - t * C) + sqrt(delta)) / (2 * -C);
          if (x >= 0 || y >= 0) {
            ans = max(ans, k);
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
