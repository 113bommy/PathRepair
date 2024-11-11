#include <bits/stdc++.h>
using namespace std;
struct ZKW_flow {
  int S, T, ecnt;
  int head[10010];
  int c[100010], w[100010], to[100010], next[100010];
  ZKW_flow() {
    memset(head, 0, sizeof(head));
    ecnt = 2;
  }
  void addEdge(int u, int v, int _c, int ww) {
    c[ecnt] = _c;
    w[ecnt] = ww;
    to[ecnt] = v;
    next[ecnt] = head[u];
    head[u] = ecnt++;
    c[ecnt] = 0;
    w[ecnt] = -ww + 2;
    to[ecnt] = u;
    next[ecnt] = head[v];
    head[v] = ecnt++;
  }
  int dis[10010];
  void SPFA() {
    for (int i = 1; i <= T; ++i) dis[i] = 0x3f3f3f3f;
    priority_queue<pair<int, int> > Q;
    dis[S] = 0;
    Q.push(make_pair(0, S));
    while (!Q.empty()) {
      int u = Q.top().second, d = -Q.top().first;
      Q.pop();
      if (dis[u] != d) continue;
      for (int p = head[u]; p; p = next[p]) {
        int &v = to[p];
        if (c[p] && dis[v] > d + w[p]) {
          dis[v] = d + w[p];
          Q.push(make_pair(-dis[v], v));
        }
      }
    }
    for (int i = 1; i <= T; ++i) dis[i] = dis[T] - dis[i];
  }
  int ans;
  bool use[10010];
  int add_flow(int u, int flow) {
    if (u == T) {
      ans += dis[S] * flow;
      return flow;
    }
    use[u] = true;
    int now = flow;
    for (int p = head[u]; p; p = next[p]) {
      int &v = to[p];
      if (c[p] && !use[v] && dis[u] == dis[v] + w[p]) {
        int tmp = add_flow(v, min(now, c[p]));
        assert(tmp <= 1);
        c[p] -= tmp, w[p] += 2 * tmp;
        c[p ^ 1] += tmp, w[p ^ 1] -= 2 * tmp;
        now -= tmp;
        if (!now) break;
      }
    }
    return flow - now;
  }
  bool modify_label() {
    int d = 0x3f3f3f3f;
    for (int u = 1; u <= T; ++u)
      if (use[u])
        for (int p = head[u]; p; p = next[p]) {
          int &v = to[p];
          if (c[p] && !use[v]) d = min(d, dis[v] + w[p] - dis[u]);
        }
    if (d == 0x3f3f3f3f) return false;
    for (int i = 1; i <= T; ++i)
      if (use[i]) dis[i] += d;
    return true;
  }
  int min_cost_flow() {
    SPFA();
    while (true) {
      while (true) {
        for (int i = 1; i <= T; ++i) use[i] = 0;
        if (!add_flow(S, 0x3f3f3f3f)) break;
      }
      if (!modify_label()) break;
    }
    return ans;
  }
} G;
const int N = 55;
int L[N], R[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  G.S = n + n + 1, G.T = G.S + 1;
  for (int i = 1; i <= n; i++) L[i] = 1, R[i] = n;
  while (q--) {
    int type, l, r, v;
    cin >> type >> l >> r >> v;
    if (type == 1) {
      for (int i = l; i <= r; i++) L[i] = max(L[i], v);
    } else {
      for (int i = l; i <= r; i++) R[i] = min(R[i], v);
    }
  }
  for (int i = 1; i <= n; i++)
    if (L[i] > R[i]) {
      cout << -1 << endl;
      return 0;
    }
  for (int i = 1; i <= n; i++) {
    G.addEdge(G.S, i, 1, 0);
    for (int j = L[i]; j <= R[i]; j++) G.addEdge(i, n + j, 1, 0);
    G.addEdge(n + i, G.T, 0x3f3f3f3f, 1);
  }
  cout << G.min_cost_flow() << endl;
  return 0;
}
