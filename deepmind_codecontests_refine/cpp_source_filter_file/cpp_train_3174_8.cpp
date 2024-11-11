#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const long long MXN = 2e9;
int n;
long long x[N];
long long f[N], g[N];
long long d[N];
int rt;
struct segment_tree {
  int ch[N * 40][2];
  int mxv[N * 40], tot;
  inline void init() { tot = rt = 0; }
  inline int new_node() {
    ++tot;
    mxv[tot] = ch[tot][0] = ch[tot][1] = 0;
    return tot;
  }
  inline void insert(int &x, long long l, long long r, long long pos, int v) {
    if (!x) x = new_node();
    mxv[x] = max(mxv[x], v);
    if (l == r) return;
    if (pos <= (l + r) / 2)
      insert(ch[x][0], l, (l + r) / 2, pos, v);
    else
      insert(ch[x][1], (l + r) / 2 + 1, r, pos, v);
  }
  inline int query(int x, long long l, long long r, long long ql,
                   long long qr) {
    if (ql > r || qr < l || !x) return 0;
    if (ql <= l && r <= qr) return mxv[x];
    return max(query(ch[x][0], l, (l + r) / 2, ql, qr),
               query(ch[x][1], (l + r) / 2 + 1, r, ql, qr));
  }
} s;
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n + 1; ++i) scanf("%lld", x + i);
  for (int i = 1; i <= n; ++i) scanf("%lld", d + i), d[i] *= 2;
  memset(f, -1, sizeof f);
  s.init();
  for (int i = 1; i <= n; ++i) {
    f[i] = max(f[i], d[i] - x[i]);
    int mxv = s.query(rt, 0, MXN, x[i], MXN);
    if (mxv > 0) f[i] = max(f[i], d[i] - (x[i] - mxv));
    if (f[i] >= 0) s.insert(rt, 0, MXN, x[i] + f[i], x[i]);
  }
  memset(g, -1, sizeof g);
  s.init();
  for (int i = n; i >= 1; --i) {
    g[i] = max(g[i], d[i] - (x[n + 1] - x[i]));
    int mxv = s.query(rt, 0, MXN, 0, x[i]);
    if (mxv > 0) g[i] = max(g[i], d[i] - (x[n + 1] - mxv - x[i]));
    if (g[i] >= 0) s.insert(rt, 0, MXN, x[i] - g[i], x[n + 1] - x[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (x[i] + f[i] >= x[n + 1]) {
      puts("0");
      return 0;
    }
    if (x[i] - g[i] <= 0) {
      puts("0");
      return 0;
    }
  }
  s.init();
  long long ans = x[n + 1] - x[0];
  for (int i = 1; i <= n; ++i)
    if (f[i] >= 0) ans = min(ans, x[n + 1] - x[i]);
  for (int i = 1; i <= n; ++i)
    if (g[i] >= 0) ans = min(ans, x[i]);
  for (int i = 1; i <= n; ++i) {
    int res = s.query(rt, 0, MXN, x[i] - g[i], MXN);
    if (g[i] >= 0 && res > 0) ans = min(ans, x[i] - res);
    if (f[i] >= 0) s.insert(rt, 0, MXN, x[i] + f[i], x[i]);
  }
  printf("%.1lf\n", ans * 0.5);
  return 0;
}
