#include <bits/stdc++.h>
using namespace std;
int r, g, s, H;
long long dp[2][5000000];
int main() {
  scanf("%d %d", &r, &g);
  s = r + g;
  int h = 1;
  while ((h + 1) * (h + 2) / 2 <= s) h++;
  H = h;
  if (r > g) swap(r, g);
  dp[0][0] = 1;
  for (int i = 1; i <= H; i++) {
    for (int j = 0; j <= i * (i + 1) / 2; j++) {
      dp[i % 2][j] =
          (dp[(i + 1) % 2][j] + (j >= i ? dp[(i + 1) % 2][j - i] : 0)) %
          1000000007LL;
    }
  }
  long long tot = 0;
  for (int i = max((H + 1) * H / 2 - g, 0); i <= r; i++) {
    tot += dp[H % 2][i];
  }
  printf("%lld\n", tot % 1000000007LL);
}
