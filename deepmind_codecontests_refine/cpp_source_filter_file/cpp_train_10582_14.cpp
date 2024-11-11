#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 1;
inline int read() {
  char c;
  int out = 0;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) {
    out = (out << 3) + (out << 1) + c - '0';
  }
  return out;
}
int tt[Maxn], num[Maxn];
int par[Maxn];
int n, m, tot;
int a[Maxn], b[Maxn];
struct Tri {
  int T, x, y, id;
  inline Tri(int T = 0, int x = 0, int y = 0, int id = 0)
      : T(T), x(x), y(y), id(id) {}
  inline bool operator<(const Tri &b) const {
    if (par[x] != par[b.x])
      return par[x] < par[b.x];
    else if (par[y] != par[b.y])
      return par[y] < par[b.y];
    else
      return T < b.T;
  }
} q[Maxn];
struct upd {
  int pos, pr, nx;
  inline upd(int pos = 0, int pr = 0, int nx = 0) : pos(pos), pr(pr), nx(nx) {}
};
upd update[Maxn];
inline void add(int x) {
  tt[num[x]]--;
  ++tt[++num[x]];
}
inline void del(int x) {
  tt[num[x]]--;
  ++tt[--num[x]];
}
int ans[Maxn];
int val[Maxn], ti;
int main() {
  n = read();
  m = read();
  tt[0] = Maxn;
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    b[i] = a[i];
    val[i] = a[i];
  }
  int tob = n;
  for (int i = 1; i <= m; ++i) {
    int x, y, z;
    x = read();
    y = read();
    z = read();
    if (x == 1)
      q[++tot] = Tri(ti, y, z, tot);
    else {
      b[++tob] = z;
      update[++ti] = upd(y, val[y], z);
      val[y] = z;
    }
  }
  sort(b + 1, b + tob + 1);
  int cntk = unique(b + 1, b + tob + 1) - b - 1;
  for (int i = 1; i <= n; ++i) {
    par[i] = i / sqrt(n);
    a[i] = lower_bound(b + 1, b + cntk + 1, a[i]) - b;
  }
  for (int i = 1; i <= ti; ++i) {
    update[i].nx = lower_bound(b + 1, b + cntk + 1, update[i].nx) - b;
    update[i].pr = lower_bound(b + 1, b + cntk + 1, update[i].pr) - b;
  }
  sort(q + 1, q + tot + 1);
  int cur = 0, lc = 0, rc = 0;
  for (int i = 1; i <= tot; ++i) {
    int cx = q[i].x, cy = q[i].y, ct = q[i].T;
    while (cur < ct) {
      ++cur;
      int pp = update[cur].pos;
      if (lc <= pp && pp <= rc) del(a[pp]);
      a[pp] = update[cur].nx;
      if (lc <= pp && pp <= rc) add(a[pp]);
    }
    while (cur > ct) {
      int pp = update[cur].pos;
      if (lc <= pp && pp <= rc) del(a[pp]);
      a[pp] = update[cur].nx;
      if (lc <= pp && pp <= rc) add(a[pp]);
      --cur;
    }
    while (lc > cx) add(a[--lc]);
    while (rc < cy) add(a[++rc]);
    while (lc < cx) del(a[lc++]);
    while (rc > cy) del(a[rc--]);
    int cans;
    for (int j = 0; j < Maxn; ++j) {
      cans = j;
      if (tt[j] == 0) break;
    }
    ans[q[i].id] = cans;
  }
  for (int i = 1; i <= tot; ++i) printf("%d ", ans[i]);
  return 0;
}
