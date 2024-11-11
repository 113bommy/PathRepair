#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct Node {
  int x, y;
  inline bool operator<(const Node& rhs) const { return x < rhs.x; }
};
set<Node> S[200010];
int lz1[200010 * 4], lz2[200010 * 4], q[200010 * 4];
int n, Q;
inline void update(int l, int r, int o, int z1, int z2) {
  lz1[o] = 1ll * lz1[o] * z1 % 998244353;
  lz2[o] = (1ll * lz2[o] * z1 + z2) % 998244353;
  q[o] = (1ll * q[o] * z1 + 1ll * z2 * (r - l + 1)) % 998244353;
}
inline void pushdown(int l, int r, int o) {
  int mid = (l + r) / 2;
  update(l, mid, 2 * o, lz1[o], lz2[o]);
  update(mid + 1, r, 2 * o + 1, lz1[o], lz2[o]);
  lz1[o] = 1;
  lz2[o] = 0;
}
inline void change(int l, int r, int o, int x, int y, int z1, int z2) {
  if (x <= l && r <= y) {
    update(l, r, o, z1, z2);
    return;
  }
  int mid = (l + r) / 2;
  pushdown(l, r, o);
  if (x <= mid) change(l, mid, 2 * o, x, y, z1, z2);
  if (y > mid) change(mid + 1, r, 2 * o + 1, x, y, z2, z2);
  q[o] = q[2 * o] + q[2 * o + 1];
  if (q[o] >= 998244353) q[o] -= 998244353;
}
inline int query(int l, int r, int o, int x, int y) {
  if (x <= l && r <= y) return q[o];
  int mid = (l + r) / 2, ret = 0;
  pushdown(l, r, o);
  if (x <= mid) ret += query(l, mid, 2 * o, x, y);
  if (y > mid) ret += query(mid + 1, r, 2 * o + 1, x, y);
  if (ret >= 998244353) ret -= 998244353;
  return ret;
}
inline bool check(Node A, Node B) {
  if (A.y < B.x || B.y < A.x) return false;
  return true;
}
Node a[200010];
int cnt;
inline void debug(int x) {
  printf("S[%d] :: \n", x);
  for (set<Node>::iterator i = S[x].begin(); i != S[x].end(); ++i) {
    printf("%d %d | ", i->x, i->y);
  }
  puts("");
}
inline void Do(int l, int r, int x) {
  Node t = (Node){l, r};
  cnt = 0;
  set<Node>::iterator it = S[x].lower_bound(t);
  if (it != S[x].begin()) {
    --it;
    for (set<Node>::iterator i = it;; --i) {
      if (check(*i, t))
        a[++cnt] = *i;
      else
        break;
      if (i == S[x].begin()) break;
    }
    ++it;
  }
  for (int i = 1; i <= cnt / 2; ++i) swap(a[i], a[cnt - i + 1]);
  for (set<Node>::iterator i = it; i != S[x].end(); ++i) {
    if (check(*i, t))
      a[++cnt] = *i;
    else
      break;
  }
  for (int i = 1; i <= cnt; ++i) {
    int L = max(a[i].x, l), R = min(a[i].y, r);
    change(1, n, 1, L, R, 2, 0);
  }
  for (int i = 1; i < cnt; ++i) {
    if (a[i].y < a[i + 1].x - 1) {
      change(1, n, 1, a[i].y + 1, a[i + 1].x - 1, 1, 1);
    }
  }
  if (cnt) {
    if (a[1].x > l) change(1, n, 1, l, a[1].x - 1, 1, 1);
    if (a[cnt].y < r) change(1, n, 1, a[cnt].y + 1, r, 1, 1);
  } else
    change(1, n, 1, l, r, 1, 1);
  for (int i = 1; i <= cnt; ++i) {
    S[x].erase(a[i]);
  }
  if (cnt)
    S[x].insert((Node){min(l, a[1].x), max(r, a[cnt].y)});
  else
    S[x].insert(t);
}
int main() {
  n = read(), Q = read();
  for (int i = 1; i <= n * 4; ++i) {
    lz1[i] = 1;
  }
  while (Q--) {
    int op = read(), l = read(), r = read();
    if (op == 1) {
      int x = read();
      Do(l, r, x);
    } else {
      printf("%d\n", query(1, n, 1, l, r));
    }
  }
}
