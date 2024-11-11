#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int fa[maxn], dp[maxn];
int ma[maxn];
int main() {
  int type = 2, n;
  scanf("%d", &n);
  n++;
  fa[1] = 1;
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &fa[i]);
    dp[i] = 1;
    int x;
    for (x = i; fa[x] != 1 && dp[x] >= ma[fa[x]]; x = fa[x]) {
      if (!ma[fa[x]]) {
        ma[fa[x]] = 1;
        break;
      }
      if (dp[x] == ma[fa[x]]) {
        if (dp[fa[x]] == ma[fa[x]])
          dp[fa[x]]++;
        else
          break;
      } else {
        ma[fa[x]] = dp[x];
        if (dp[fa[x]] == dp[x]) break;
        dp[fa[x]] = dp[x];
      }
    }
    if (fa[x] == 1) ans = max(ans, dp[x]);
    printf("%d%c", ans, i == n ? '\n' : ' ');
  }
}
