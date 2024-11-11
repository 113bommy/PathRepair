#include <bits/stdc++.h>
using namespace std;
int src, s, n, m, deg_in[100005];
set<int> G[100005];
vector<pair<int, int> > e;
void adjust(int mid) {
  if (s < mid) {
    for (int i = s + 1; i <= mid; i++) {
      int u = e[i].first, v = e[i].second;
      G[u].insert(v);
    }
  } else if (s > mid) {
    for (int i = mid + 1; i <= s; i++) {
      int u = e[i].first, v = e[i].second;
      G[u].erase(v);
    }
  }
  s = mid;
}
void dfs(int u, bool *vis, stack<int> &stk) {
  if (vis[u]) return;
  vis[u] = true;
  for (set<int>::iterator it = G[u].begin(); it != G[u].end(); it++)
    dfs(*it, vis, stk);
  stk.push(u);
}
bool ok() {
  bool vis[100005] = {false};
  static int d[100005];
  stack<int> stk;
  int max_d;
  memset(d, -1, sizeof(d));
  dfs(src, vis, stk);
  d[src] = 0;
  max_d = -1;
  while (!stk.empty()) {
    int u = stk.top();
    stk.pop();
    set<int>::iterator it;
    for (it = G[u].begin(); it != G[u].end(); it++) {
      int v = *it;
      if (d[v] < d[u] + 1) {
        d[v] = d[u] + 1;
        max_d = max(d[v], max_d);
      }
    }
  }
  return max_d == n - 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e.push_back(pair<int, int>(u, v));
    deg_in[v]++;
  }
  for (int u = 1; u <= n; u++)
    if (deg_in[u] == 0) {
      src = u;
      break;
    }
  s = -1;
  int i, j;
  for (i = 0, j = m - 1; i < j;) {
    int mid = (i + j) >> 1;
    adjust(mid);
    if (!ok()) {
      i = mid + 1;
    } else {
      j = mid;
    }
  }
  adjust(i);
  if (ok())
    printf("%d\n", i);
  else
    puts("-1");
  return 0;
}
