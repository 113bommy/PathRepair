#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int n, m, q;
long long w, cnt[10];
long long pre[N];
long long dp[10][N];
int main() {
  scanf("%lld", &w);
  for (int i = 1; i <= 8; i++) scanf("%d", &cnt[i]);
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= 8; i++) {
    for (int j = 0; j <= 8 * 840; j++) {
      if (dp[i - 1][j] == -1) continue;
      long long x = min(840ll / i, cnt[i]);
      for (int k = 0; k <= x; k++)
        dp[i][j + k * i] =
            max(dp[i][j + k * i], dp[i - 1][j] + (cnt[i] - k) / (840 / i));
    }
  }
  long long ans = 0;
  for (int i = 0; i <= 840 * 8; i++) {
    if (dp[8][i] == -1 || i > w) continue;
    ans = max(ans, i + 840 * min(dp[8][i], (w - i) / 840));
  }
  printf("%lld\n", ans);
  return 0;
}
