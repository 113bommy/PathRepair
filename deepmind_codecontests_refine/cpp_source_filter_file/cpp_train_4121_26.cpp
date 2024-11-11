#include <bits/stdc++.h>
using namespace std;
const int N = 35;
vector<int> g[N];
long long ans[N][2];
long long dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const long long LIM = 1e11;
long long delta[N];
int opposite(int d) {
  int ret;
  if (d == 0) ret = 1;
  if (d == 1) ret = 0;
  if (d == 2) ret = 3;
  if (d == 3) ret = 2;
  return ret;
}
bool dfs(int u, long long x, long long y, int prv, int prvd, int lvl) {
  ans[u][0] = x;
  ans[u][1] = y;
  if (g[u].size() > 4) return false;
  bool ret = true;
  int d = 0;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v != prv) {
      if (opposite(d) == prvd) d++;
      ret = ret && dfs(v, x + delta[lvl] * dir[d][0],
                       y + delta[lvl] * dir[d][1], u, d, lvl + 1);
      d++;
    }
  }
  return ret;
}
int main() {
  delta[0] = LIM;
  for (int i = 1; i < N; i++) delta[i] = delta[i - 1] / 2LL;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bool a = dfs(1, 0, 0, -1, -1, 0);
  printf("%s\n", a ? "YES" : "NO");
  if (a) {
    for (int i = 1; i <= n; i++) printf("%lld %lld\n", ans[i][0], ans[i][1]);
  }
  return 0;
}
