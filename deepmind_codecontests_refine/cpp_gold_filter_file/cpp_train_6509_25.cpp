#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
const double eps = 1e-7;
const double pi = acos(-1.0);
const long long INF = (long long)2e9 + 1;
const long long LINF = (long long)8e18;
const long long inf = (long long)2e9 + 1;
const long long linf = (long long)8e18;
const long long MM = (long long)1e9 + 7;
int solve();
void gen();
int main() {
  solve();
  return 0;
}
const int dd = 2e5 + 7;
double T[dd], B[dd], A[dd];
int G[dd];
double cinf = 1e21;
double dp[57][dd];
double f(int l, int r) {
  double t1 = T[r] - T[l - 1];
  double t2 = B[r] - B[l - 1];
  double t3 = A[l - 1];
  return t1 - t2 * t3;
}
void dfs(int i, int l, int r, int oL, int oR) {
  if (l > r) return;
  int m = (l + r) / 2;
  int opt = -1;
  for (int k = max(oL, 1); k <= min(oR, m); k++) {
    if (dp[i][m] > dp[i - 1][k - 1] + f(k, m)) {
      dp[i][m] = dp[i - 1][k - 1] + f(k, m);
      opt = k;
    }
  }
  dfs(i, l, m - 1, oL, opt);
  dfs(i, m + 1, r, opt, oR);
}
int solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < (int)n; ++i) {
    scanf("%d", &G[i]);
    A[i + 1] = A[i] + G[i];
    B[i + 1] = B[i] + 1.0 / G[i];
    T[i + 1] = T[i] + A[i + 1] / G[i];
  }
  for (int i = 0; i < (int)k + 1; ++i) {
    for (int j = 0; j < (int)n + 1; ++j) {
      dp[i][j] = cinf;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i < (long long)k + 1; ++i) {
    dfs(i, 1, n, 1, n);
  }
  printf("%.10f", (double)dp[k][n]);
  return 0;
}
