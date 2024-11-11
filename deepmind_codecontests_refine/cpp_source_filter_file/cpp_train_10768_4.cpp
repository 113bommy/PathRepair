#include <bits/stdc++.h>
using namespace std;
struct networkflow {
  struct node {
    int v, w, rev;
  };
  void setEdge(int u, int v, int fl) {
    int sz1 = (int)adj[v].size();
    int sz2 = (int)adj[u].size();
    adj[u].push_back({v, fl, sz1});
    adj[v].push_back({u, 0, sz2});
  }
  vector<vector<node> > adj;
  vector<int> lev, edge_tried;
  int st, ed;
  networkflow(int V, int s, int t)
      : adj(V), lev(V), edge_tried(V), st(s), ed(t) {}
  bool assign_level() {
    fill(lev.begin(), lev.end(), -1);
    lev[st] = 0;
    queue<int> que;
    que.push(st);
    while (!que.empty()) {
      int now = que.front();
      que.pop();
      for (int i = 0; i < adj[now].size(); i++) {
        int nxt = adj[now][i].v;
        if (lev[nxt] == -1 && adj[now][i].w != 0) {
          lev[nxt] = lev[now] + 1;
          que.push(nxt);
        }
      }
    }
    return (lev[ed] != -1);
  }
  int dfs(int now, int fl) {
    if (now == ed) return fl;
    for (int &i = edge_tried[now]; i < adj[now].size(); i++) {
      int nxt = adj[now][i].v;
      if (lev[nxt] == lev[now] + 1 && adj[now][i].w != 0) {
        int nxtflow = dfs(nxt, min(fl, adj[now][i].w));
        if (nxtflow) {
          adj[now][i].w -= nxtflow;
          adj[nxt][adj[now][i].rev].w += nxtflow;
          return nxtflow;
        }
      }
    }
    return 0;
  }
  long long dinic() {
    long long ret = 0;
    while (assign_level()) {
      fill(edge_tried.begin(), edge_tried.end(), 0);
      while (1) {
        int amt = dfs(st, 2e9);
        if (amt == 0) break;
        ret += amt;
      }
    }
    return ret;
  }
};
int n, m;
int a[55], b[55], c[55], l[55], r[55];
map<pair<int, int>, int> M;
int F(int i, int j) { return a[i] * j * j + b[i] * j + c[i]; }
int main() {
  int nodecnt = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    for (int j = l[i] - 1; j <= r[i]; j++) {
      M[make_pair(i, j)] = ++nodecnt;
    }
  }
  int st = 0, ed = nodecnt + 3;
  networkflow net(nodecnt + 5, st, ed);
  int INF = 1e9;
  int BIG = (int)1e6;
  for (int xi, xj, d, i = 1; i <= m; i++) {
    scanf("%d %d %d", &xi, &xj, &d);
    for (int j = l[xi]; j <= r[xi]; j++) {
      if (l[xj] - 1 <= j - d && j - d <= r[xj]) {
        net.setEdge(M[make_pair(xi, j)], M[make_pair(xj, j - d)], INF);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    net.setEdge(st, M[make_pair(i, l[i] - 1)], INF);
    for (int j = l[i] - 1; j < r[i]; j++) {
      net.setEdge(M[make_pair(i, j)], M[make_pair(i, j + 1)],
                  BIG - F(i, j + 1));
    }
    net.setEdge(M[make_pair(i, r[i])], ed, INF);
  }
  long long ans = (long long)n * BIG;
  ans -= net.dinic();
  cout << ans;
}
