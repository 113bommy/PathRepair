#include <bits/stdc++.h>
using namespace std;
int n, m;
double dp[2001][2001];
bool haverow[2001], havecol[2001];
void run() {
  scanf("%d%d", &n, &m);
  memset(haverow, false, sizeof(haverow));
  memset(havecol, false, sizeof(havecol));
  for (int i = (0); i < (m); ++i) {
    int r, c;
    scanf("%d%d", &r, &c);
    --r, --c;
    haverow[r] = true;
    havecol[c] = true;
  }
  int R = 0;
  for (int i = (0); i < (n); ++i)
    if (!haverow[i]) ++R;
  int C = 0;
  for (int i = (0); i < (n); ++i)
    if (!havecol[i]) ++C;
  dp[0][0] = 0;
  for (int r = (1); r <= (R); ++r) {
    double pr = 1.0 * r / n;
    dp[r][0] = (1 + pr * dp[r - 1][0]) / (1 - (1 - pr));
  }
  for (int c = (1); c <= (C); ++c) {
    double pc = 1.0 * c / n;
    dp[0][c] = (1 + pc * dp[0][c - 1]) / (1 - (1 - pc));
  }
  for (int r = (1); r <= (R); ++r)
    for (int c = (1); c <= (C); ++c) {
      double pr = 1.0 * r / n, pc = 1.0 * c / n;
      dp[r][c] = (1 + pr * pc * dp[r - 1][c - 1] +
                  pr * (1 - pc) * dp[r - 1][c] + (1 - pr) * pc * dp[r][c - 1]) /
                 (1 - (1 - pr) * (1 - pc));
    }
  printf("%.9lf\n", dp[R][C]);
}
int main() {
  run();
  return 0;
}
