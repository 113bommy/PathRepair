#include <bits/stdc++.h>
using namespace std;
template <typename X, typename Y>
static inline void xmin(X &x, Y y) {
  if (y < x) x = y;
}
template <typename X, typename Y>
static inline void xmax(X &x, Y y) {
  if (x < y) x = y;
}
long long pw(long long x, long long y, long long md) {
  if (!y) return 1;
  if (y & 1) return (x * pw(x, y - 1, md)) % md;
  long long tmp = pw(x, y / 2, md);
  return (tmp * tmp) % md;
}
int n, a[200001], sm[200001], seg[524288];
void ins(int x, int v, int s = 1, int e = n, int i = 1) {
  seg[i] += v;
  int md = (s + e) / 2;
  if (s == e) return;
  if (x > md)
    ins(x, v, md + 1, e, 2 * i + 1);
  else
    ins(x, v, s, md, 2 * i);
}
int que(int x, int s = 1, int e = n, int i = 1) {
  if (s > x) return 0;
  if (e <= x) return seg[i];
  int md = (s + e) / 2;
  return que(x, s, md, 2 * i) + que(x, md + 1, e, 2 * i + 1);
}
int elt(int x, int s = 1, int e = n, int i = 1) {
  if (s == e) return s;
  int md = (s + e) / 2;
  return seg[2 * i] >= x ? elt(x, s, md, 2 * i)
                         : elt(x - seg[2 * i], md + 1, e, 2 * i + 1);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], ins(a[i] + 1, 1);
  for (int i = 1; i <= n; ++i) ins(a[i] + 1, -1), sm[i] = que(a[i] + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i], ins(a[i] + 1, 1);
  for (int i = 1; i <= n; ++i) ins(a[i] + 1, -1), sm[i] += que(a[i] + 1);
  for (int i = n; i >= 1; --i)
    if (sm[i] > n - i) sm[i] -= n - i + 1, ++sm[i - 1];
  for (int i = 1; i <= n; ++i) ins(i, 1);
  for (int i = 1; i <= n; ++i) {
    sm[i] = elt(sm[i] + 1);
    ins(sm[i], -1);
  }
  for (int i = 1; i <= n; ++i) cout << sm[i] - 1 << ' ';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int TESTS = 1;
  while (TESTS--) solve();
  return 0;
}
