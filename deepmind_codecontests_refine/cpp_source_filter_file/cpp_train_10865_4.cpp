#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 4e3 + 7;
int n, a[N];
int dp[N][N];
void Init() {
  for (int i = (1); i < (n + 1); ++i) scanf("%d", a + i);
}
int Solve() {
  int ans = 0;
  for (int i = (1); i < (n + 1); ++i) dp[0][i] = 1;
  for (int i = (2); i < (n + 1); ++i) {
    int pre = 0;
    for (int j = (1); j < (i); ++j) {
      dp[j][i] = dp[pre][j] + 1;
      ans = max(ans, dp[j][i]);
      if (a[i] == a[j]) pre = j;
    }
  }
  return printf("%d\n", ans);
}
int main() {
  while (~scanf("%d", &n)) {
    Init();
    Solve();
  }
  return 0;
}
