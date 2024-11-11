#include <bits/stdc++.h>
using namespace std;
const int M = 200000 + 10;
int n, q;
vector<vector<int> > ss;
vector<vector<int> > g[M];
int tin[M], tout[M], tim;
int mp[M];
int dis1[M], dis2[M];
struct Node {
  long long dis1, dis2;
  long long mk;
  void init() { dis1 = dis2 = mk = 0; }
  void mark(long long __mk) {
    mk += __mk;
    dis1 += __mk;
    dis2 += __mk;
  }
};
void dfs(int o, int u) {
  tin[u] = ++tim;
  mp[tim] = u;
  for (vector<int> &v : g[u])
    if (v[1] != u) {
      dis1[v[1]] = v[0] + dis1[u];
      dis2[v[1]] += dis1[v[1]];
      dfs(u, v[1]);
    }
  tout[u] = tim;
}
struct Segtree {
  Node T[M << 2];
  Node up(Node ls, Node rs) {
    Node ret;
    ret.init();
    ret.dis1 = min(ls.dis1, rs.dis1);
    ret.dis2 = min(ls.dis2, rs.dis2);
    return ret;
  }
  void down(int o) {
    if (T[o].mk == 0) return;
    T[o << 1].mark(T[o].mk);
    T[o << 1 | 1].mark(T[o].mk);
    T[o].mk = 0;
  }
  void build(int o, int l, int r) {
    if (l == r) {
      T[o] = {dis1[mp[l]], dis2[mp[l]], 0};
      return;
    }
    int mid = l + r >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    T[o] = up(T[o << 1], T[o << 1 | 1]);
  }
  void update(int o, int l, int r, int pl, int pr, long long v) {
    if (pl <= l && r <= pr) {
      T[o].mark(v);
      return;
    }
    down(o);
    int mid = l + r >> 1;
    if (pl <= mid) update(o << 1, l, mid, pl, pr, v);
    if (pr > mid) update(o << 1 | 1, mid + 1, r, pl, pr, v);
    T[o] = up(T[o << 1], T[o << 1 | 1]);
  }
  void ins(int o, int l, int r, int x, long long v) {
    if (l == r) {
      T[o].dis2 = T[o].dis1 + v;
      return;
    }
    down(o);
    int mid = l + r >> 1;
    if (x <= mid)
      ins(o << 1, l, mid, x, v);
    else
      ins(o << 1 | 1, mid + 1, r, x, v);
    T[o] = up(T[o << 1], T[o << 1 | 1]);
  }
  Node ask(int o, int l, int r, int pl, int pr) {
    if (pl <= l && r <= pr) {
      return T[o];
    }
    down(o);
    int mid = l + r >> 1;
    if (pl <= mid && pr > mid)
      return up(ask(o << 1, l, mid, pl, pr),
                ask(o << 1 | 1, mid + 1, r, pl, pr));
    if (pl <= mid) return ask(o << 1, l, mid, pl, pr);
    if (pr > mid) return ask(o << 1 | 1, mid + 1, r, pl, pr);
  }
} sgt;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0, a, b, c; i < n - 1; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    ss.emplace_back(vector<int>{a, b, c});
    g[a].emplace_back(vector<int>{c, b});
  }
  for (int i = 0, a, b, c; i < n - 1; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    ss.emplace_back(vector<int>{a, b, c});
    dis2[a] = c;
  }
  tim = 0;
  dfs(0, 1);
  sgt.build(1, 1, tim);
  int op, id, w, u, v;
  while (q--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &id, &w);
      --id;
      if (id < n - 1) {
        sgt.update(1, 1, tim, tin[ss[id][1]], tout[ss[id][1]], w - ss[id][2]);
        ss[id][2] = w;
      } else {
        sgt.ins(1, 1, tim, tin[ss[id][0]], w);
      }
    } else {
      scanf("%d%d", &u, &v);
      if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
        printf("%I64d\n", sgt.ask(1, 1, tim, tin[v], tin[v]).dis1 -
                              sgt.ask(1, 1, tim, tin[u], tin[u]).dis1);
      } else {
        printf("%I64d\n", sgt.ask(1, 1, tim, tin[u], tout[u]).dis2 -
                              sgt.ask(1, 1, tim, tin[u], tin[u]).dis1 +
                              sgt.ask(1, 1, tim, tin[v], tin[v]).dis1);
      }
    }
  }
  return 0;
}
