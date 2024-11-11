#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> edge[200100];
long long dp[200100];
long long ans[200100];
long long L[200100], R[200100];
long long get_inv(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % 1000000007;
    x = (x * x) % 1000000007;
    y >>= 1;
  }
  return ret;
}
void dfs1(int now, int fa) {
  dp[now] = 1;
  for (int i = 0; i < edge[now].size(); i++) {
    int to = edge[now][i];
    if (to == fa) continue;
    dfs1(to, now);
    dp[now] = (dp[now] * (dp[to] + 1)) % 1000000007;
  }
}
void dfs2(int now, int fa) {
  L[0] = 1, R[edge[now].size() - 1] = ans[now];
  for (int i = 0; i < edge[now].size(); i++) {
    int to = edge[now][i];
    if (to == fa) {
      L[i + 1] = L[i];
    } else
      L[i + 1] = L[i] * (dp[to] + 1) % 1000000007;
  }
  for (int i = edge[now].size() - 1; i > 0; i--) {
    int to = edge[now][i];
    if (to == fa) {
      R[i - 1] = R[i];
    } else
      R[i - 1] = R[i] * (dp[to] + 1) % 1000000007;
  }
  for (int i = 0; i < edge[now].size(); i++) {
    int to = edge[now][i];
    if (to == fa) continue;
    ans[to] = (L[i] * R[i] % 1000000007 + 1) % 1000000007;
  }
  for (int i = 0; i < edge[now].size(); i++) {
    int to = edge[now][i];
    if (to == fa) continue;
    dfs2(to, now);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    edge[i].push_back(x);
    edge[x].push_back(i);
  }
  dfs1(1, 0);
  ans[1] = 1;
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) {
    printf("%I64d", ans[i] * dp[i] % 1000000007);
  }
  puts("");
}
