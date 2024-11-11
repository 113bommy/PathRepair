#include <bits/stdc++.h>
using namespace std;
double dp[2][1 << 8][2][444], p;
int x, k;
int main() {
  cin >> x >> k >> p;
  p /= 100;
  int ninth = (x & (1 << 8)) > 0;
  int cnt = 0;
  while (true) {
    cnt++;
    if (ninth != (x & (1 << (8 + cnt)))) break;
  }
  for (int a = 0; a < 2; a++)
    for (int b = 0; b < (1 << 8); b++)
      for (int c = 0; c < 1; c++)
        for (int d = 0; d < 444; d++) dp[a][b][c][d] = 0;
  dp[0][x & ((1 << 8) - 1)][ninth][cnt] = 1.;
  for (int step = 1; step <= k; step++) {
    for (int bit = 0; bit < (1 << 8); bit++) {
      for (int last = 0; last < 2; last++) {
        for (int cnt = 0; cnt < 444; cnt++) {
          double& now = dp[(step + 1) % 2][bit][last][cnt];
          int dmask = (bit << 1) & ((1 << 8) - 1);
          int dlast = (bit & (1 << 7)) > 0;
          int dcnt = cnt + 1;
          if (dlast != last) dcnt = 1;
          dp[step % 2][dmask][dlast][dcnt] += now * p;
          int amask = bit + 1;
          if (amask == (1 << 8)) {
            if (last == 1)
              dp[step % 2][0][0][cnt] += now * (1 - p);
            else
              dp[step % 2][0][1][1] += now * (1 - p);
          } else
            dp[step % 2][amask][last][cnt] += now * (1 - p);
          now = 0;
        }
      }
    }
  }
  double ans = 0;
  k %= 2;
  for (int bit = 1; bit < (1 << 8); bit++) {
    for (int last = 0; last < 2; last++) {
      for (int cnt = 0; cnt < 444; cnt++) {
        int s = 0, tmp = bit;
        while (tmp % 2 == 0) {
          s++;
          tmp /= 2;
        }
        ans += dp[k][bit][last][cnt] * s;
      }
    }
  }
  for (int cnt = 0; cnt < 444; cnt++) {
    ans += dp[k][0][0][cnt] * (8 + cnt);
    ans += dp[k][0][1][cnt] * 8;
  }
  cout.precision(10);
  cout << ans;
}
