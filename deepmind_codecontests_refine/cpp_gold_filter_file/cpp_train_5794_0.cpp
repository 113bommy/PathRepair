#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 7, inf = 0x3f3f3f3f;
const int mod97 = 1e9 + 7, mod33 = 998244353;
const int drc[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, Q, K;
int a[MAX];
int dp[MAX];
void Solve() {
  for (int i = 1; i <= K + 1 && i <= n; ++i) {
    dp[i] = min(i + K, n) - max(i - K, 1) + 1;
    printf("%d ", dp[i]);
  }
  for (int i = K + 2; i <= n; ++i) {
    int j = a[i];
    if (j == 0)
      dp[i] = min(i + K, n) - max(i - K, 1) + 1;
    else if (j + K < i - K)
      dp[i] = dp[j] + (min(i + K, n) - max(i - K, 1) + 1);
    else
      dp[i] = dp[j] + (min(i + K, n) - min(j + K, n));
    printf("%d ", dp[i]);
  }
  puts("");
}
int Main() {
  int t = 1;
  while (t--) {
    while (~scanf("%d%d", &n, &K)) {
      for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
      Solve();
    }
  }
  return 0;
}
int main() { return Main(); }
