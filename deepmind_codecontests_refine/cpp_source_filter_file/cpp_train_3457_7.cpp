#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, m, k, a[N], b[N], c[N], mx[N], dp[N];
vector<int> G[N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    mx[i] = i;
  }
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    mx[v] = max(mx[v], u);
  }
  for (int i = 1; i <= n; i++) G[mx[i]].push_back(c[i]);
  for (int i = k + 1; i < N; i++) dp[i] = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < a[i]; j++) dp[j] = -1;
    for (int j = N; j > b[i]; j--) dp[j] = dp[j - b[i]];
    for (auto v : G[i]) {
      for (int j = 0; j < N - 1; j++) {
        if (dp[j + 1] == -1) continue;
        dp[j] = max(dp[j], dp[j + 1] + v);
      }
    }
  }
  int ans = -1;
  for (int i = 0; i < N; i++) ans = max(ans, dp[i]);
  printf("%d\n", ans);
}
