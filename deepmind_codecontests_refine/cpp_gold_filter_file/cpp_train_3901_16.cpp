#include <bits/stdc++.h>
using namespace std;
int num[100005];
int mx[17][100005], mn[17][100005];
int dp[100005], mdp[17][100005];
int main() {
  int n, s, l;
  scanf("%d %d %d", &n, &s, &l);
  for (int i = (1); i <= (n); i += (1)) {
    scanf("%d", &num[i]);
    mx[0][i] = mn[0][i] = num[i];
  }
  for (int i = (1); i <= (16); i += (1))
    for (int j = (1); j <= (n); j += (1)) {
      mx[i][j] = mx[i - 1][j];
      mn[i][j] = mn[i - 1][j];
      int p = j - (1 << (i - 1));
      if (p >= 1) {
        mx[i][j] = max(mx[i][j], mx[i - 1][p]);
        mn[i][j] = min(mn[i][j], mn[i - 1][p]);
      }
    }
  dp[0] = 0;
  for (int k = (0); k <= (16); k += (1)) mdp[k][0] = 0;
  for (int i = (1); i <= (n); i += (1)) {
    dp[i] = 1000000000;
    int tmx = -1000000000 - 1000000000, tmn = 1000000000 + 1000000000, p = i;
    for (int k = (16); k >= (0); k -= (1)) {
      if (max(tmx, mx[k][p]) - min(tmn, mn[k][p]) > s) continue;
      tmx = max(tmx, mx[k][p]);
      tmn = min(tmn, mn[k][p]);
      p -= (1 << k);
      if (p < 1) {
        p = max(p, 0);
        break;
      }
    }
    int q = i - l;
    for (int k = (16); k >= (0); k -= (1)) {
      if (q - (1 << k) < p) continue;
      dp[i] = min(dp[i], mdp[k][q]);
      q -= (1 << k);
    }
    if (q >= p) dp[i] = min(dp[i], dp[p]);
    dp[i]++;
    mdp[0][i] = dp[i];
    for (int k = (1); k <= (16); k += (1)) {
      mdp[k][i] = mdp[k - 1][i];
      int p = i - (1 << (k - 1));
      if (p >= 0) mdp[k][i] = min(mdp[k][i], mdp[k - 1][p]);
    }
  }
  printf("%d\n", (dp[n] >= 1000000000) ? -1 : dp[n]);
  return 0;
}
