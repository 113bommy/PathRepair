#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x) {
  x = 0;
  long long f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
long long i, j, k, m, n, s, t;
const long long N = 4e5 + 10;
long long dfn[N], rak[N], head[N], size[N];
long long a[N << 2], lazy[N << 2], val[N << 1], sum[N], rk[N << 1];
struct fu {
  long long u, v, nxt, val;
} edge[N << 1];
void work(long long aa, long long bb, long long cc) {
  edge[++k].nxt = head[aa];
  head[aa] = k;
  edge[k].v = bb;
  edge[k].u = aa;
  edge[k].val = cc;
}
void push_up(long long rt) { a[rt] = min(a[rt << 1], a[rt << 1 | 1]); }
void push_down(long long rt) {
  a[rt << 1] += lazy[rt];
  a[rt << 1 | 1] += lazy[rt];
  lazy[rt << 1] += lazy[rt];
  lazy[rt << 1 | 1] += lazy[rt];
  lazy[rt] = 0;
}
void updata(long long l, long long r, long long rt, long long x, long long y,
            long long c) {
  if (x <= l && y >= r) {
    a[rt] += c;
    lazy[rt] += c;
    return;
  }
  long long mid = (l + r) / 2;
  push_down(rt);
  if (x <= mid) updata(l, mid, rt << 1, x, y, c);
  if (y > mid) updata(mid + 1, r, rt << 1 | 1, x, y, c);
  push_up(rt);
}
long long quert(long long l, long long r, long long rt, long long x,
                long long y) {
  if (x <= l && y >= r) return a[rt];
  long long mid = (l + r) / 2;
  long long ret = 1e17;
  push_down(rt);
  if (x <= mid) ret = min(ret, quert(l, mid, rt << 1, x, y));
  if (y > mid) ret = min(ret, quert(mid + 1, r, rt << 1 | 1, x, y));
  return ret;
}
void build(long long l, long long r, long long rt) {
  if (l == r) {
    a[rt] = sum[rak[l]];
    return;
  }
  long long mid = (l + r) / 2;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  push_up(rt);
}
void dfs(long long u) {
  dfn[u] = ++t;
  rak[dfn[u]] = u;
  for (long long i = head[u]; i; i = edge[i].nxt) {
    long long v = edge[i].v;
    if (v == 1) continue;
    sum[v] = sum[u] + edge[i].val;
    dfs(v);
    size[u] += size[v];
  }
  sum[u] += val[u + n];
  size[u]++;
}
signed main() {
  read(n), read(m);
  for (i = 1; i <= n - 1; i++) {
    long long x, y, z;
    read(x), read(y), read(z);
    rk[i] = y;
    val[y] = z;
    work(x, y, z);
  }
  for (i = 1; i <= n - 1; i++) {
    long long x, y, z;
    read(x), read(y), read(z);
    rk[i + n - 1] = x;
    val[x + n] = z;
  }
  dfs(1);
  build(1, n, 1);
  for (i = 1; i <= m; i++) {
    long long op, x, y;
    read(op), read(x), read(y);
    if (op == 1) {
      if (x <= n - 1) {
        updata(1, n, 1, dfn[rk[x]], dfn[rk[x]] + size[rk[x]] - 1,
               y - val[rk[x]]);
        val[rk[x]] = y;
      } else {
        updata(1, n, 1, dfn[rk[x]], dfn[rk[x]], y - val[rk[x] + n]);
        val[rk[x] + n] = y;
      }
    } else {
      if (dfn[y] < dfn[x] + size[x] && dfn[y] >= dfn[x])
        printf("%lld\n", (quert(1, n, 1, dfn[y], dfn[y]) - val[y + n]) -
                             (quert(1, n, 1, dfn[x], dfn[x]) - val[x + n]));
      else
        printf("%lld\n", quert(1, n, 1, dfn[x], dfn[x] + size[x] - 1) -
                             (quert(1, n, 1, dfn[x], dfn[x]) - val[x + n]) +
                             (quert(1, n, 1, dfn[y], dfn[y]) - val[y + n]));
    }
  }
  return 0;
}
