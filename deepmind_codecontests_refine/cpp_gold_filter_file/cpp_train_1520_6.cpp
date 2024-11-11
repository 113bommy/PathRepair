#include <bits/stdc++.h>
using namespace std;
namespace thecold {
inline int read() {
  int res = 0;
  bool flag = false;
  char c = getchar();
  while (!isdigit(c)) flag = (c == '-'), c = getchar();
  while (isdigit(c)) res = res * 10 + (c ^ 48), c = getchar();
  return !flag ? res : -res;
}
const int Max_n = 1e4 + 5;
struct node {
  int yl, yr, val;
  node(int a, int b, int d) { yl = a, yr = b, val = d; }
  node() {}
};
vector<node> v[Max_n];
int n, q;
struct NetworkFlow {
  static const int Max_m = 5e5 + 5;
  static const int INF = 1e7;
  static const int Max_d = 3e5 + 5;
  struct node {
    int nex, to, val;
    node(int a, int b, int c) { nex = a, to = b, val = c; }
    node() {}
  } edge[Max_m << 1];
  int tot = 1, head[Max_d], son[Max_d][2], cnt = 5;
  int root_in, root_out, s = 0, t = 1;
  inline void add_edge(const int x, const int y, const int z) {
    edge[++tot] = node(head[x], y, z), head[x] = tot;
    edge[++tot] = node(head[y], x, 0), head[y] = tot;
  }
  void build_in(const int l, const int r, int &now) {
    now = ++cnt;
    if (l == r) return add_edge(s, now, 1);
    int mid = (l + r) >> 1;
    build_in(l, mid, son[now][0]), build_in(mid + 1, r, son[now][1]);
    add_edge(son[now][0], now, INF), add_edge(son[now][1], now, INF);
  }
  void build_out(const int l, const int r, int &now) {
    now = ++cnt;
    if (l == r) return add_edge(now, t, 1);
    int mid = (l + r) >> 1;
    build_out(l, mid, son[now][0]), build_out(mid + 1, r, son[now][1]);
    add_edge(now, son[now][0], INF), add_edge(now, son[now][1], INF);
  }
  inline void build() { build_in(1, n, root_in), build_out(1, n, root_out); }
  void add_in(const int l, const int r, const int ll, const int rr,
              const int now, const int goal) {
    if (ll > r || rr < l) return;
    if (l <= ll && rr <= r) return add_edge(now, goal, INF);
    int mid = (ll + rr) >> 1;
    add_in(l, r, ll, mid, son[now][0], goal),
        add_in(l, r, mid + 1, rr, son[now][1], goal);
  }
  void add_out(const int l, const int r, const int ll, const int rr,
               const int now, const int goal) {
    if (ll > r || rr < l) return;
    if (l <= ll && rr <= r) return add_edge(goal, now, INF);
    int mid = (ll + rr) >> 1;
    add_out(l, r, ll, mid, son[now][0], goal),
        add_out(l, r, mid + 1, rr, son[now][1], goal);
  }
  inline void add(const int l1, const int r1, const int l2, const int r2) {
    if (l1 > r1 || l2 > r2) return;
    ++cnt;
    add_in(l1, r1, 1, n, root_in, cnt);
    add_out(l2, r2, 1, n, root_out, cnt);
  }
  int dis[Max_d], beg[Max_d];
  queue<int> q;
  inline bool bfs() {
    memset(dis, 0x3f, sizeof(dis));
    while (q.size()) q.pop();
    q.push(s);
    dis[s] = 0;
    beg[s] = head[s];
    while (q.size()) {
      int now = q.front();
      q.pop();
      for (int i = head[now]; i; i = edge[i].nex) {
        int nex = edge[i].to;
        if (dis[nex] != 0x3f3f3f3f || !edge[i].val) continue;
        dis[nex] = dis[now] + 1, beg[nex] = head[nex];
        if (nex == t) return true;
        q.push(nex);
      }
    }
    return false;
  }
  int dinic(const int now, int flow) {
    if (now == t || !flow) return flow;
    int ret = 0;
    for (int i = beg[now]; i; i = edge[i].nex) {
      beg[now] = i;
      int nex = edge[i].to;
      if (dis[nex] != dis[now] + 1 || !edge[i].val) continue;
      int tmp = dinic(nex, min(flow, edge[i].val));
      if (!tmp) dis[nex] = 0x3f3f3f3f;
      ret += tmp, flow -= tmp, edge[i].val -= tmp, edge[i ^ 1].val += tmp;
      if (!flow) break;
    }
    return ret;
  }
  inline void query() {
    int ret = 0;
    while (bfs()) {
      ret += dinic(s, INF);
    }
    printf("%d\n", ret);
  }
} flow;
struct ODT {
  struct node {
    int l, r;
    node(int a, int b) { l = a, r = b; }
    node() {}
    bool operator<(const node &a) const { return l < a.l; }
  };
  set<node> odt;
  inline ODT() { odt.insert(node(1, n)); }
  inline set<node>::iterator split(const int x) {
    if (x > n) return odt.end();
    set<node>::iterator it = odt.upper_bound(node(x, 0));
    --it;
    if (it->l == x) return it;
    if (it->r < x) return ++it;
    int l = it->l, r = it->r;
    odt.erase(it);
    odt.insert(node(l, x - 1));
    return odt.insert(node(x, r)).first;
  }
  inline void del(const int l, const int r) {
    set<node>::iterator rp = split(r + 1), lp = split(l);
    odt.erase(lp, rp);
  }
  inline void insert(const int l, const int r) {
    set<node>::iterator it = odt.lower_bound(node(l, r));
    if (it != odt.end() && it->l == l) printf("%d\n", l);
    odt.insert(node(l, r));
  }
  inline void solve(const int l, const int r) {
    set<node>::iterator it = odt.begin();
    for (; it != odt.end(); ++it) {
      set<node>::iterator lst = it;
      ++it;
      int beg = lst->l;
      while (it != odt.end() && it->l == lst->r + 1) ++it, ++lst;
      --it;
      flow.add(l, r, beg, lst->r);
    }
  }
};
inline bool cmp(node a, node b) { return a.val < b.val; }
struct que {
  int xi, yl, yr, val;
  que(int a, int b, int c, int d) { xi = a, yl = b, yr = c, val = d; }
  que() {}
  bool operator<(const que &a) const {
    if (xi != a.xi) return xi < a.xi;
    return val > a.val;
  }
} rect[Max_n << 1];
int lstpos[Max_n];
inline void main() {
  n = read(), q = read();
  flow.build();
  for (int i = 1; i <= n; ++i) lstpos[i] = 1;
  for (int i = 1; i <= q; ++i) {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();
    rect[i * 2 - 1] = que(x1, y1, y2, -1);
    rect[i * 2] = que(x2 + 1, y1, y2, 1);
  }
  sort(rect + 1, rect + q * 2 + 1);
  for (int i = 1; i <= 2 * q; ++i) {
    if (rect[i].val == 1)
      for (int j = rect[i].yl; j <= rect[i].yr; ++j) lstpos[j] = rect[i].xi;
    else
      for (int j = rect[i].yl; j <= rect[i].yr; ++j) {
        int lst = j;
        while (j <= rect[i].yr && lstpos[j] == lstpos[lst]) ++j;
        --j;
        if (lstpos[j] < rect[i].xi) flow.add(lstpos[j], rect[i].xi - 1, lst, j);
      }
  }
  for (int i = 1; i <= n; ++i) {
    int lst = i;
    while (i <= n && lstpos[lst] == lstpos[i]) ++i;
    --i;
    if (lstpos[lst] <= n) flow.add(lstpos[lst], n, lst, i);
  }
  flow.query();
}
}  // namespace thecold
int main() {
  thecold::main();
  return 0;
}
