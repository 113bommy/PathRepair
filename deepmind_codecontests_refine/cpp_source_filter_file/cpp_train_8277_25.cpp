#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e5 + 10;
const int K = 10;
double dp[N][K];
int par[N];
void solve(int n) {
  int curv = 2;
  memset(dp, 0, sizeof dp);
  for (int i = 1; i < K; i++) dp[1][i] = 1.0;
  par[1] = -1;
  for (int i = 0; i < n; i++) {
    int type, v;
    cin >> type >> v;
    if (type == 1) {
      par[curv] = v;
      dp[curv][0] = 0.0;
      for (int i = 1; i < K; i++) dp[curv][i] = 1.0;
      assert(par[curv] == v);
      double old_val = dp[v][1];
      dp[v][1] *= (0.5 + 0.5 * dp[curv][0]);
      int cv = v;
      for (int i = 2; i < K; i++) {
        int u = par[cv];
        assert(u != 0);
        if (u == -1) break;
        double nold = dp[u][i];
        dp[u][i] /= (0.5 + 0.5 * old_val);
        dp[u][i] *= (0.5 + 0.5 * dp[cv][i - 1]);
        old_val = nold;
        cv = u;
      }
      curv++;
    } else {
      double ans = 0;
      for (int i = 1; i < K; i++) {
        ans += (1.0 - dp[v][i]);
      }
      printf("%.12f\n", (double)ans);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) solve(n);
}
