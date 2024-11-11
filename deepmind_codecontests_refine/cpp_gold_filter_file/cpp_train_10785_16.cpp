#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005, maxk = 2005;
int a[maxn], b[maxk];
long long dp[maxn][maxk], lastmin[maxn][maxk];
inline long long ABS(long long x) { return x >= 0 ? x : -x; }
int n, k, p;
int main() {
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &b[i]);
  }
  sort(a, a + n);
  sort(b, b + k);
  dp[0][0] = ABS(a[0] - b[0]) + ABS(b[0] - p);
  lastmin[0][0] = dp[0][0];
  for (int i = 1; i < k; i++) {
    dp[0][i] = ABS(a[0] - b[i]) + ABS(b[i] - p);
    lastmin[0][i] = min(lastmin[0][i - 1], dp[0][i]);
  }
  for (int i = 1; i < n; i++) {
    dp[i][i] = max(lastmin[i - 1][i - 1], ABS(a[i] - b[i]) + ABS(b[i] - p));
    lastmin[i][i] = dp[i][i];
    for (int j = i + 1; j < k; j++) {
      dp[i][j] = max(lastmin[i - 1][j - 1], ABS(a[i] - b[j]) + ABS(b[j] - p));
      lastmin[i][j] = min(lastmin[i][j - 1], dp[i][j]);
    }
  }
  long long ans = 1000000000000000000;
  for (int i = n - 1; i < k; i++) {
    ans = min(ans, dp[n - 1][i]);
  }
  cout << ans << endl;
  return 0;
}
