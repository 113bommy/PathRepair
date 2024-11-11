#include <bits/stdc++.h>
using namespace std;
int used[5000];
double vals[5000];
double dp[4100][4100];
int n;
double solve(int pos, int baixo) {
  int cima = pos - baixo;
  if (cima == n && baixo == n) return 0.0;
  double &ret = dp[pos][baixo];
  if (ret == ret) return ret;
  if (cima == n) {
    return ret = solve(pos + 1, baixo + 1) + fabs(vals[pos] - floor(vals[pos]));
  } else if (baixo == n) {
    return ret = solve(pos + 1, baixo) - fabs(vals[pos] - ceil(vals[pos]));
  }
  double v1 = solve(pos + 1, baixo + 1) + fabs(vals[pos] - floor(vals[pos]));
  double v2 = solve(pos + 1, baixo) - fabs(vals[pos] - ceil(vals[pos]));
  if (fabs(v1) < fabs(v2))
    ret = v1;
  else
    ret = v2;
  return ret;
}
int main() {
  scanf("%d", &n);
  vector<pair<double, int> > cima, baixo;
  double fsum = 0.0;
  for (int i = 0; i < 2 * n; i++) {
    double val;
    scanf("%lf", &val);
    vals[i] = val;
    fsum += val;
  }
  memset(dp, -1, sizeof(dp));
  printf("%.3f\n", fabs(solve(0, 0)));
  return 0;
}
