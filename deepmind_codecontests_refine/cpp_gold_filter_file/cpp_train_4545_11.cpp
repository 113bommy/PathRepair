#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 50, LIM = 12;
char ch[N], ans[N];
int n, lim, dp[N][N];
int main() {
  scanf("%s", ch + 1);
  n = strlen(ch + 1);
  for (lim = 1; (lim << 1) <= n; lim <<= 1)
    ;
  lim--;
  dp[0][0] = 1;
  for (int i = 0; i < n - lim; i++) {
    char c = 'z' + 1;
    for (int u = i; u <= n; ++u) {
      if (!dp[u][u - i]) continue;
      c = min(c, ch[u + 1]);
      for (int k = 1; k <= lim; k <<= 1) {
        if (u + k > n) break;
        if ((!((u + k - i) & k)) || (u - i) & k) continue;
        if (u + k - i > lim) continue;
        dp[u + k][u + k - i] = 1;
      }
    }
    ans[i + 1] = c;
    for (int u = i; u <= n; ++u)
      if (dp[u][u - i] && ch[u + 1] == c) dp[u + 1][u - i] = 1;
  }
  printf("%s", ans + 1);
}
