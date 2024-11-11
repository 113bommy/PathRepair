#include <bits/stdc++.h>
using namespace std;
const int N = 3e4;
const int M = 30;
int n, m;
char typ[7];
namespace AtoB {
long double f0[N + 3][M + 3], g0[N + 3][M + 3], f1[N + 3][M + 3],
    g1[N + 3][M + 3];
long double Prob(int x) {
  return x == m ? 1.0 / (1ll << m) : 1.0 / (1ll << x + 1);
}
void solve() {
  for (int j = 0; j <= m; j++) {
    f0[1][j] = g0[1][j] = f1[1][j] = g1[1][j] = Prob(j);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= j; k++) {
        f0[i][j] += f0[i - 1][k] * Prob(j);
        g0[i][j] += (g0[i - 1][k] + (1ll << k) * f0[i - 1][k]) * Prob(j);
      }
      f1[i][j] = f0[i][j];
      g1[i][j] = g0[i][j];
      for (int k = 0; k < j; k++) {
        f0[i][j] += f0[i - 1][j] * Prob(k);
        g0[i][j] += g0[i - 1][j] * Prob(k);
      }
    }
  }
  long double ans = 0.0;
  for (int j = 0; j <= m; j++) {
    for (int i = 1; i < n; i++) {
      for (int k = 0; k < j; k++) {
        long double tmp = f1[i][j] * (g0[n - i][k] - f0[n - i][k]) +
                          g1[i][j] * f0[n - i][k] +
                          (1ll << k) * f1[i][j] * f0[n - i][k];
        ans += tmp;
      }
    }
    long double tmp = g1[n][j];
    ans += tmp;
  }
  printf("%.9lf\n", (long double)ans);
}
}  // namespace AtoB
namespace BtoA {
void solve() { printf("%d.000000000\n", n); }
}  // namespace BtoA
int main() {
  scanf("%s", typ);
  scanf("%d%d", &n, &m);
  if (typ[0] == 'A') {
    AtoB::solve();
  } else if (typ[0] == 'B') {
    BtoA::solve();
  }
  return 0;
}
