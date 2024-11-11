#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 60;
int q, fa[N], n = 1;
double dp[N][M + 5];
int main() {
  ios::sync_with_stdio(false);
  cin >> q;
  int opt, pos;
  for (int i = 0; i <= M; i++) dp[1][i] = 1;
  for (int _ = 1; _ <= q; _++) {
    cin >> opt >> pos;
    if (opt == 1) {
      fa[++n] = pos;
      for (int i = 0; i <= M; i++) dp[n][i] = 1;
      double pre = 1;
      int pp = n;
      for (int i = 0, cur = pos; cur && i <= M; i++, cur = fa[cur]) {
        double tmp = dp[cur][i];
        dp[cur][i] /= 0.5 * (pre + 1);
        if (i)
          dp[cur][i] *= 0.5 * (1 + dp[pp][i - 1]);
        else
          dp[cur][i] *= 0.5;
        pp = cur;
        pre = tmp;
      }
    } else {
      double ans = 0;
      for (int i = 1; i <= M; i++) ans += (dp[pos][i] - dp[pos][i - 1]) * i;
      printf("%.10lf\n", ans);
    }
  }
  return 0;
}
