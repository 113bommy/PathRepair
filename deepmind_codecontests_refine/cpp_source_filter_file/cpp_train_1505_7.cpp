#include <bits/stdc++.h>
using namespace std;
int dp[100008], n, fa[100008];
int mx[100008], num[100008];
int main() {
  cin >> n;
  int ans = 0;
  memset(mx, -1, sizeof(mx));
  for (int i = 2; i <= n + 1; i++) {
    scanf("%d", &fa[i]);
    dp[i] = 0;
    int now = i, p;
    while ((p = fa[now]) != 1) {
      int newdp = 0;
      if (dp[now] > mx[p]) {
        mx[p] = dp[now];
        newdp = dp[now];
        num[p] = 1;
      } else if (dp[now] == mx[p]) {
        if (num[p]++ == 1) {
          newdp = dp[p] + 1;
        }
      }
      if (newdp > dp[p])
        dp[p] = newdp;
      else
        break;
      now = p;
    }
    printf("%d ", ans = max(ans, dp[now] + 1));
  }
  return 0;
}
