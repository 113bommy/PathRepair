#include <bits/stdc++.h>
using namespace std;
class edge {
 public:
  int e, nxt, cap;
  edge(int e1 = -1, int nxt1 = -1, int cap1 = 0) {
    e = e1, nxt = nxt1, cap = cap1;
  }
};
int S, T;
int dep[90000];
bool vis[90000];
class graph {
 public:
  edge g[3000000];
  int head[90000], tmpcnt, cur[90000];
  void init() {
    memset(head, 255, sizeof(head));
    tmpcnt = 0;
  }
  void addedge(int s, int e, int cap) {
    if (cap == 0) return;
    g[tmpcnt] = edge(e, head[s], cap), head[s] = tmpcnt++;
    g[tmpcnt] = edge(s, head[e], 0), head[e] = tmpcnt++;
  }
  bool bfs() {
    memset(vis, 0, sizeof(vis));
    memset(dep, 0, sizeof(dep));
    queue<int> q;
    q.push(S);
    vis[S] = 1;
    while (!q.empty()) {
      int fr = q.front();
      q.pop();
      for (int i = head[fr]; i != -1; i = g[i].nxt) {
        if (g[i].cap > 0 && !vis[g[i].e]) {
          dep[g[i].e] = dep[fr] + 1;
          vis[g[i].e] = 1;
          q.push(g[i].e);
        }
      }
    }
    return vis[T];
  }
  int dfs(int np, int maxflow) {
    int f;
    int flow = 0;
    if (np == T || !maxflow) return maxflow;
    for (int i = cur[np]; i != -1; i = g[i].nxt) {
      cur[np] = i;
      if (g[i].cap > 0 && dep[g[i].e] == dep[np] + 1 &&
          (f = dfs(g[i].e, min(g[i].cap, maxflow))) > 0) {
        g[i].cap -= f;
        g[i ^ 1].cap += f;
        flow += f;
        maxflow -= f;
        if (!maxflow) break;
      }
    }
    return flow;
  }
  int dinic() {
    int out = 0;
    while (bfs()) memcpy(cur, head, sizeof(cur)), out += dfs(S, 0x3f3f3f3f);
    return out;
  }
} G;
int n, Q, nodecnt = 0;
class segment {
 public:
  int l, r, tim;
  segment() {}
  segment(int tl, int tr, int tt) {
    l = tl;
    r = tr;
    tim = tt;
  }
  bool operator<(const segment &t) const {
    return l != t.l ? l < t.l : r < t.r;
  }
};
class sgt {
 public:
  int ch[40010][2], rt;
  bool flag;
  void build(int &p, int l, int r) {
    p = ++nodecnt;
    if (l == r) {
      if (!flag)
        G.addedge(S, p, 1);
      else
        G.addedge(p, T, 1);
      return;
    }
    int mid = (l + r) >> 1;
    build(ch[p][0], l, mid);
    build(ch[p][1], mid + 1, r);
    if (!flag) {
      G.addedge(ch[p][0], p, mid - l + 1);
      G.addedge(ch[p][1], p, r - mid);
    } else {
      G.addedge(p, ch[p][0], mid - l + 1);
      G.addedge(p, ch[p][1], r - mid);
    }
  }
  void link(int p, int l, int r, int ql, int qr, int des) {
    if (ql <= l && r <= qr) {
      if (!flag)
        G.addedge(p, des, r - l + 1);
      else
        G.addedge(des, p, r - l + 1);
      return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) link(ch[p][0], l, mid, ql, qr, des);
    if (qr > mid) link(ch[p][1], mid + 1, r, ql, qr, des);
  }
} tree[2];
set<segment> st;
int lx[10010], rx[10010], ly[10010], ry[10010];
vector<int> add[10010], del[10010];
void addrect(int lx, int rx, int ly, int ry) {
  int p = ++nodecnt;
  tree[0].link(tree[0].rt, 1, n, lx, rx, p);
  tree[1].link(tree[1].rt, 1, n, ly, ry, p);
}
int main() {
  G.init();
  tree[1].flag = 1;
  S = 1, T = 2;
  nodecnt = 2;
  scanf("%d%d", &n, &Q);
  tree[0].build(tree[0].rt, 1, n);
  tree[1].build(tree[1].rt, 1, n);
  st.insert(segment(0, n, 0));
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d%d%d", &lx[i], &ly[i], &rx[i], &ry[i]);
    add[lx[i] - 1].push_back(i);
    del[rx[i]].push_back(i);
  }
  for (int i = 0; i <= n; i++) {
    for (int &x : del[i]) {
      auto r = st.lower_bound(segment(ly[x] - 1, 0x3f3f3f3f, 0));
      auto l = r;
      l--;
      auto L = *l, R = *r;
      st.erase(l);
      st.erase(r);
      if (L.tim != i && L.l < L.r) addrect(L.tim + 1, i, L.l + 1, L.r);
      if (R.tim != i && R.l < R.r) addrect(R.tim + 1, i, R.l + 1, R.r);
      st.insert(segment(L.l, R.r, i));
    }
    for (int &x : add[i]) {
      auto pt = st.lower_bound(segment(ly[x] - 1, 0x3f3f3f3f, 0));
      pt--;
      auto cur = *pt;
      st.erase(pt);
      if (cur.tim != i && cur.l < cur.r)
        addrect(cur.tim + 1, i, cur.l + 1, cur.r);
      st.insert(segment(cur.l, ly[x] - 1, i));
      st.insert(segment(ry[x], cur.r, i));
    }
  }
  assert(st.size() == 1);
  if (st.begin()->tim != n && st.begin()->r < st.begin()->r)
    addrect(st.begin()->tim + 1, n, st.begin()->l + 1, st.begin()->r);
  printf("%d\n", G.dinic());
  return 0;
}
