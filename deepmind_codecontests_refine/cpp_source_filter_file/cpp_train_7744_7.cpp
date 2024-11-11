#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, n, m, res;
int a[4009][4009], pref[4009][4009], dp[4009][4009];
inline int cost(int l, int r) {
  int sum = pref[r][r] - pref[l - 1][r] - pref[r][l - 1] + pref[l - 1][l - 1];
  return sum / 2;
}
void build(int h, int L, int R, int tl, int tr) {
  if (L > R) return;
  int tm = (L + R) / 2;
  int best = -1, res;
  dp[h][tm] = ((int)1e9 + 9ll);
  for (int i = tl; i < tm && i <= tr; i++) {
    res = dp[h - 1][i] + cost(i + 1, tm);
    if (dp[h][tm] > res) {
      dp[h][tm] = res;
      best = i;
    }
  }
  build(h, L, tm - 1, tl, best);
  build(h, tm + 1, R, best, tr);
}
int main() {
  scanf("%lld %lld", &n, &m);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%lld", &a[i][j]);
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
    }
  }
  for (i = 1; i <= n; i++) dp[1][i] = cost(1, i);
  for (i = 2; i <= m; i++) {
    build(i, 1, n, 1, n);
  }
  printf("%lld\n", dp[m][n]);
  exit(0);
}
