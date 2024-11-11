#include <bits/stdc++.h>
using namespace std;
long long dis[5][5], n, f[5][5][50], w[5][5];
long long dfs(long long at, long long to, long long sum) {
  if (f[at][to][sum]) return f[at][to][sum];
  if (sum == 1) {
    f[at][to][sum] = dis[at][to];
    return dis[at][to];
  }
  long long other = 6 - at - to;
  long long ans = dfs(at, other, sum - 1) + w[at][to] + dfs(other, to, sum - 1);
  ans = min(ans, dfs(at, to, sum - 1) + w[at][other] + dfs(to, at, sum - 1) +
                     w[other][to] + dfs(at, to, sum - 1));
  f[at][to][sum] = ans;
  return ans;
}
signed main() {
  for (register long long i = 1; i <= 3; i++)
    for (register long long j = 1; j <= 3; j++) {
      cin >> w[i][j];
      dis[i][j] = w[i][j];
    }
  for (register long long k = 1; k <= 3; k++)
    for (register long long i = 1; i <= 3; i++)
      for (register long long j = i + 1; j <= 3; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  cin >> n;
  cout << dfs(1, 3, n);
  return 0;
}
