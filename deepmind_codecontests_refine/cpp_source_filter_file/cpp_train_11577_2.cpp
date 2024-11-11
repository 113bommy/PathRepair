#include <bits/stdc++.h>
using namespace std;
const int mn = 5e5 + 10;
vector<int> g[mn], w[mn];
long long dp[mn], pen[mn];
int k;
void dfs(int x, int p) {
  vector<long long> pos;
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i], e = w[x][i];
    if (y == p) continue;
    dfs(y, x);
    dp[x] += dp[y];
    pos.push_back(e - pen[y]);
  }
  long long add = 0;
  sort(pos.begin(), pos.end(), greater<long long>());
  for (int i = 0; i < min((int)pos.size(), k); i++) add += max(0LL, pos[i]);
  dp[x] += add;
  if (pos.size() >= k) pen[x] = max(0LL, pos[k - 1]);
}
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, i;
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) g[i].clear(), w[i].clear();
    memset(dp, 0, 4 * (n + 10));
    memset(pen, 0, 4 * (n + 10));
    for (i = 0; i < n - 1; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      g[a].push_back(b);
      g[b].push_back(a);
      w[a].push_back(c);
      w[b].push_back(c);
    }
    dfs(1, 0);
    printf("%lld\n", dp[1]);
  }
}
