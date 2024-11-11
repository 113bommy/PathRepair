#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int dp[maxn], num[30];
int main() {
  int i, j, k, n, m, t, l, ans, x, y, z;
  char s[maxn];
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s);
    ans = 1e9;
    memset(num, 0, sizeof(num));
    for (i = 0; i < k; i++) {
      num[s[i] - 'A' + 1]++;
    }
    for (l = 1; l <= 26; l++) {
      if (num[l] == 0) continue;
      for (i = 0; i <= k; i++) dp[i] = 0;
      dp[0] = 1;
      for (i = 1; i <= 26; i++) {
        if (num[i] == 0 || i == l) continue;
        for (j = k; j >= num[i]; j--)
          if (dp[j - num[i]] == 1) dp[j] = 1;
      }
      for (i = 0; i <= k; i++) {
        if (dp[i] == 1) {
          if (i + num[l] >= n) {
            x = max(0, n - i);
            z = k - num[l] - i;
            if (z + x >= m) {
              y = max(0, m - z);
              ans = min(ans, x * y);
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
