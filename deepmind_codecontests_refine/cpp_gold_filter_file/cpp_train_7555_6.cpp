#include <bits/stdc++.h>
using namespace std;
const int BUF_SIZE = 1 << 12;
char buf[BUF_SIZE], *buf_s = buf, *buf_t = buf + 1;
template <typename _n_>
void mian(_n_ &_x_) {
  while (*buf_s != '-' && !isdigit(*buf_s)) {
    buf_s++;
    if (buf_s == buf_t) {
      buf_s = buf;
      buf_t = buf + fread(buf, 1, BUF_SIZE, stdin);
    }
  };
  bool register _nega_ = false;
  if (*buf_s == '-') {
    _nega_ = true;
    {
      buf_s++;
      if (buf_s == buf_t) {
        buf_s = buf;
        buf_t = buf + fread(buf, 1, BUF_SIZE, stdin);
      }
    };
  }
  _x_ = 0;
  while (isdigit(*buf_s)) {
    _x_ = _x_ * 10 + *buf_s - '0';
    {
      buf_s++;
      if (buf_s == buf_t) {
        buf_s = buf;
        buf_t = buf + fread(buf, 1, BUF_SIZE, stdin);
      }
    };
  }
  if (_nega_) _x_ = -_x_;
}
const int kato = 6e6 + 5e5 + 10;
const int atri = 1e6 + 5e5 + 10;
template <typename _n_>
bool cmax(_n_ &a, const _n_ &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename _n_>
bool cmin(_n_ &a, const _n_ &b) {
  return a > b ? a = b, 1 : 0;
}
int n, m, v, l, r, w, u, q, s, opt;
namespace towa {
struct Edge {
  long long to, dis;
  Edge *nxt;
};
struct Graph {
  Edge yuni[atri << 1], *head[atri], *tail;
  void clear() {
    memset(head, 0x0, sizeof head);
    tail = yuni;
  }
  Graph() { clear(); }
  Edge *operator[](int x) { return head[x]; }
  void add(int x, int y, int z) {
    *tail = (Edge){y, z, head[x]};
    head[x] = tail++;
  }
} Ire;
struct Segementtree {
 protected:
  struct node {
    node *ch[2];
    int l, r;
    node(int l = 0, int r = 0) : l(l), r(r) { memset(ch, 0x0, sizeof ch); }
    inline int mid() { return (l + r) >> 1; }
  } * root, *tail, _pool[kato];
  inline void build(node *&o, int l, int r) {
    o = new (tail++) node(l, r);
    if (l == r) {
      Ire.add(o - _pool, l + 8 * n, 0);
      Ire.add(o - _pool + 4 * n, l + 8 * n, 0);
      Ire.add(l + 8 * n, o - _pool, 0);
      Ire.add(l + 8 * n, o - _pool + 4 * n, 0);
      return;
    }
    build(o->ch[0], l, o->mid());
    build(o->ch[1], o->mid() + 1, r);
    Ire.add(o - _pool, o->ch[0] - _pool, 0);
    Ire.add(o->ch[0] - _pool + 4 * n, o - _pool + 4 * n, 0);
    Ire.add(o - _pool, o->ch[1] - _pool, 0);
    Ire.add(o->ch[1] - _pool + 4 * n, o - _pool + 4 * n, 0);
  }
  inline void Modify_in(node *o, int l, int r, int v, int z) {
    if (l <= o->l && o->r <= r) {
      Ire.add(v + 8 * n, o - _pool, z);
      return;
    }
    if (l <= o->mid()) {
      Modify_in(o->ch[0], l, r, v, z);
    }
    if (r > o->mid()) {
      Modify_in(o->ch[1], l, r, v, z);
    }
  }
  inline void Modify_out(node *o, int l, int r, int v, int z) {
    if (l <= o->l && o->r <= r) {
      Ire.add(o - _pool + 4 * n, v + 8 * n, z);
      return;
    }
    if (l <= o->mid()) {
      Modify_out(o->ch[0], l, r, v, z);
    }
    if (r > o->mid()) {
      Modify_out(o->ch[1], l, r, v, z);
    }
  }
  void clear() { tail = _pool; }

 public:
  Segementtree() { clear(); }
  inline void build(int n) { build(root, 1, n); }
  inline void Modify_in(int l, int r, int v, int z) {
    Modify_in(root, l, r, v, z);
  }
  inline void Modify_out(int l, int r, int v, int z) {
    Modify_out(root, l, r, v, z);
  }
} yuni;
struct node {
  long long v, w;
  friend bool operator<(const node &a, const node &b) { return a.w > b.w; }
};
priority_queue<node> q;
long long dis[kato];
bool vis[kato];
inline void Dij(int s) {
  memset(dis, 0x3f, sizeof dis);
  dis[s] = 0;
  q.push((node){s, 0});
  while (!q.empty()) {
    int u = q.top().v;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (Edge *i = Ire[u]; i; i = i->nxt) {
      int v = i->to;
      if (dis[v] > dis[u] + i->dis) {
        dis[v] = dis[u] + i->dis;
        if (!vis[v]) q.push((node){v, dis[v]});
      }
    }
  }
}
}  // namespace towa
inline int Ame_() {
  mian(n), mian(q), mian(s);
  towa::yuni.build(n);
  for (; q-- > 0;) {
    mian(opt);
    if (opt == 1)
      mian(v), mian(u), mian(w), towa::Ire.add(v + 8 * n, u + 8 * n, w);
    if (opt == 2)
      mian(v), mian(l), mian(r), mian(w), towa::yuni.Modify_in(l, r, v, w);
    if (opt == 3)
      mian(v), mian(l), mian(r), mian(w), towa::yuni.Modify_out(l, r, v, w);
  }
  s = s + 8 * n;
  towa::Dij(s);
  for (int i = 1; i <= n; i++) {
    if (towa::dis[i + 8 * n] < 0x3f3f3f3f3f3f3f3f)
      fprintf(stdout, "%lld ", towa::dis[i + 8 * n]);
    else
      fprintf(stdout, "-1 ");
  }
  return ~~(0 ^ 0 ^ 0);
}
int Ame__ = Ame_();
int main() { ; }
