#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int n, a, b;
int t[5005][2];
int dp[5005][2];
vector<pair<int, int> > p;
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    p.push_back({a, b});
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; ++i) t[i][0] = p[i].first, t[i][1] = p[i].second;
  for (int i = n - 1; i > 0; --i) {
    for (int j = 0; j < 2; ++j) {
      dp[i][j] = inf;
      for (int k = 0; k < 2; ++k) {
        if (i == n - 1) {
          if (t[i - 1][j] <= t[i][k]) dp[i][j] = min(dp[i][j], t[i][k]);
        } else {
          if (t[i - 1][j] <= t[i][k]) dp[i][j] = min(dp[i][j], dp[i + 1][k]);
        }
      }
    }
  }
  if (n == 1) {
    printf("%d\n", min(t[0][0], t[1][1]));
    exit(0);
  }
  printf("%d\n", min(dp[1][0], dp[1][1]));
  return 0;
}
