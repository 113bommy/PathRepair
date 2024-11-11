#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 30005;
const int oo = 2e9 + 7;
struct tedge {
  int u, v, w, directed;
  tedge() {}
  tedge(int u, int v, int w) : u(u), v(v), w(w) {}
  int get_adj(int t) { return u + v - t; }
  void direct(int u0, int v0) {
    if (u0 != u) swap(u, v);
    directed = 1;
  }
} e[M];
int n, m, s, t, vtime = 0;
int low[N], num[N];
vector<int> g[N];
vector<int> bridge;
int vis[N];
void DFS(int u, int id_del) {
  for (int id : g[u]) {
    if (id == id_del) continue;
    int v = e[id].get_adj(u);
    if (!vis[v]) {
      vis[v] = id;
      DFS(v, id_del);
    }
  }
}
void get_bridge(int u, int id_del) {
  low[u] = num[u] = ++vtime;
  vis[u] = 1;
  for (int id : g[u]) {
    if (id == id_del) continue;
    int v = e[id].get_adj(u);
    if (e[id].directed) continue;
    e[id].direct(u, v);
    if (vis[v]) {
      low[u] = min(low[u], num[v]);
      continue;
    }
    get_bridge(v, id_del);
    low[u] = min(low[u], low[v]);
    if (num[u] < low[v]) {
      bridge.push_back(id);
    }
  }
}
int main() {
  cin >> n >> m >> s >> t;
  for (int i = 1, _b = (m); i <= _b; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
    g[e[i].u].push_back(i);
    g[e[i].v].push_back(i);
  }
  vis[s] = -1;
  DFS(s, 0);
  if (!vis[t]) return cout << 0 << endl << 0, 0;
  vector<int> path_st, path_st2;
  for (int u = t; u != s;) {
    int v = e[vis[u]].get_adj(u);
    path_st.push_back(vis[u]);
    u = v;
  }
  reverse(path_st.begin(), path_st.end());
  pair<int, int> best;
  best.first = oo;
  for (int id_del : path_st) {
    for (int i = 1, _b = (n); i <= _b; i++) vis[i] = 0;
    vis[s] = -1;
    DFS(s, id_del);
    if (!vis[t]) {
      best = min(best, make_pair(e[id_del].w, id_del));
    }
  }
  pair<int, pair<int, int> > best2;
  best2.first = oo;
  for (int id_del : path_st) {
    for (int i = 1, _b = (n); i <= _b; i++) {
      low[i] = num[i] = vis[i] = 0;
    }
    for (int i = 1, _b = (m); i <= _b; i++) e[i].directed = 0;
    vtime = 0;
    bridge.clear();
    get_bridge(s, id_del);
    for (int i = 1, _b = (n); i <= _b; i++) vis[i] = 0;
    path_st2.clear();
    vis[s] = -1;
    DFS(s, id_del);
    if (!vis[t]) continue;
    for (int u = t; u != s;) {
      int v = e[vis[u]].get_adj(u);
      path_st2.push_back(vis[u]);
      u = v;
    }
    reverse(path_st2.begin(), path_st2.end());
    vector<int> consis;
    sort(path_st2.begin(), path_st2.end());
    sort(bridge.begin(), bridge.end());
    int ip = 0, ib = 0;
    for (; ip < path_st2.size() && ib < bridge.size();) {
      if (bridge[ib] < path_st2[ip])
        ib++;
      else if (bridge[ib] > path_st2[ip])
        ip++;
      else {
        consis.push_back(bridge[ib]);
        ib++, ip++;
      }
    }
    for (int id : consis) {
      best2 =
          min(best2, make_pair(e[id_del].w + e[id].w, make_pair(id, id_del)));
    }
  }
  if (best.first < best2.first && best.first != oo) {
    cout << best.first << endl;
    cout << 1 << endl;
    cout << best.second;
    return 0;
  } else if (best2.first != oo) {
    cout << best2.first << endl;
    cout << 2 << endl;
    cout << best2.second.first << " " << best2.second.second << endl;
    return 0;
  }
  cout << -1;
  return 0;
}
