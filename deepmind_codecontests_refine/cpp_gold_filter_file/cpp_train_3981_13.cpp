#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<int> G[1000006];
int vis[1000006], dep[1000006], d, fa[1000006];
void dfs(int u) {
  vis[u] = 1;
  for (int v : G[u]) {
    if (vis[v] && (dep[u] - dep[v] + 1) >= d) {
      vector<int> cyc;
      int x = u;
      while (x != v) cyc.push_back(x), x = fa[x];
      cyc.push_back(v);
      puts("2");
      printf("%d\n", cyc.size());
      for (int t : cyc) printf("%d ", t);
      exit(0);
    } else if (!vis[v]) {
      fa[v] = u, dep[v] = dep[u] + 1;
      dfs(v);
    }
  }
}
int cn[1000006];
void solve() {
  cin >> n >> m;
  int u, v;
  for (int i = (1), iend = (m); i <= iend; ++i) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v), G[v].push_back(u);
  }
  d = sqrt(n) - 1;
  while (d * d < n) ++d;
  dfs(1);
  int t = d - 1;
  for (int i = 1; i <= n; ++i) cn[dep[i] % t]++;
  int ps = max_element(cn, cn + t) - cn;
  puts("1");
  vector<int> ans;
  for (int i = 1; i <= n; ++i)
    if (dep[i] % t == ps) ans.push_back(i);
  ans.resize(d);
  for (int x : ans) printf("%d ", x);
}
signed main() { solve(); }
