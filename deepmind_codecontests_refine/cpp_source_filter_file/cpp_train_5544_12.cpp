#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 2e5 + 9, M = 1e6 + 1;
const int Maxn = 1000010;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
long long qp(long long x, long long y) {
  long long ans = 1;
  x %= mod;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long qp1(long long x, long long y) {
  long long ans = 1;
  x;
  while (y) {
    if (y & 1) ans = ans * x;
    x = x * x;
    y >>= 1;
  }
  return ans;
}
long long inv(long long x) { return qp(x, mod - 2); }
int n, m, k;
vector<int> G[N];
int dp[N], vis[N];
vector<int> cyc;
void dfs(int x, int fa = -1) {
  cyc.push_back(x);
  dp[x] = dp[fa] + 1;
  for (auto y : G[x]) {
    if (y == fa) continue;
    if (!dp[y])
      dfs(y, x);
    else {
      if (dp[x] - dp[y] + 1 >= 0 && dp[x] - dp[y] + 1 <= k) {
        puts("2");
        printf("%d\n", dp[y] - dp[x] + 1);
        for (int i = dp[y] - 1; i < dp[x]; i++) {
          printf("%d ", cyc[i]);
        }
        puts("");
        exit(0);
      }
    }
  }
  if (!vis[x])
    for (auto y : G[x]) vis[y] = 1;
  cyc.pop_back();
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1);
  puts("1");
  int cnt = 0;
  for (int i = 1, cnt = 0; i <= n; i++) {
    if (!vis[i]) {
      printf("%d ", i), cnt++;
      if (cnt >= (k + 1) / 2) break;
    }
  }
  puts("");
}
