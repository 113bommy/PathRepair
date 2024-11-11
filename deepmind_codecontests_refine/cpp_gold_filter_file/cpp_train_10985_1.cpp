#include <bits/stdc++.h>
using namespace std;
pair<double, double> solve(double a, double b, double c) {
  double ans1, ans2;
  ans1 = (b - a + sqrt(max((a + b) * (a + b) - 4.0 * c, 0.0))) / 2.0;
  ans2 = (b - a - sqrt(max((a + b) * (a + b) - 4.0 * c, 0.0))) / 2.0;
  return pair<double, double>(ans1, ans2);
}
double mini[100005], maxi[100005], ans[2][100005], dp1 = 0, dp2 = 0, dp3 = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < int(n); ++i) scanf("%lf", &maxi[i]);
  for (int i = 0; i < int(n); ++i) scanf("%lf", &mini[i]);
  for (int i = 0; i < int(n); ++i) {
    double temp, chk;
    dp3 += maxi[i];
    tie(ans[0][i], temp) = solve(dp1, mini[i] + maxi[i] + dp2, dp3);
    chk = (ans[0][i] + dp1) * (maxi[i] + mini[i] - ans[0][i] + dp2);
    if (abs(chk - dp3) > 1e-7) swap(ans[0][i], temp);
    ans[1][i] = maxi[i] + mini[i] - ans[0][i];
    dp1 += ans[0][i];
    dp2 += ans[1][i];
  }
  for (int i = 0; i < int(n); ++i) printf("%.10lf ", ans[0][i]);
  printf("\n");
  for (int i = 0; i < int(n); ++i) printf("%.10lf ", ans[1][i]);
  printf("\n");
  return 0;
}
