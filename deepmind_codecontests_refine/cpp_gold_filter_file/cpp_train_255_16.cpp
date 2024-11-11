#include <bits/stdc++.h>
using namespace std;
int dp[20000005], v[55][55];
char s[55][55];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  int nn = (1 << n);
  for (int i = 1; i < nn; i++) {
    dp[i] = 1e9;
  }
  for (int k = 0; k < nn; k++) {
    for (int i = 0; i < n; i++) {
      if (((k >> i) & 1) == 0) {
        for (int j = 1; j <= m; j++) {
          dp[k + (1 << i)] = min(dp[k + (1 << i)], dp[k] + v[i + 1][j]);
          int maxx = 0, ans = 0, c = 0;
          for (int ii = 0; ii < n; ii++) {
            if (s[ii + 1][j] == s[i + 1][j]) {
              maxx = max(maxx, v[ii + 1][j]);
              ans += v[ii + 1][j];
              c += (1 << ii);
            }
          }
          dp[k | c] = min(dp[k | c], dp[k] + ans - maxx);
        }
        break;
      }
    }
  }
  printf("%d\n", dp[nn - 1]);
  return 0;
}
