#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int fr[100010], dp[100010];
vector<int> g[100010];
int memo(int x) {
  if (fr[x] == 1) return dp[x];
  fr[x] = 1;
  int sol = 0;
  for (unsigned int i = 0; i < g[x].size(); i++)
    if (g[x][i] < x) sol = max(sol, memo(g[x][i]));
  return dp[x] = sol + 1;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (fr[i] == 0) dp[i] = memo(i);
  long long int sol = 0;
  for (int i = 1; i <= n; i++) {
    long long int y = g[i].size();
    sol = max(sol, 1LL * y * dp[i]);
  }
  printf("%d", sol);
  return 0;
}
