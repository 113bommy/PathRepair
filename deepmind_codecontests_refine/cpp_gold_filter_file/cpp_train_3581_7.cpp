#include <bits/stdc++.h>
using namespace std;
const long long N = 4e6 + 100, OO = 1e6 + 10, M = 1e9 + 7, lg = 22;
long long a[N], b[N], seg[N];
void build(long long c, long long b, long long e) {
  if (e - b == 1) {
    seg[c] = 1;
    return;
  }
  long long mid = (b + e) / 2;
  build(2 * c, b, mid);
  build(2 * c + 1, mid, e);
  seg[c] = seg[2 * c] + seg[2 * c + 1] - (a[mid - 1] < a[mid]);
}
long long get(long long c, long long b, long long e, long long l, long long r) {
  if (b == l && e == r) return seg[c];
  long long mid = (b + e) / 2;
  if (r <= mid) return get(2 * c, b, mid, l, r);
  if (l >= mid) return get(2 * c + 1, mid, e, l, r);
  return get(2 * c, b, mid, l, mid) + get(2 * c + 1, mid, e, mid, r) -
         (a[mid - 1] < a[mid]);
}
void upd(long long c, long long b, long long e, long long x) {
  if (e - b == 1) {
    seg[c] = 1;
    return;
  }
  long long mid = (b + e) / 2;
  if (x < mid)
    upd(2 * c, b, mid, x);
  else
    upd(2 * c + 1, mid, e, x);
  seg[c] = seg[2 * c] + seg[2 * c + 1] - (a[mid - 1] < a[mid]);
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
    a[b[i]] = i;
  }
  vector<pair<long long, long long> > v;
  build(1, 0, n);
  long long q;
  cin >> q;
  while (q--) {
    long long t, x, y;
    cin >> t >> x >> y;
    x--;
    if (t == 1) {
      cout << get(1, 0, n, x, y) << endl;
      continue;
    } else {
      v.push_back({x + 1, y});
    }
    y--;
    swap(b[x], b[y]);
    a[b[x]] = x;
    a[b[y]] = y;
    upd(1, 0, n, b[x]);
    upd(1, 0, n, b[y]);
  }
  return 0;
}
