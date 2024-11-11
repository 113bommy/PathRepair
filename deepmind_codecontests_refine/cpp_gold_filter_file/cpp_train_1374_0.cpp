#include <bits/stdc++.h>
using namespace std;
int t, n, m;
vector<int> e[((int)1001 * 1000)], er[((int)1001 * 1000)], tpl;
bool mark[((int)1001 * 1000)];
void dfs(int x) {
  mark[x] = 1;
  for (auto u : er[x])
    if (!mark[u]) dfs(u);
  tpl.push_back(x);
}
void dfs2(int x) {
  mark[x] = 1;
  for (auto u : e[x])
    if (!mark[u]) dfs2(u);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) e[i].clear(), er[i].clear();
    for (int i = 0; i < m; i++) {
      int v, u;
      scanf("%d%d", &v, &u);
      if (u != v) e[v].push_back(u), er[u].push_back(v);
    }
    tpl.clear();
    for (int i = 1; i <= n; i++)
      if (!mark[i]) dfs(i);
    int x = tpl.back();
    for (int i = 1; i <= n; i++) mark[i] = 0;
    dfs2(x);
    bool flg = 1;
    vector<int> v1, v2;
    for (int i = 1; i <= n; i++) {
      if (mark[i])
        v1.push_back(i);
      else
        v2.push_back(i);
      mark[i] = 0;
    }
    if (!v1.size() || !v2.size()) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    cout << v1.size() << " " << v2.size() << "\n";
    for (auto u : v1) cout << u << " ";
    cout << "\n";
    for (auto u : v2) cout << u << " ";
    cout << "\n";
  }
  return 0;
}
