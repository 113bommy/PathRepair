#include <bits/stdc++.h>
using namespace std;
namespace BlueQuantum {
int const N = 1e5 + 5, INF = 0x7f7f7f7f;
int e_cnt = 1, ncnt;
int heads[N * 2], cur[N * 2], dep[N * 2], need[N * 2];
int lim[N * 2], cnt[N * 2];
bool typ[N * 2];
map<int, int> xmap, ymap;
struct Edge {
  int v, nxt, f;
} e[N * 22];
inline void add(int u, int v, int f) {
  e[++e_cnt].v = v, e[e_cnt].nxt = heads[u], heads[u] = e_cnt, e[e_cnt].f = f;
  e[++e_cnt].v = u, e[e_cnt].nxt = heads[v], heads[v] = e_cnt, e[e_cnt].f = 0;
}
inline void add(int u, int v, int lower, int upper) {
  need[u] -= lower, need[v] += lower;
  add(u, v, upper - lower);
}
inline bool bfs(int s, int t) {
  memset(dep, 0, sizeof(dep));
  memcpy(cur, heads, sizeof(cur));
  queue<int> q;
  q.push(s);
  dep[s] = 1;
  while (q.empty() == false) {
    int u = q.front();
    q.pop();
    for (int i = heads[u], v; i; i = e[i].nxt) {
      if (dep[v = e[i].v] == 0 && e[i].f) {
        dep[v] = dep[u] + 1;
        if (v == t) return true;
        q.push(v);
      }
    }
  }
  return false;
}
int dinic(int u, int t, int flow) {
  if (u == t) return flow;
  int rest = flow;
  for (int &i = cur[u], v; i; i = e[i].nxt) {
    if (dep[v = e[i].v] == dep[u] + 1 && e[i].f) {
      int k = dinic(v, t, min(e[i].f, rest));
      e[i].f -= k, e[i ^ 1].f += k;
      rest -= k;
      if (rest == 0) break;
    }
  }
  return flow - rest;
}
inline int getMaxFlow(int s, int t) {
  int res = 0;
  while (bfs(s, t)) res += dinic(s, t, INF);
  return res;
}
inline int main() {
  int n, m, r, b;
  cin >> n >> m >> r >> b;
  bool flag = false;
  if (r > b) swap(r, b), flag = true;
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    if (xmap.find(x) == xmap.end()) xmap[x] = ++ncnt, typ[ncnt] = true;
    cnt[xmap[x]]++;
    if (ymap.find(y) == ymap.end()) ymap[y] = ++ncnt;
    cnt[ymap[y]]++;
    add(xmap[x], ymap[y], 1);
  }
  memset(lim, INF, sizeof(lim));
  for (int i = 1, t, l, d; i <= m; ++i) {
    cin >> t >> l >> d;
    switch (t) {
      case 1:
        if (xmap.find(l) != xmap.end()) lim[xmap[l]] = min(lim[xmap[l]], d);
        break;
      case 2:
        if (ymap.find(l) != ymap.end()) lim[ymap[l]] = min(lim[ymap[l]], d);
        break;
    }
  }
  int s = ncnt + 1, t = s + 1, S = 0, T = t + 1;
  for (int i = 1; i <= ncnt; ++i) {
    int c = cnt[i], d = min(c, lim[i]), lower = (c - d + 1) / 2,
        upper = (c + d) / 2;
    if (lower > upper) return cout << "-1", 0;
    typ[i] ? add(s, i, lower, upper) : add(i, t, lower, upper);
  }
  int sum = 0;
  for (int i = 1; i < T; ++i) {
    if (need[i] < 0) add(i, T, -need[i]);
    if (need[i] > 0) add(S, i, need[i]), sum += need[i];
  }
  add(t, s, INF);
  if (getMaxFlow(S, T) != sum) return cout << "-1", 0;
  int ans = getMaxFlow(s, t);
  cout << (long long)ans * r + (long long)(n - ans) * b << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << (e[i * 2 ^ 1].f ^ flag ? 'r' : 'b');
  }
  return 0;
}
}  // namespace BlueQuantum
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  return BlueQuantum::main();
}
