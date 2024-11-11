#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> mp[N];
int n, m, vi[N], dfn[N], cnt;
bool dfs(int u, int fa) {
  dfn[u] = ++cnt;
  vi[u] = 1;
  vector<int> unp;
  for (int i = 0; i < mp[u].size(); ++i) {
    int to = mp[u][i];
    if (to == fa) continue;
    if (!vi[to]) {
      if (!dfs(to, u)) {
        unp.push_back(to);
      }
    } else if (dfn[to] < dfn[u]) {
      unp.push_back(to);
    }
  }
  bool r = 0;
  if ((int(unp.size())) & 1) {
    printf("%d %d %d\n", unp.back(), u, fa);
    unp.pop_back();
    r = 1;
  }
  for (int i = 0; i < (int(unp.size())); i += 2) {
    printf("%d %d %d\n", unp[0], u, unp[1]);
  }
  return r;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    mp[a].push_back(b);
    mp[b].push_back(a);
  }
  if (m & 1) return puts("No solution"), 0;
  dfs(1, 1);
  return 0;
}
