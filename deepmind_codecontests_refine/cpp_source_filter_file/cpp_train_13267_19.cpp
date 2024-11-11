#include <bits/stdc++.h>
using namespace std;
void RI() {}
template <typename... T>
void RI(int& head, T&... tail) {
  scanf("%d", &head);
  RI(tail...);
}
inline int min(int a, int b) { return a < b ? a : b; }
struct Maxflow {
  static const short INF = 2e4;
  struct E {
    short to, cap, rev;
    E() {}
    E(short _to, short _cap, short _rev) : to(_to), cap(_cap), rev(_rev) {}
  };
  int n;
  vector<vector<E> > e;
  vector<vector<E>::iterator> cur;
  vector<short> dis;
  void init(int _n) {
    n = _n;
    e.resize(n);
    cur.resize(n);
    dis.resize(n);
    for (int i = 0; i < int(n); i++) e[i].clear();
  }
  void add(int a, int b, int c) {
    if (a == b) return;
    e[a].push_back(E(b, c, e[b].size()));
    e[b].push_back(E(a, 0, e[a].size() - 1));
  }
  bool bfs() {
    fill(dis.begin(), dis.end(), -1);
    queue<int> q;
    dis[0] = 0;
    q.push(0);
    while (!q.empty() && dis[n - 1] == -1) {
      int p = q.front();
      q.pop();
      for (auto it = (e[p]).begin(); it != (e[p]).end(); it++) {
        if (it->cap == 0 || dis[it->to] != -1) continue;
        dis[it->to] = dis[p] + 1;
        q.push(it->to);
      }
    }
    return dis[n - 1] != -1;
  }
  short go(int p, short c) {
    if (p == n - 1) return c;
    short ret = 0;
    for (auto& it = cur[p]; it != e[p].end(); it++) {
      if (it->cap == 0 || dis[it->to] != dis[p] + 1) continue;
      short now = go(it->to, min(it->cap, c - ret));
      ret += now;
      it->cap -= now;
      e[it->to][it->rev].cap += now;
      if (ret == c) break;
    }
    if (ret == 0) dis[p] = -1;
    return ret;
  }
  int maxflow() {
    int ret = 0;
    while (bfs()) {
      for (int i = 0; i < int(n); i++) cur[i] = e[i].begin();
      ret += go(0, INF);
    }
    return ret;
  }
} flow;
int n, ea[3010], eb[3010], ec[3010], ub[3010];
vector<int> e[3010];
short dis[3010][3010];
bool vis[3010];
void dfs(int st, int p, int d, short _dis[3010]) {
  _dis[p] = d;
  for (auto it = (e[p]).begin(); it != (e[p]).end(); it++) {
    int to = ea[*it] ^ eb[*it] ^ p;
    if (!vis[to]) {
      vis[to] = 1;
      dfs(st, to, max(d, ec[*it]), _dis);
    }
  }
}
bool chk(int m) {
  flow.init(2 * n + 2);
  for (int i = (1); i <= int(n); i++) flow.add(0, i, 1);
  for (int i = (1); i <= int(n); i++)
    for (int j = (1); j <= int(n); j++)
      if (dis[i][j] >= m) flow.add(i, j + n, 1);
  for (int i = (1); i <= int(n); i++) flow.add(i + n, n + n + 1, ub[i]);
  return flow.maxflow() == n;
}
int main() {
  RI(n);
  for (int i = 0; i < int(n - 1); i++) {
    RI(ea[i], eb[i], ec[i]);
    e[ea[i]].push_back(i);
    e[eb[i]].push_back(i);
  }
  for (int i = (1); i <= int(n); i++) RI(ub[i]);
  for (int i = (1); i <= int(n); i++) {
    memset(vis, 0, sizeof(vis));
    dfs(i, i, 0, dis[i]);
  }
  int l = 1, r = 10000;
  while (l != r) {
    int m = (l + r + 1) / 2;
    if (chk(m))
      l = m;
    else
      r = m - 1;
  }
  printf("%d\n", l);
  return 0;
}
