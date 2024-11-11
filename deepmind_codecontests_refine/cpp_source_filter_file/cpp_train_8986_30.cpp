#include <bits/stdc++.h>
using namespace std;
double dp1[2006][202];
double dp2[2006][202];
int main() {
  int hp1, dt1, l1, r1, p1;
  int hp2, dt2, l2, r2, p2;
  cin >> hp1 >> dt1 >> l1 >> r1 >> p1;
  cin >> hp2 >> dt2 >> l2 >> r2 >> p2;
  if (p1 == 100) {
    cout << 0 << endl;
    return 0;
  }
  if (p2 == 100) {
    cout << 1 << endl;
    return 0;
  }
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));
  dp1[0][hp1] = 1;
  for (int i = 0; i < 2006 - 1; ++i)
    for (int j = hp1; j >= 0; --j) {
      dp1[i + 1][j] += dp1[i][j] * 0.01 * p2;
      for (int d = l2; d <= r2; ++d)
        dp1[i + 1][max(0, j - d)] +=
            dp1[i][j] * 0.01 * (100 - p2) / (r2 - l2 + 1);
    }
  dp2[0][hp2] = 1;
  for (int i = 0; i < 2006 - 1; ++i)
    for (int j = hp2; j >= 0; --j) {
      dp2[i + 1][j] += dp2[i][j] * 0.01 * p1;
      for (int d = l1; d <= r1; ++d)
        dp2[i + 1][max(0, j - d)] +=
            dp2[i][j] * 0.01 * (100 - p1) / (r1 - l1 + 1);
    }
  double ans = 0;
  for (int K = 1; K < 2006; ++K) {
    int T = 0;
    while ((K - 1) * dt1 > T * dt2 && T < 2006) ++T;
    if (0 <= T && T < 2006)
      ans += (1 - dp1[T][0]) * (dp2[K][0] - dp2[K - 1][0]);
  }
  cout << ans << endl;
  return 0;
}
