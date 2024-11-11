#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
const int INF = 2e9 + 7;
int n, k, p;
int a[N], b[N];
int dp[N][N];
int main() {
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 1; i < int(n + 1); i++) scanf("%d", &a[i]);
  for (int i = 1; i < int(k + 1); i++) scanf("%d", &b[i]);
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  for (int j = 0; j < int(k + 1); j++) dp[0][j] = 0;
  for (int i = 1; i < int(n + 1); i++) {
    dp[i][0] = INF;
    for (int j = 1; j < int(k + 1); j++) {
      dp[i][j] = min(max(abs(a[i] - b[j]) + abs(b[j] - p), dp[i - 1][j - 1]),
                     dp[i][j - 1]);
    }
  }
  printf("%d\n", dp[n][k]);
  return 0;
}
