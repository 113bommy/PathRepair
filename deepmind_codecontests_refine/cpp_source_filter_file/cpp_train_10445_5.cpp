#include <bits/stdc++.h>
using namespace std;
int c[101];
double b[101];
double n, k, p, l;
double dp[203][203][410];
double solve(int ne, int le, int ke) {
  if (le < 0) return 0;
  if (ke > 200) ke = 200;
  if (ne < le) return 0;
  if (ne == 0 && le == 0) {
    if (ke < 0) return 0;
    return 1;
  }
  if (dp[ne][le][ke + 200] > -1) return dp[ne][le][ke + 200];
  return dp[ne][le][ke + 201] =
             solve(ne - 1, le - 1, ke + c[ne - 1]) * b[ne - 1] +
             solve(ne - 1, le, ke) * (1 - b[ne - 1]);
}
int main() {
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i] /= 100.0;
  }
  for (int j = 0; j < n; j++) cin >> c[j];
  for (int nn = 0; nn < 201; nn++)
    for (int ll = 0; ll < 201; ll++)
      for (int kk = 0; kk < 410; kk++) dp[nn][ll][kk] = -1;
  double zew = 0;
  for (int nn = l; nn <= n; nn++) zew += solve(n, nn, k);
  printf("%.9f", zew);
  return 0;
}
