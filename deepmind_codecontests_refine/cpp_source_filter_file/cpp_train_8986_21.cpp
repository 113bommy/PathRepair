#include <bits/stdc++.h>
using namespace std;
int turn[1024], sz = 0;
double dp1[1 << 16][202];
double dp2[1 << 16][202];
int MAXTO = 3500;
double h1, d1, l1, r1, p1;
double h2, d2, l2, r2, p2;
void scan() {
  cin >> h1 >> d1 >> l1 >> r1 >> p1;
  cin >> h2 >> d2 >> l2 >> r2 >> p2;
}
void init() {
  for (int i = 0; i < d1 * d2; ++i)
    if (i % (int)d1 == 0 && i % (int)d2 == 0)
      turn[sz++] = 3;
    else if (i % (int)d1 == 0)
      turn[sz++] = 1;
    else if (i % (int)d2 == 0)
      turn[sz++] = 2;
}
inline int MAX(int t1, int t2) { return (t1 > t2) ? t1 : t2; }
inline int MIN(int t1, int t2) { return (t1 < t2) ? t1 : t2; }
void solve(double dp[1 << 16][202], double h, double l, double r, double p,
           int me) {
  dp[0][0] = 1;
  for (int i = 0; i < MAXTO; ++i) {
    double sum[202];
    if ((turn[i % sz] & me) == 0) {
      for (int j = 0; j < h; ++j) dp[i + 1][j] = dp[i][j];
      continue;
    }
    for (int j = 0; j < 202; ++j) sum[j] = 0;
    for (int j = 0; j < h; ++j) {
      double cur = dp[i][j] / (r - l + 1) * ((100 - p) / 100.);
      int out = MIN(j + r - h, r - l + 1);
      if (out < 0) out = 0;
      dp[i + 1][(int)h] += (out * cur);
      if (j + l <= h) sum[j + (int)l] += cur;
      if (j + r + 1 <= h) sum[j + (int)r + 1] += (-cur);
      dp[i + 1][j] = dp[i][j] * (p / 100.);
    }
    double sm = 0;
    for (int j = 0; j <= h; ++j) {
      sm += sum[j];
      dp[i + 1][j] += sm;
    }
  }
}
void solve() {
  init();
  if (p1 == 100) {
    printf("0\n");
    return;
  }
  if (p2 == 100) {
    printf("1\n");
    return;
  }
  solve(dp1, h2, l1, r1, p1, 1);
  solve(dp2, h1, l2, r2, p2, 2);
  double ans = 0, other = 0, ended = 0;
  for (int i = 0; i < MAXTO; ++i) {
    ans += (dp1[i][(int)h2] * (1 - ended));
    ended += ((dp2[i][(int)h1]));
  }
  printf("%.12f\n", ans);
}
int main() {
  scan();
  solve();
}
