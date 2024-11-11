#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 20) + 10;
const double PI = acos(-1);
double dp[MAXN];
int N;
double L, R;
double x[22], y[22], a[22];
int main() {
  memset(dp, 0, sizeof(dp));
  scanf("%d%lf%lf", &N, &L, &R);
  for (int ni = 0; ni < N; ni++) {
    scanf("%lf%lf%lf", x + ni, y + ni, a + ni);
    a[ni] = a[ni] * PI / 180;
  }
  int imax = 1 << N;
  for (int i = 0; i < imax; i++) dp[i] = L;
  bool flag = false;
  double ans = L;
  for (int i = 0; i < imax; i++) {
    if (flag) break;
    for (int j = 0; j < N; j++) {
      int tmpj = 1 << j;
      if (i & tmpj) continue;
      double dist = sqrt((dp[i] - x[j]) * (dp[i] - x[j]) + y[j] * y[j]);
      double alpha = acos((dp[i] - x[j]) / dist);
      if (alpha <= a[j]) {
        flag = true;
        ans = R;
        break;
      }
      double beta = alpha - a[j];
      int tmpi = i | tmpj;
      dp[tmpi] = max(dp[tmpi], dp[i] + dist * sin(a[j]) / sin(beta));
      ans = max(dp[tmpi], ans);
      if (fabs(ans - R) < 1e-6 || ans >= R) {
        flag = true;
        ans = R;
        break;
      }
    }
  }
  printf("%.9lf\n", ans - L);
  return 0;
}
