#include <bits/stdc++.h>
using namespace std;
const int64_t M1 = 998244353;
const int64_t M2 = 1000000007;
int64_t seg[800010];
int64_t a[200001];
int64_t b[200001];
void upd(int64_t n, int64_t s, int64_t e, int64_t i, int64_t x) {
  if (s == e)
    seg[n] = x;
  else {
    int64_t m = (s + e) >> 1;
    if (i <= m)
      upd(n << 1, s, m, i, x);
    else
      upd(n << 1 | 1, m + 1, e, i, x);
    seg[n] = max(seg[n << 1], seg[n << 1 | 1]);
  }
}
int64_t get(int64_t n, int64_t s, int64_t e, int64_t l, int64_t r) {
  if (s > e || e < l || s > r) return 0;
  if (l <= s && e <= r) return seg[n];
  int64_t m = (s + e) >> 1;
  return max(get(n << 1, s, m, l, r), get(n << 1 | 1, m + 1, e, l, r));
}
void solve() {
  int64_t n, t, x, q, p;
  cin >> n;
  for (int64_t i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
  for (int64_t i = 1; i <= q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> p >> x;
      b[p] = i;
      a[p] = x;
    } else {
      cin >> x;
      upd(1, 1, n, i, x);
    }
  }
  for (int64_t i = 1; i <= n; i++)
    cout << max(a[i], get(1, 1, n, b[i] + 1, n)) << " ";
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
