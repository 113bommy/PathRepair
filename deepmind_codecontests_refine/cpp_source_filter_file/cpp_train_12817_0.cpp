#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, k, w;
vector<int> edge[300005], cost[300005];
int A[300005];
long long dp[300005], res;
void DFS(int x, int y) {
  for (int i = (0); i < (edge[x].size()); i++) {
    if (edge[x][i] == y) continue;
    DFS(edge[x][i], x);
  }
  dp[x] = A[x];
  long long a = 0, b = 0;
  for (int i = (0); i < (edge[x].size()); i++) {
    if (edge[x][i] == y) continue;
    dp[x] = max(dp[x], dp[edge[x][i]] + A[i] - cost[x][i]);
    long long tmp = dp[edge[x][i]] - cost[x][i];
    if (tmp > a) {
      b = a;
      a = tmp;
    } else if (tmp > b)
      b = tmp;
  }
  res = max(res, a + b + A[x]);
  res = max(res, dp[x]);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &A[i]);
  for (int i = (0); i < (n - 1); i++) {
    scanf("%d %d %d", &x, &y, &z);
    edge[x].push_back(y), edge[y].push_back(x);
    cost[x].push_back(z), cost[y].push_back(z);
  }
  DFS(1, 0);
  printf("%lld\n", res);
  return 0;
}
