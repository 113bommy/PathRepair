#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
double dp[maxn][maxn];
double p[maxn][maxn], pr[maxn][maxn];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int N = (1 << n);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> p[i][j];
      p[i][j] /= 100;
    }
  }
  int xo = 1023;
  double answer = 0;
  for (int lev = 0; lev < n; lev++) {
    for (int player = 0; player < N; player++) {
      int op = player ^ (1 << lev);
      op = op & xo;
      double maxi = 0;
      for (int off = 0; off < (1 << lev); off++) {
        double val;
        if (lev == 0) {
          val = p[player][op + off] * (1 << lev);
          pr[lev][player] = p[player][op + off];
        } else {
          val = p[player][op + off] * (1 << lev) * pr[lev - 1][player] *
                pr[lev - 1][op + off];
          pr[lev][player] +=
              p[player][op + off] * pr[lev - 1][player] * pr[lev - 1][op + off];
          maxi = max(maxi, dp[lev - 1][op + off]);
        }
        dp[lev][player] += val;
      }
      if (lev) dp[lev][player] += dp[lev - 1][player] + maxi;
      answer = max(answer, dp[lev][player]);
    }
    xo -= (1 << lev);
  }
  cout << setprecision(12) << answer << endl;
  return 0;
}
