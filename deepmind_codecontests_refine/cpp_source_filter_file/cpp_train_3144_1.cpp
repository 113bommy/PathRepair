#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 7;
int n, a[N], nex[N];
map<int, int> Map[N];
long long dp[N];
void init() {
  for (int i = 0; i <= n; i++) Map[i].clear(), dp[i] = 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    nex[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] == a[i + 1]) {
        nex[i] = i + 1;
        if (i + 2 <= n) swap(Map[i + 1], Map[i]);
        if (i + 2 <= n) Map[i][a[i + 2]] = i + 1;
      } else {
        nex[i] = Map[i + 1].count(a[i]) ? (Map[i + 1][a[i]] + 1) : 0;
        if (nex[i] && nex[i] + 1 <= n) {
          swap(Map[nex[i] + 1], Map[i]);
          Map[i][a[nex[i] + 1]] = nex[i];
        }
      }
    }
    long long ans = 0;
    dp[n + 1] = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (!nex[i]) continue;
      dp[i] = 1 + dp[nex[i] + 1];
      ans += dp[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
