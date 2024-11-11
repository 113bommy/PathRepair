#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int maxn = 1000 * 100 + 5;
const long long inf = 9223372036854775807;
const long long mod = 60;
const long long lg = 60;
int n, m, seg[lg][4 * maxn], ans, a[4 * maxn], sz = 1, t, sum[lg][4 * maxn];
void build(int x, int lx, int rx) {
  if (rx - lx == 1) {
    for (int i = 0; i < lg; i++) {
      if (a[lx] == 0 || i % a[lx] == 0) {
        seg[i][x] = 2;
        sum[i][x] = 2;
      } else {
        seg[i][x] = 1;
        sum[i][x] = 1;
      }
    }
    return;
  }
  int mid = lx + rx >> 1;
  build(x << 1, lx, mid);
  build(x << 1 | 1, mid, rx);
  for (int i = 0; i < lg; i++) {
    seg[i][x] =
        (seg[i][x << 1] + seg[(i + seg[i][x << 1]) % lg][x << 1 | 1]) % mod;
    sum[i][x] = sum[i][x << 1] + sum[(i + sum[i][x << 1]) % mod][x << 1 | 1];
  }
}
void upd(int i, int v, int x = 1, int lx = 0, int rx = sz) {
  if (rx - lx == 1) {
    a[lx] = v;
    for (int i = 0; i < lg; i++) {
      if (a[lx] == 0 || i % a[lx] == 0) {
        seg[i][x] = 2;
        sum[i][x] = 2;
      } else {
        seg[i][x] = 1;
        sum[i][x] = 1;
      }
    }
    return;
  }
  int mid = lx + rx >> 1;
  if (i < mid) {
    upd(i, v, x << 1, lx, mid);
  } else {
    upd(i, v, x << 1 | 1, mid, rx);
  }
  for (int i = 0; i < lg; i++) {
    seg[i][x] =
        (seg[i][x << 1] + seg[(i + seg[i][x << 1]) % lg][x << 1 | 1]) % mod;
    sum[i][x] = sum[i][x << 1] + seg[(i + sum[i][x << 1]) % mod][x << 1 | 1];
  }
}
void get(int l, int r, int x = 1, int lx = 0, int rx = sz) {
  if (rx <= l || lx >= r) {
    return;
  }
  if (lx >= l && rx <= r) {
    ans += sum[t][x];
    t = (t + sum[t][x]) % 60;
    return;
  }
  int mid = lx + rx >> 1;
  get(l, r, x << 1, lx, mid);
  get(l, r, x << 1 | 1, mid, rx);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  while (sz <= n) sz *= 2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 0, sz);
  cin >> m;
  char c;
  int l, r;
  for (int i = 1; i <= m; i++) {
    cin >> c >> l >> r;
    if (c == 'A') {
      ans = 0;
      t = 0;
      get(l, r);
      cout << ans << endl;
    } else {
      upd(l, r);
    }
  }
}
