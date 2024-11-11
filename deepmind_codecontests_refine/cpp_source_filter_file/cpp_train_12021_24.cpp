#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int n, l;
int x[MAXN], b[MAXN], p[MAXN];
double lb, ub, mid, ans;
double dp[MAXN], c[MAXN][MAXN];
bool solve(double t) {
  dp[0] = 0;
  memset(p, -1, sizeof(p));
  for (int i = 1; i <= n; i++) {
    double tb = t * b[i];
    dp[i] = 1e30;
    for (int j = 0; j < i; j++) {
      double t_ans = dp[j] + c[j][i] - tb;
      if (t_ans < dp[i]) {
        dp[i] = t_ans;
        p[i] = j;
      }
    }
  }
  return dp[n] <= 0;
}
void init() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) c[i][j] = sqrt(abs(x[j] - x[i] - l));
  lb = 0;
  ub = sqrt(abs(x[n] - l)) / b[n] + 10;
}
void prt(int idx) {
  if (idx == 0) return;
  prt(p[idx]);
  if (idx == n)
    printf("%d\n", idx);
  else
    printf("%d ", idx);
}
int main() {
  cin >> n >> l;
  x[0] = 0;
  b[0] = 1;
  for (int i = 1; i <= n; i++) cin >> x[i] >> b[i];
  init();
  while (abs(lb - ub) > 1e-6) {
    mid = (lb + ub) / 2;
    if (solve(mid)) {
      ub = mid;
      ans = mid;
    } else {
      lb = mid;
    }
  }
  solve(ans);
  prt(n);
  return 0;
}
