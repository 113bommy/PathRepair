#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5e5 + 42, md = 1e9 + 7;
int add(int x, int y) {
  x += y;
  x %= md;
  while (x < 0) x += md;
  return x;
}
long long mul(long long x, long long y) {
  long long ans = (x * 1ll * y) % md;
  while (ans < 0) ans += md;
  return ans;
}
string s;
int n, m;
struct vert {
  long long val[4], len;
};
vert comb(vert a, vert b, int l, int r) {
  vert c;
  int na = a.len == 1 ? 0 : 1;
  int nb = b.len == 1 ? 0 : 2;
  c.len = a.len + b.len;
  c.val[0] = mul(a.val[na], b.val[nb]);
  c.val[1] = mul(a.val[na], b.val[3]);
  c.val[2] = mul(a.val[3], b.val[nb]);
  c.val[3] = mul(a.val[3], b.val[3]);
  if (l == 1) {
    na = a.len == 1 ? 2 : 0;
    nb = b.len == 1 ? 1 : 0;
    c.val[na + nb] =
        add(c.val[na + nb], mul(mul(a.val[0], b.val[0]), 19 - (l * 10 + r)));
    c.val[1 + na] =
        add(c.val[1 + na], mul(mul(a.val[0], b.val[1]), 19 - (l * 10 + r)));
    c.val[2 + nb] =
        add(c.val[2 + nb], mul(mul(a.val[2], b.val[0]), 19 - (l * 10 + r)));
    c.val[3] = add(c.val[3], mul(mul(a.val[2], b.val[1]), 19 - (l * 10 + r)));
  }
  return c;
}
vert st[4 * N];
void build(int v, int tl, int tr) {
  st[v].len = tr - tl + 1;
  if (tl == tr) {
    st[v].val[0] = 1;
    st[v].val[3] = s[tl] + 1;
    return;
  }
  int tm = ((tl + tr) >> 1);
  build((v << 1), tl, tm);
  build((v << 1) + 1, tm + 1, tr);
  st[v] = comb(st[(v << 1)], st[(v << 1) + 1], s[tm], s[tm + 1]);
}
void upd(int v, int tl, int tr, int ind, int val) {
  if (tl == tr) {
    s[tl] = val;
    st[v].val[3] = s[tl] + 1;
    return;
  }
  int tm = ((tl + tr) >> 1);
  if (ind <= tm)
    upd((v << 1), tl, tm, ind, val);
  else
    upd((v << 1) + 1, tm + 1, tr, ind, val);
  st[v] = comb(st[(v << 1)], st[(v << 1) + 1], s[tm], s[tm + 1]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> s;
  for (int i = 0; i < n; i++) s[i] -= '0';
  memset(st, 0, sizeof(st));
  build(1, 0, n - 1);
  while (m--) {
    int x, v;
    cin >> x >> v;
    x--;
    upd(1, 0, n - 1, x, v);
    cout << st[1].val[3] << endl;
  }
  return 0;
}
