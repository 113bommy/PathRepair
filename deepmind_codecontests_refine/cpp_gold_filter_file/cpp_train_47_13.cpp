#include <bits/stdc++.h>
const int MAXN = 1e5 + 5;
const int inf = 2e9 + 5;
int dp[MAXN][2];
std::pair<int, int> ar[MAXN];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d %d", &ar[i].first, &ar[i].second);
  std::sort(ar + 1, ar + 1 + N);
  ar[0].first = -inf;
  ar[N + 1].first = inf;
  for (int i = N; i >= 1; i--) {
    for (int j = 0; j < 2; j++) {
      int &ret = dp[i][j];
      ret = dp[i + 1][0];
      if (ar[i].first + ar[i].second < ar[i + 1].first)
        ret = std::max(ret, dp[i + 1][1] + 1);
      if (j) {
        if (ar[i - 1].first + ar[i - 1].second + ar[i].second < ar[i].first)
          ret = std::max(ret, dp[i + 1][0] + 1);
      } else {
        if (ar[i - 1].first + ar[i].second < ar[i].first)
          ret = std::max(ret, dp[i + 1][0] + 1);
      }
    }
  }
  printf("%d\n", dp[1][0]);
  return 0;
}
