#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 250, MAXM = 21000;
long long n, m;
vector<long long> g[MAXN];
vector<long long> g_rev[MAXN];
long long used[MAXN];
long long comp[MAXN];
vector<long long> ans;
vector<long long> order;
long long col = 0;
void dfs(long long v) {
  used[v] = 1;
  for (long long i = 0; i < (long long)g[v].size(); ++i)
    if (!used[g[v][i]]) dfs(g[v][i]);
  order.push_back(v);
}
void scc(long long v) {
  used[v] = 1;
  comp[v] = col;
  for (long long i = 0; i < (long long)g_rev[v].size(); ++i)
    if (!used[g_rev[v][i]]) scc(g_rev[v][i]);
}
signed main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; ++i) {
    long long v, u, flag;
    cin >> v >> u >> flag;
    --u, --v;
    if (flag) {
      g[v].push_back(u);
      g_rev[u].push_back(v);
      g[u].push_back(v);
      g_rev[v].push_back(u);
      g[v + n].push_back(u + n);
      g[u + n].push_back(v + n);
      g_rev[v + n].push_back(u + n);
      g_rev[u + n].push_back(v + n);
    } else {
      g[v + n].push_back(u);
      g_rev[u].push_back(v + n);
      g[u + n].push_back(v);
      g_rev[v].push_back(u + n);
      g[v].push_back(u + n);
      g_rev[u + n].push_back(v);
      g[u].push_back(v + n);
      g_rev[v + n].push_back(u);
    }
  }
  for (long long i = 0; i < 2 * n; ++i) used[i] = 0;
  for (long long i = 0; i < 2 * n; ++i)
    if (!used[i]) dfs(i);
  reverse(order.begin(), order.end());
  for (long long i = 0; i < 2 * n; ++i) used[i] = 0;
  for (long long i = 0; i < (long long)order.size(); ++i)
    if (!used[order[i]]) {
      ++col;
      scc(order[i]);
    }
  for (long long i = 0; i < n; ++i) {
    if (comp[i] == comp[i + n]) {
      cout << "Impossible" << endl;
      return 0;
    }
    if (comp[i + n] < comp[i]) ans.push_back(i + 1);
  }
  assert((long long)ans.size() <= n);
  cout << (long long)ans.size() << endl;
  for (long long i = 0; i < (long long)ans.size(); ++i) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
