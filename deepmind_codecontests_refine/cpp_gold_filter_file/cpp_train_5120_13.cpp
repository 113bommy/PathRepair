#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
constexpr int maxn = 110;
pii v[maxn];
int dp[maxn][maxn];
int main() {
  int n, h;
  scanf("%d %d", &n, &h);
  for (int i = 1; i <= n; i++) scanf("%d %d", &v[i].first, &v[i].second);
  sort(v + 1, v + 1 + n, [](pii x, pii y) {
    if (x.second >= 0 && y.second >= 0) return x.first < y.first;
    if (x.second >= 0) return true;
    if (y.second >= 0) return false;
    return x.first + x.second > y.first + y.second;
  });
  for (int i = 0; i <= n; i++)
    for (int k = 0; k <= n; k++) dp[i][k] = -0x3f3f3f3f;
  for (int i = 0; i <= n; i++) dp[i][0] = h;
  for (int i = 1; i <= n; i++)
    for (int k = 1; k <= n; k++)
      dp[i][k] = max(dp[i - 1][k], (dp[i - 1][k - 1] >= v[i].first &&
                                            dp[i - 1][k - 1] + v[i].second >= 0
                                        ? dp[i - 1][k - 1] + v[i].second
                                        : -0x3f3f3f3f));
  bool ok = 0;
  for (int k = 0; k <= n; k++)
    if (dp[n][k] < 0) {
      printf("%d\n", k - 1);
      ok = 1;
      break;
    }
  if (!ok) printf("%d\n", n);
}
