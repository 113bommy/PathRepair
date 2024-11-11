#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int hp[2], dt[2], l[2], r[2];
double pi[2], f[2][4005][205], ans;
int main() {
  for (int i = 0; i <= 1; i++) {
    cin >> hp[i] >> dt[i] >> l[i] >> r[i] >> pi[i];
    pi[i] /= 100.0;
  }
  if (pi[0] == 1) return puts("0.000000"), 0;
  if (pi[1] == 1) return puts("1.000000"), 0;
  f[0][0][hp[0]] = f[1][0][hp[1]] = 1.0;
  for (int x = 1; x <= 4000; x++) {
    for (int i = 0; i <= 1; i++) {
      for (int j = 1; j <= hp[i]; j++) {
        if (f[i][x - 1][j] < eps) continue;
        for (int k = l[i ^ 1]; k <= r[i ^ 1]; k++) {
          f[i][x][max(0, j - k)] +=
              f[i][x - 1][j] * (1 - pi[i ^ 1]) / (r[i ^ 1] - l[i ^ 1] + 1);
        }
        f[i][x][j] += f[i][x - 1][j] * pi[i ^ 1];
      }
    }
    f[0][x][0] += f[0][x - 1][0];
  }
  for (int i = 1; i <= 4000; i++) {
    int T = ((i - 1) * dt[0] + dt[1] - 1) / dt[1];
    if (T > 4000) break;
    ans += (1 - f[0][T][0]) * f[1][i][0];
  }
  printf("%.6lf\n", ans);
  return 0;
}
