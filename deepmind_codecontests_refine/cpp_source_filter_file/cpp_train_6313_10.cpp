#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long N = 1e5 + 1;
const long long mod = 1e9 + 7;
const long double eps = 1E-7;
long long t[4 * N], lz[4 * N];
long long n, a[N], k, x, ans;
void push(int v, int tl, int tr) {
  if (!lz[v]) return;
  t[v * 2] += lz[v];
  t[v * 2 + 1] += lz[v];
  lz[v * 2] += lz[v];
  lz[v * 2 + 1] += lz[v];
  lz[v] = 0;
}
void bld(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = a[tl];
  else {
    int tm = (tl + tr) / 2;
    bld(v * 2, tl, tm);
    bld(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}
void upd(int v, int tl, int tr, int l, int r, int val) {
  if (l > r) return;
  if (tl == l && tr == r) {
    t[v] += val;
    lz[v] = val;
  } else {
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(tm, r), val);
    upd(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}
void check(int v, int tl, int tr) {
  if (t[v] >= 0) return;
  if (tl == tr) {
    k--;
    ans += t[v];
    t[v] = INF;
    return;
  }
  push(v, tl, tr);
  int tm = (tl + tr) / 2;
  check(v * 2, tl, tm);
  check(v * 2 + 1, tm + 1, tr);
  t[v] = min(t[v * 2], t[v * 2 + 1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  bld(1, 1, n);
  for (int i = 1; i <= n; i++) {
    k++;
    cin >> x;
    ans = k * x;
    upd(1, 1, n, 1, i, -x);
    check(1, 1, n);
    cout << ans << endl;
  }
}
