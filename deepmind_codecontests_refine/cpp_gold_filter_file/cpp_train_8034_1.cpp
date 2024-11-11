#include <bits/stdc++.h>
using namespace std;
const long long oo = 2e9;
const double PI = acos(-1);
const long long M = 1e9 + 7;
long long oor(long long a, long long b) { return (a | b); }
struct mseg {
  int best, a1[10];
  int& operator[](int x) { return a1[x]; }
} seg[800010];
mseg change(mseg& seg, int vl) {
  int x = vl;
  for (int i = 0; i <= 9; ++i) {
    if (x % 10 == 0)
      seg[i] = oo;
    else
      seg[i] = vl;
    x /= 10;
  }
  seg.best = oo;
  return seg;
}
mseg marge(mseg a, mseg b) {
  mseg seg;
  seg.best = min(b.best, a.best);
  for (int i = 0; i <= 9; ++i) {
    seg[i] = min(a[i], b[i]);
    if (a[i] != oo && b[i] != oo) seg.best = min(a[i] + b[i], seg.best);
  }
  return seg;
}
int a[200010];
void build(int n, int s, int e) {
  if (s == e) {
    change(seg[n], a[s]);
    return;
  }
  build(n * 2, s, (s + e) / 2);
  build(n * 2 + 1, (s + e) / 2 + 1, e);
  seg[n] = marge(seg[n * 2], seg[n * 2 + 1]);
}
mseg get(int n, int s, int e, int l, int r) {
  if (s > r || e < l) {
    mseg s1 = change(s1, oo);
    return s1;
  }
  if (s >= l && e <= r) return seg[n];
  return marge(get(n * 2, s, (s + e) / 2, l, r),
               get(n * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
void update(int n, int s, int e, int at, int vl) {
  if (s == e) {
    change(seg[n], vl);
    return;
  }
  int md = (s + e) / 2;
  if (md >= at)
    update(n * 2, s, md, at, vl);
  else
    update(n * 2 + 1, md + 1, e, at, vl);
  seg[n] = marge(seg[n * 2], seg[n * 2 + 1]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  build(1, 0, n - 1);
  while (m--) {
    int t;
    cin >> t;
    if (t - 1) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int x = get(1, 0, n - 1, l, r).best;
      cout << (x == oo ? -1 : x) << endl;
    } else {
      int pos, vl;
      cin >> pos >> vl;
      pos--;
      update(1, 0, n - 1, pos, vl);
    }
  }
}
