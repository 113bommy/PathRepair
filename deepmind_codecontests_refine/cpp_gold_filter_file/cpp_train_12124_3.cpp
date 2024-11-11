#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 2e6 + 10;
int n, q, u, v, a[N], ans[N], L[N], p[M];
vector<int> g[N], st[M], f[M];
void go(int u = 1, int pr = -1, int d = 1) {
  L[u] = d;
  for (auto to : g[u])
    if (to != pr) go(to, u, d + 1);
}
void dfs(int u = 1, int pr = -1) {
  ans[u] = -1;
  for (auto it : f[a[u]]) {
    if (st[it].size() && (ans[u] == -1 || L[ans[u]] < L[st[it].back()]))
      ans[u] = st[it].back();
    st[it].push_back(u);
  }
  for (auto to : g[u])
    if (to != pr) dfs(to, u);
  for (auto it : f[a[u]]) st[it].pop_back();
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v), g[v].push_back(u);
  }
  for (int i = 2; i < M; i++)
    if (!p[i])
      for (int j = i; j < M; j += i) p[j] = i;
  for (int i = 2; i < M; i++) {
    int x = i;
    while (x > 1) {
      int j = p[x];
      f[i].push_back(j);
      while (x % j == 0) x /= j;
    }
  }
  go();
  dfs();
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &u);
      printf("%d\n", ans[u]);
    } else {
      scanf("%d%d", &u, &v);
      a[u] = v;
      dfs();
    }
  }
  return 0;
}
