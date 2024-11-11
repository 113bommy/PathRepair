#include <bits/stdc++.h>
using namespace std;
int read();
int n, m, q, cnt, ecnt, pcnt;
map<int, int> mp[200005];
struct Edge {
  int x, y, l, r, w;
  void init(int xx, int yy, int d, int L) { x = xx, y = yy, w = d, l = L; }
} e[400005];
struct P {
  int x, y;
};
vector<P> vp[200005];
struct liner_Base {
  int b[31];
  void ins(int w) {
    for (int i = 29; i >= 0; --i) {
      if (!(w >> i)) continue;
      if (!b[i]) {
        b[i] = w;
        break;
      }
      w ^= b[i];
    }
  }
  int work(int w) {
    for (int i = 29; i >= 0; --i) {
      if ((w ^ b[i]) < w) w ^= b[i];
    }
    return w;
  }
} lb[20];
struct T {
  int fa, w, sz;
};
struct Dsu {
  T t[200005];
  int find(int x, int &w) {
    while (x != t[x].fa) w ^= t[x].w, x = t[x].fa;
    return x;
  }
  void merge(int x, int y, int w, int id) {
    if (x == y) return lb[id].ins(w);
    if (t[x].sz > t[y].sz) swap(x, y);
    t[x].fa = y, t[x].w = w, t[y].sz += t[x].sz;
  }
  int qry(int x, int y, int id) {
    int w = 0;
    find(x, w), find(y, w);
    int t;
    return lb[id].work(w);
  }
} dsu;
int ppcnt;
struct Seg {
  vector<Edge> te[800005];
  void ins_edge(int l, int r, int k, Edge &e) {
    if (e.l > r || e.r < l) return;
    if (e.l <= l && e.r >= r) return ++ppcnt, te[k].push_back(e);
    int mid = l + r >> 1;
    ins_edge(l, mid, k << 1, e), ins_edge(mid + 1, r, k << 1 | 1, e);
  }
  T stt[800005];
  int st[800005], tag[20], top;
  void ins(int k, int d) {
    lb[d] = lb[d - 1], tag[d] = top;
    for (int i = 0; i < te[k].size(); ++i) {
      int x = te[k][i].x, y = te[k][i].y, wx = 0, wy = 0;
      x = dsu.find(x, wx), y = dsu.find(y, wy);
      st[++top] = x, stt[top] = dsu.t[x];
      st[++top] = y, stt[top] = dsu.t[y];
      dsu.merge(x, y, wx ^ wy ^ te[k][i].w, d);
    }
  }
  void del(int d) {
    while (top > tag[d]) dsu.t[st[top]] = stt[top], top--;
  }
  void work(int l, int r, int k, int d) {
    ins(k, d);
    if (l == r) {
      for (int i = 0; i < vp[l].size(); ++i)
        printf("%d\n", dsu.qry(vp[l][i].x, vp[l][i].y, d));
      return del(d);
    }
    int mid = l + r >> 1;
    work(l, mid, k << 1, d + 1), work(mid + 1, r, k << 1 | 1, d + 1);
    del(d);
  }
} seg;
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) dsu.t[i] = (T){i, 0, 1};
  for (int i = 1, x, y; i <= m; ++i)
    x = read(), y = read(), e[mp[x][y] = mp[y][x] = i].init(x, y, read(), 1);
  q = read();
  ecnt = m, cnt = 1;
  for (int i = 1, op, x, y; i <= q; ++i) {
    op = read(), x = read(), y = read();
    if (op == 1) e[mp[x][y] = mp[y][x] = ++ecnt].init(x, y, read(), ++cnt);
    if (op == 2) e[mp[x][y]].r = cnt++;
    if (op == 3) vp[cnt].push_back((P){x, y});
  }
  for (int i = 1; i <= ecnt; ++i) {
    if (!e[i].r) e[i].r = cnt;
    seg.ins_edge(1, cnt, 1, e[i]);
  }
  seg.work(1, cnt, 1, 1);
  return 0;
}
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
