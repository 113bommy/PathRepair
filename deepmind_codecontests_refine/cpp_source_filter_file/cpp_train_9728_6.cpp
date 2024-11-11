#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 101010;
const int INF = 1e9;
struct Node {
  long long x;
  int mx, mn, cnt;
  Node() {}
} t[4 * MAXN];
int mod[4 * MAXN];
int a[MAXN];
void pull(int v) {
  t[v].x = t[v << 1].x + t[(v << 1) + 1].x;
  t[v].mx = max(t[v << 1].x, t[(v << 1) + 1].x);
  t[v].mn = min(t[v << 1].x, t[(v << 1) + 1].x);
  t[v].cnt = t[v << 1].cnt + t[(v << 1) + 1].cnt;
}
void push(int v) {
  if (mod[v] == 0) return;
  int l = (v << 1);
  int r = (v << 1) + 1;
  int m = mod[v];
  t[l].mn %= m;
  t[r].mn %= m;
  t[l].mx %= m;
  t[r].mx %= m;
  t[l].x = t[l].mx * t[l].cnt;
  t[r].x = t[r].mx * t[r].cnt;
  mod[l] = m;
  mod[r] = m;
}
void build(int v, int l, int r) {
  if (l == r - 1) {
    t[v].x = (long long)a[l];
    t[v].mn = a[l];
    t[v].mx = a[l];
    t[v].cnt = 1;
    return;
  }
  int m = (l + r) >> 1;
  build(v << 1, l, m);
  build((v << 1) + 1, m, r);
  pull(v);
}
void build(int N) { build(1, 0, N); }
void set_x(int v, int l, int r, int pos, int x) {
  if (l == r - 1) {
    t[v].x = (long long)x;
    t[v].mn = x;
    t[v].mx = x;
    return;
  }
  int m = (l + r) >> 1;
  if (pos < m) {
    set_x(v << 1, l, m, pos, x);
  } else {
    set_x((v << 1) + 1, m, r, pos, x);
  }
  pull(v);
}
long long sum(int v, int l, int r, int tl, int tr) {
  if (l >= tr || r <= tl) {
    return 0LL;
  }
  if (l >= tl && r <= tr) {
    return (long long)t[v].x;
  }
  int m = (l + r) >> 1;
  long long r1 = sum(v << 1, l, m, tl, tr);
  long long r2 = sum((v << 1) + 1, m, r, tl, tr);
  pull(v);
  return r1 + r2;
}
void mod_x(int v, int l, int r, int tl, int tr, int x) {
  if (l >= tr || r <= tl || t[v].mx < x) {
    return;
  }
  if (l == r - 1) {
    mod[v] = x;
    t[v].mn %= x;
    t[v].mx %= x;
    t[v].x %= x;
    return;
  }
  int m = (l + r) >> 1;
  mod_x(v << 1, l, m, tl, tr, x);
  mod_x((v << 1) + 1, m, r, tl, tr, x);
  pull(v);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(mod, 0, sizeof mod);
  build(n);
  int t, l, r, x, pos;
  for (int i = 0; i < m; i++) {
    cin >> t;
    if (t == 1) {
      cin >> l >> r;
      l--;
      cout << sum(1, 0, n, l, r) << '\n';
    } else if (t == 2) {
      cin >> l >> r >> x;
      mod_x(1, 0, n, l - 1, r, x);
    } else {
      cin >> pos >> x;
      set_x(1, 0, n, pos - 1, x);
    }
  }
  return 0;
}
