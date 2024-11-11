#include <bits/stdc++.h>
const int M = 5e5 + 10;
int n, q;
int a[M];
int dp[M], cnt[M];
bool vis[M];
std::vector<int> g[M];
void table() {
  dp[1] = 1;
  for (int i = 1; i < M; i++) {
    if (dp[i]) g[i].push_back(i);
    for (int j = i + i; j < M; j += i) {
      if (dp[i]) g[j].push_back(i);
      dp[j] -= dp[i];
    }
  }
}
int main() {
  table();
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long ans = 0;
  while (q--) {
    int x;
    scanf("%d", &x);
    if (vis[x]) {
      for (int i : g[a[x]]) ans -= 1ll * dp[i] * (--cnt[i]);
    } else {
      for (int i : g[a[x]]) {
        ans += 1ll * dp[i] * (cnt[i]++);
      }
    }
    vis[x] ^= 1;
    printf("%I64d\n", ans);
  }
  return 0;
}
