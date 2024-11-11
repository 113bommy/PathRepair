#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
const char nl = '\n';
using namespace std;
const long long inf = 1e9;
const long long inf2 = 1e18 + 10;
const int mod = 1e9 + 7;
const long double eps = 1e-4;
const int logn = 19;
const int maxn = 5e5 + 5;
struct node {
  int ans0, p0, s0, tp0, ts0, ans1, p1, s1, tp1, ts1, len;
  void apply() {
    swap(ans0, ans1);
    swap(p0, p1);
    swap(s0, s1);
    swap(tp0, tp1);
    swap(ts0, ts1);
  }
};
node add(const node& a, const node& b) {
  node s = {max({a.ans0, b.ans0}),
            (a.p0 == a.len ? a.len + b.p0 : a.p0),
            (b.s0 == b.len ? b.len + a.s0 : b.s0),
            0,
            0,
            max({a.ans1, b.ans1}),
            (a.p1 == a.len ? a.len + b.p1 : a.p1),
            (b.s1 == b.len ? b.len + a.s1 : b.s1),
            0,
            0,
            a.len + b.len};
  s.tp0 = max({s.p0, s.p1, (a.p0 == a.len ? a.p0 + b.tp0 : 0),
               (a.tp0 == a.len ? b.s1 : 0) + a.tp0});
  s.tp1 = max({s.p0, s.p1, (a.p1 == a.len ? a.p1 + b.tp1 : 0),
               (a.tp1 == a.len ? b.s0 : 0) + a.tp1});
  s.ts0 = max({s.s0, s.s1, (b.s1 == b.len ? b.s1 + a.ts0 : 0),
               (b.ts0 == b.len ? a.s0 : 0) + b.ts0});
  s.ts1 = max({s.s0, s.s1, (b.s0 == b.len ? b.s0 + a.ts1 : 0),
               (b.ts1 == b.len ? a.s1 : 0) + b.ts1});
  s.ans0 = max({s.ans0, s.tp0, s.ts0, a.s0 + b.tp0, a.s1 + b.p1, a.ts0 + b.p1,
                a.s0 + b.p0});
  s.ans1 = max({s.ans1, s.tp1, s.ts1, a.s1 + b.tp1, a.s0 + b.p0, a.ts1 + b.p0,
                a.s1 + b.p1});
  return s;
}
node t[maxn * 4];
bool lp[maxn * 4];
bool a[maxn];
void build(int v, int tl, int tr) {
  if (tl == tr - 1) {
    if (a[tl]) {
      t[v] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    } else {
      t[v] = {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1};
    }
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v + 1, tl, tm);
    build(2 * v + 2, tm, tr);
    t[v] = add(t[2 * v + 1], t[2 * v + 2]);
  }
}
void update(int v, int tl, int tr, int l, int r) {
  if (l >= r)
    return;
  else if (tl == l && tr == r) {
    t[v].apply();
    lp[v] = !lp[v];
  } else {
    int tm = (tl + tr) / 2;
    update(2 * v + 1, tl, tm, l, min(r, tm));
    update(2 * v + 2, tm, tr, max(l, tm), r);
    t[v] = add(t[2 * v + 1], t[2 * v + 2]);
    if (lp[v]) t[v].apply();
  }
}
node query(int v, int tl, int tr, int l, int r) {
  if (l >= r)
    return {};
  else if (tl == l && tr == r)
    return t[v];
  else {
    int tm = (tl + tr) / 2;
    auto r1 = add(query(2 * v + 1, tl, tm, l, min(r, tm)),
                  query(2 * v + 2, tm, tr, max(l, tm), r));
    if (lp[v]) r1.apply();
    return r1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = (c == '<');
  }
  build(0, 0, n);
  while (q--) {
    int l, r;
    cin >> l >> r;
    update(0, 0, n, l - 1, r);
    cout << query(0, 0, n, l - 1, r).ans0 << nl;
  }
}
