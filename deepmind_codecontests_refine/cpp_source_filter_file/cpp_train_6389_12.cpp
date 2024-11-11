#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T qmin(const T &a, const T &b) {
  return a < b ? a : b;
}
template <typename T>
inline T qmax(const T &a, const T &b) {
  return a > b ? a : b;
}
template <typename T>
inline void getmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <typename T>
inline void getmax(T &a, const T &b) {
  if (a < b) a = b;
}
inline void fileio(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const int inf = (int)1e9 + 7;
const long long linf = (long long)1e17 + 7;
const int N = 2e5 + 21, Node = N << 1;
struct seg {
  int mx[Node], n;
  inline int qmax(int u, int l, int r, int l1, int r1) {
    if (l1 <= l && r <= r1) return mx[u];
    int mid = l + r >> 1;
    if (l1 > mid) return qmax(((u) << 1 ^ 1), mid + 1, r, l1, r1);
    if (r1 <= mid) return qmax(((u) << 1), l, mid, l1, r1);
    return ::qmax(qmax(((u) << 1), l, mid, l1, r1),
                  qmax(((u) << 1 ^ 1), mid + 1, r, l1, r1));
  }
  inline void ins(int u, int l, int r, int p, int v) {
    if (l == r) {
      mx[u] = v;
      return;
    }
    int mid = l + r >> 1;
    if (p <= mid)
      ins(((u) << 1), l, mid, p, v);
    else
      ins(((u) << 1 ^ 1), mid + 1, r, p, v);
    mx[u] = ::qmax(mx[((u) << 1)], mx[((u) << 1 ^ 1)]);
  }
  inline int qmax(int l, int r) {
    if (l > r) return 0;
    return qmax(1, 1, n, l, r);
  }
  inline void ins(int p, int v) { ins(1, 1, n, p, v); }
} tp, th;
int pos[N], h[N], sz;
struct node {
  int pre, nxt, id;
} lp[N], lh[N];
int n, q;
set<int> sp, sh;
int main() {
  scanf("%d%d", &n, &q);
  sp.insert(0);
  sp.insert(n + 1);
  for (register int i = (0); i <= (n + 1); ++i)
    lp[i].pre = 0, lp[i].nxt = n + 1;
  sh.insert(0);
  sh.insert(N - 1);
  for (register int i = (0); i <= (N - 1); ++i)
    lh[i].pre = 0, lh[i].nxt = N - 1;
  tp.n = n, th.n = N - 2;
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      ++sz;
      scanf("%d%d", pos + sz, h + sz), h[sz] += q;
      sp.insert(pos[sz]);
      sh.insert(h[sz]);
      node &u = lp[pos[sz]];
      u.id = sz;
      u.pre = *(--sp.find(pos[sz]));
      u.nxt = *(++sp.find(pos[sz]));
      lp[u.pre].nxt = pos[sz];
      lp[u.nxt].pre = pos[sz];
      node &v = lh[h[sz]];
      v.id = sz;
      v.pre = *(--sh.find(h[sz]));
      v.nxt = *(++sh.find(h[sz]));
      lh[v.pre].nxt = h[sz];
      lh[v.nxt].pre = h[sz];
      for (int i = h[sz]; i; i = lh[i].pre) {
        int id = lh[i].id;
        tp.ins(pos[id], 0);
      }
      for (int i = h[sz]; i; i = lh[i].pre) {
        int id = lh[i].id;
        int ans = tp.qmax(pos[id] + 1, tp.n) + 1;
        tp.ins(pos[id], ans);
        th.ins(h[id], ans);
      }
    } else if (type == 2) {
      int rk;
      scanf("%d", &rk);
      int idx = 0;
      while (rk--) {
        idx = lp[idx].nxt;
        th.ins(h[lp[idx].id], 0);
      }
      int id = lp[idx].id;
      tp.ins(pos[id], 0);
      for (idx = lp[idx].pre; idx; idx = lp[idx].pre) {
        int i = lp[idx].id;
        int ans = th.qmax(h[i] + 1, th.n) + 1;
        th.ins(h[i], ans);
        tp.ins(pos[i], ans);
      }
      node &u = lp[pos[id]];
      lp[u.pre].nxt = u.nxt;
      lp[u.nxt].pre = u.pre;
      node &v = lh[h[id]];
      lh[v.pre].nxt = v.nxt;
      lh[v.nxt].pre = v.pre;
      sp.erase(pos[id]);
      sh.erase(h[id]);
    } else
      assert(false);
    printf("%d\n", tp.qmax(1, tp.n));
  }
  return 0;
}
