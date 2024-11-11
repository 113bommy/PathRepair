#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int NN = 110;
const int MM = 55;
int dp[MM][MM][MM][NN], c[NN][NN];
void add(int &u, int v) {
  u += v;
  if (u >= mod) u -= mod;
}
int main() {
  for (int i = (0); i < (NN); i++)
    for (int j = (0); j < (i + 1); j++) {
      c[i][j] = (i == 0 || j == 0) ? 1 : (c[i - 1][j] + c[i - 1][j - 1]);
      c[i][j] = min(c[i][j], NN);
    }
  int N, M, K, ans = 0, i, s, lst, w, res, nxt;
  scanf("%d%d%d", &N, &M, &K);
  dp[0][0][0][1] = 1;
  for (i = 0; i < M && i <= N / 2; i++) {
    for (s = 0; s <= N / 2; s++) {
      for (lst = 0; lst <= N / 2; lst++) {
        for (w = 1; w <= K; w++) {
          res = dp[i][s][lst][w];
          if (!res) continue;
          if (i > 0) add(ans, 1LL * res * (M - i) % mod);
          for (nxt = 1; nxt + s <= N / 2; nxt++) {
            int ww = nxt * c[lst + nxt - 1][nxt - 1];
            if (ww <= K) add(dp[i + 1][s + nxt][nxt][ww], res);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
