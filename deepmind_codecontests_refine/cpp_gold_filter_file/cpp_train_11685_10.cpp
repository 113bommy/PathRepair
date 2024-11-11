#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
using namespace std;
const int MAX_N = 2e5 + 5;
vector<int> g[MAX_N];
vector<pair<int, int> > ans;
int mx;
void dfs(int u, int fa, int t) {
  ans.push_back(pair<int, int>(u, t));
  int tmp = t, son = g[u].size() - (u != 1);
  for (auto v : g[u])
    if (v != fa) {
      if (t == mx) {
        t = mx - son - 1;
        ans.push_back(pair<int, int>(u, t));
      }
      t++;
      dfs(v, u, t);
      ans.push_back(pair<int, int>(u, t));
    }
  if (u != 1 && t != tmp - 1) ans.push_back(pair<int, int>(u, tmp - 1));
}
int main() {
  int n;
  scanf("%d", &n);
  for (register int i = 1; i <= n - 1; ++i) {
    int u, v;
    scanf("%d", &u), scanf("%d", &v);
    g[u].push_back(v), g[v].push_back(u);
  }
  for (register int i = 1; i <= n; ++i) mx = max(mx, (int)g[i].size());
  dfs(1, -1, 0);
  printf("%d\n", ans.size());
  for (auto x : ans) printf("%d %d\n", x.first, x.second);
  return 0;
}
