#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000006];
bool dp[1006][1006];
int main() {
  scanf("%d %d", &n, &m);
  if (n >= m) {
    printf("YES");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] %= m;
  }
  memset(dp, false, sizeof(dp));
  for (int i = 0; i < n; i++) {
    dp[i][a[i]] = 1;
    for (int j = 0; j < m; j++) {
      if (dp[i - 1][j]) {
        dp[i][j] = 1;
        dp[i][(j + a[i]) % m] = 1;
      }
    }
  }
  if (dp[n - 1][0])
    printf("YES");
  else
    printf("NO");
  return 0;
}
