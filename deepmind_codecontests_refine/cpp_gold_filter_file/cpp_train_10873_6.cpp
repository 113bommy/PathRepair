#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
const long long INF = 1e18;
const long long MOD = 998244353;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
long long n, m, ptr, lazy[MAXN * 4];
long long seg[MAXN * 4], val[MAXN * 4], sum[MAXN * 4];
void build(long long id, long long s, long long e) {
  if (e - s == 1) {
    val[id] = s;
    return;
  }
  long long mid = (s + e) / 2;
  build(id * 2, s, mid);
  build(id * 2 + 1, mid, e);
}
void shift(long long id, long long s, long long e) {
  if (!lazy[id]) return;
  val[id] = lazy[id];
  seg[id] += sum[id] * (e - s);
  if (e - s > 1) {
    lazy[id * 2] = lazy[id];
    lazy[id * 2 + 1] = lazy[id];
    sum[id * 2] += sum[id];
    sum[id * 2 + 1] += sum[id];
  }
  sum[id] = lazy[id] = 0;
}
void update(long long id, long long s, long long e, long long l, long long r,
            long long x) {
  shift(id, s, e);
  if (r <= s || e <= l) {
    return;
  }
  if (l <= s && e <= r && val[id]) {
    lazy[id] = x;
    sum[id] += abs(x - val[id]);
    shift(id, s, e);
    return;
  }
  long long mid = (s + e) / 2;
  update(id * 2, s, mid, l, r, x);
  update(id * 2 + 1, mid, e, l, r, x);
  seg[id] = seg[id * 2] + seg[id * 2 + 1];
  if (val[id * 2] == val[id * 2 + 1]) {
    val[id] = val[id * 2];
  } else {
    val[id] = 0;
  }
}
long long get(long long id, long long s, long long e, long long l,
              long long r) {
  shift(id, s, e);
  if (r <= s || e <= l) {
    return 0;
  }
  if (l <= s && e <= r) {
    return seg[id];
  }
  long long mid = (s + e) / 2;
  return get(id * 2, s, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  build(1, 1, n + 1);
  while (m--) {
    long long t, l, r, x;
    cin >> t >> l >> r;
    if (t == 1) {
      cin >> x;
      update(1, 1, n + 1, l, r + 1, x);
    } else {
      cout << get(1, 1, n + 1, l, r + 1) << '\n';
    }
  }
}
