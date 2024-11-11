#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265359;
const int MAXT = 5000, MAXHP = 410;
double dp[MAXHP][2];
int hp[2], dt[2], l[2], r[2], dd[2];
double q[2];
int main() {
  for (int i = 0; i < 2; ++i) cin >> hp[i] >> dt[i] >> l[i] >> r[i] >> q[i];
  q[0] /= 100.0;
  q[1] /= 100.0;
  dd[0] = r[0] - l[0] + 1;
  dd[1] = r[1] - l[1] + 1;
  hp[0] += MAXHP / 2;
  hp[1] += MAXHP / 2;
  double ans = 0.0;
  double srazu_sdoh[2] = {0.0, 0.0};
  for (int tank = 0; tank < 2; ++tank) {
    dp[hp[!tank]][!tank] = q[tank];
    double pr = double(1 - q[tank]) / dd[tank];
    for (int i = l[tank]; i <= r[tank]; ++i) {
      dp[hp[!tank] - i][!tank] = pr;
      if (hp[!tank] - i <= MAXHP / 2) srazu_sdoh[!tank] += pr;
    }
  }
  ans += srazu_sdoh[1];
  for (int i = 1; i < 25000; ++i) {
    double palive = 0.0;
    int nesdoh[2] = {0, 0};
    for (int j = MAXHP / 2 + 1; j < MAXHP; ++j) {
      for (int tank = 0; tank < 2; ++tank) {
        if (dp[j][tank] > 1e-4) nesdoh[tank]++;
        if (!tank) palive += dp[j][tank];
      }
    }
    if (!nesdoh[0] || !nesdoh[1]) break;
    double sdoh[2] = {0.0, 0.0};
    for (int tank = 0; tank < 2; ++tank) {
      if (i % dt[tank] == 0) {
        for (int j = MAXHP / 2 + 1; j <= hp[!tank]; ++j) {
          double pred = dp[j][!tank];
          dp[j][!tank] = (q[tank]) * pred;
          double pr = pred * double(1 - q[tank]) / dd[tank];
          for (int k = l[tank]; k <= r[tank]; ++k) {
            dp[j - k][!tank] += pr;
            if (j - k <= MAXHP / 2) sdoh[!tank] += pr;
          }
        }
      }
    }
    ans += sdoh[1] * palive;
  }
  printf("%.6lf", ans);
  return 0;
}
