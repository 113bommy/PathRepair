#include <bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9 + 7);
pair<int, int> a[2000 + 20];
int cnt;
int H[2000 + 20];
long long dp[2000 + 20];
struct EDGE {
  int v, next;
} edge[2000 * 2 + 20];
bool flag[2000 + 20];
void addedge(int u, int v) {
  cnt++;
  edge[cnt].v = v;
  edge[cnt].next = H[u];
  H[u] = cnt;
}
void dfs(int u, int fa) {
  dp[u] = 1;
  for (int i = H[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == fa) continue;
    if (!flag[v]) continue;
    if (dp[v] == -1) dfs(v, u);
    dp[u] = dp[u] * (dp[v] + 1) % mod;
  }
}
int main() {
  int d, n;
  scanf("%d%d", &d, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  cnt = 0;
  memset(H, -1, sizeof(H));
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  sort(a + 1, a + 1 + n);
  int lef = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (; a[i].first - a[lef].first > d; lef++) {
      flag[a[lef].second] = false;
    }
    flag[a[i].second] = true;
    memset(dp, -1, sizeof(dp));
    dfs(a[i].second, 0);
    ans = (ans + dp[a[i].second]) % mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
