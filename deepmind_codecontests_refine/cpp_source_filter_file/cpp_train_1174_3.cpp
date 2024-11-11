#include <bits/stdc++.h>
using namespace std;
int getAns(vector<int> c, vector<set<int>> adj, int cur) {
  int n = int(adj.size());
  auto remEdge = [&adj](int u, int v) {
    adj[u].erase(v);
    adj[v].erase(u);
  };
  vector<int> proc(n);
  auto remLayer = [&](queue<int> q) {
    queue<int> ret;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (c[u] == 0 || c[u] == cur) {
        if (int(adj[u].size()) == 0) continue;
        int v = *adj[u].begin();
        remEdge(u, v);
        if (proc[v]) continue;
        if (int(adj[v].size()) <= 1) {
          proc[v] = 1;
          if (c[v] == cur || c[v] == 0)
            q.push(v);
          else
            ret.push(v);
        }
      } else
        ret.push(u);
    }
    return ret;
  };
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (int(adj[i].size()) <= 1) q.push(i), proc[i] = 1;
  }
  int ans = 0;
  while (!q.empty()) {
    q = remLayer(q);
    cur == 1 ? cur = 2 : cur = 1;
    ans++;
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    vector<int> c(n), D(n);
    for (int &t : c) scanf("%d", &t);
    vector<set<int>> adj(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      adj[u].insert(v);
      adj[v].insert(u);
    }
    if (!accumulate(begin(c), end(c), 0)) {
      puts("1");
      continue;
    }
    int ans = n;
    if (count(begin(c), end(c), 1)) ans = min(ans, getAns(c, adj, 1));
    if (count(begin(c), end(c), 1)) ans = min(ans, getAns(c, adj, 2));
    printf("%d\n", ans);
  }
}
