#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 0, fl = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fl = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch - '0');
  return x * fl;
}
const int N = 100005;
const long long mod = 1e9 + 7;
int n, m, ct[N], a[N], b[N], len;
bool can[N];
void upd(long long &x, long long y) { x = (x + y) % mod; }
namespace bf {
struct bit {
  long long t[N];
  void clear() {
    for (int i = 1; i <= len; i++) t[i] = 0LL;
  }
  void mdf(int x, long long y) {
    for (int i = x; i <= len; i += (i & -i)) upd(t[i], y);
  }
  long long qry(int x) {
    long long res = 0LL;
    for (int i = x; i; i -= (i & -i)) upd(res, t[i]);
    return res;
  }
} st[6];
long long f[N][6], p[N][6];
long long getans() {
  long long ans = 0LL;
  for (int i = 1; i <= 5; i++) {
    st[i].clear();
    for (int j = 1; j <= len; j++) p[j][i] = 0LL;
  }
  for (int i = 1; i <= n; i++) {
    f[i][1] = 1LL;
    if (can[i]) {
      f[i][2] = st[1].qry(a[i]);
      f[i][3] = p[a[i]][2];
      f[i][4] = p[a[i]][3];
    } else {
      f[i][2] = f[i][3] = f[i][4] = 0LL;
    }
    f[i][5] = (st[4].qry(len) - st[4].qry(a[i] - 1) + mod) % mod;
    st[1].mdf(a[i], f[i][1]);
    upd(p[a[i]][2], f[i][2]);
    upd(p[a[i]][3], f[i][3]);
    st[4].mdf(a[i], f[i][4]);
    upd(ans, f[i][5]);
  }
  return ans;
}
void work() {
  while (m--) {
    int opt = read(), id = read();
    if (opt == 1)
      can[id] = 0;
    else
      can[id] = 1;
    cout << getans() << '\n';
  }
}
}  // namespace bf
namespace subtask1 {
int ll[N], rr[N], rt[N];
struct bit {
  int t[N];
  void clear() { memset(t, 0, sizeof(t)); }
  void mdf(int x) {
    for (int i = x; i <= len; i += (i & -i)) t[i]++;
  }
  int qry(int x) {
    int res = 0;
    for (int i = x; i; i -= (i & -i)) res += t[i];
    return res;
  }
} st;
struct node {
  int f[3][3];
} t[N << 5];
int ls[N << 5], rs[N << 5], tot;
void upd_(int x, long long y) { x = (1LL * x + 1LL * y) % mod; }
void psu(int rt) {
  int _l = ls[rt], _r = rs[rt];
  for (int i = 0; i < 3; i++) {
    for (int j = i; j < 3; j++) {
      t[rt].f[i][j] = (t[_l].f[i][j] + t[_r].f[i][j]) % mod;
      for (int k = i; k < j; k++) {
        upd_(t[rt].f[i][j], 1LL * t[_l].f[i][k] * t[_r].f[k + 1][j] % mod);
      }
    }
  }
}
void chg(int rt, int l, int r, int pv, int w) {
  if (l == r) {
    t[rt].f[0][0] = 1LL * w * ll[pv];
    t[rt].f[1][1] = 1LL * w;
    t[rt].f[2][2] = 1LL * w * rr[pv];
    return;
  }
  int mid = (l + r) >> 1;
  if (pv <= mid) {
    if (!ls[rt]) ls[rt] = ++tot;
    chg(ls[rt], l, mid, pv, w);
  } else {
    if (!rs[rt]) rs[rt] = ++tot;
    chg(rs[rt], mid + 1, r, pv, w);
  }
  psu(rt);
}
void work() {
  st.clear();
  for (int i = 1; i <= n; i++) {
    ll[i] = st.qry(a[i]);
    st.mdf(a[i]);
  }
  st.clear();
  for (int i = n; i; i--) {
    rr[i] = st.qry(a[i]);
    st.mdf(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (!rt[a[i]]) rt[a[i]] = ++tot;
    chg(rt[a[i]], 1, n, i, 1);
  }
  long long ans = 0LL;
  for (int i = 1; i <= len; i++) upd(ans, t[rt[i]].f[0][2]);
  while (m--) {
    int opt = read(), id = read();
    int v = a[id];
    upd(ans, mod - t[rt[v]].f[0][2]);
    if (opt == 1)
      chg(rt[v], 1, n, id, 0);
    else
      chg(rt[v], 1, n, id, 1);
    upd(ans, t[rt[v]].f[0][2]);
    cout << ans << '\n';
  }
}
}  // namespace subtask1
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = b[i] = read();
  sort(b + 1, b + n + 1);
  len = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;
    can[i] = 1;
  }
  m = read();
  if (n * m <= 1e6)
    bf::work();
  else
    subtask1::work();
  return 0;
}
