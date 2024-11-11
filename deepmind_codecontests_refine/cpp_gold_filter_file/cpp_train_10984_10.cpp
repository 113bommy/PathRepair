#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int head[N], cnt, c[N], dfn[N], tot, ed[N], rk[N];
long long sta[N << 2], ly[N << 2];
struct edge {
  int next, to;
} e[N << 1];
int main() {
  auto add = [&](int u, int v) {
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
  };
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]), c[i]--;
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    add(a, b);
    add(b, a);
  }
  function<void(int, int)> dfs = [&](int u, int f) {
    dfn[u] = ++tot;
    rk[tot] = u;
    for (int i = head[u]; i; i = e[i].next)
      if (e[i].to != f) dfs(e[i].to, u);
    ed[u] = tot;
  };
  dfs(1, 0);
  function<void(int)> push_down = [&](int rt) {
    if (ly[rt]) {
      ly[(rt << 1)] = ly[(rt << 1 | 1)] = sta[(rt << 1)] = sta[(rt << 1 | 1)] =
          ly[rt];
      ly[rt] = 0;
    }
  };
  function<void(int, int, int)> build = [&](int l, int r, int rt) {
    if (l == r) {
      sta[rt] = 1ll << c[rk[l]];
      return;
    }
    int mid = l + r >> 1;
    build(l, mid, (rt << 1));
    build(mid + 1, r, (rt << 1 | 1));
    sta[rt] = sta[(rt << 1)] | sta[(rt << 1 | 1)];
  };
  function<void(int, int, int, int, int, int)> upd =
      [&](int l, int r, int L, int R, int val, int rt) {
        if (L <= l && r <= R) {
          sta[rt] = 1ll << val;
          ly[rt] = 1ll << val;
          return;
        }
        int mid = l + r >> 1;
        push_down(rt);
        if (L <= mid) upd(l, mid, L, R, val, (rt << 1));
        if (mid < R) upd(mid + 1, r, L, R, val, (rt << 1 | 1));
        sta[rt] = sta[(rt << 1)] | sta[(rt << 1 | 1)];
      };
  function<long long(int, int, int, int, int)> qry = [&](int l, int r, int L,
                                                         int R, int rt) {
    if (L <= l && r <= R) return sta[rt];
    int mid = l + r >> 1;
    long long ans = 0;
    push_down(rt);
    if (L <= mid) ans |= qry(l, mid, L, R, (rt << 1));
    if (mid < R) ans |= qry(mid + 1, r, L, R, (rt << 1 | 1));
    return ans;
  };
  build(1, n, 1);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int v, c;
      scanf("%d %d", &v, &c);
      upd(1, n, dfn[v], ed[v], c - 1, 1);
    } else {
      int v;
      scanf("%d", &v);
      long long ans = qry(1, n, dfn[v], ed[v], 1);
      int res = 0;
      for (int i = 0; i < 60; i++) res += (ans >> i) & 1;
      printf("%d\n", res);
    }
  }
  return 0;
}
