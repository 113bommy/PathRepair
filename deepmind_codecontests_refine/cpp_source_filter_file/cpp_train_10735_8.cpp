#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O2")
using namespace std;
const long long N = 10000 + 10;
const long long MOD = 1000000000 + 7;
const long long INF = 1000000010;
const long long LOG = 25;
long long seg[N << 2], lazy[N << 2], q, t[N], d[N], Time = 1, tt[N];
void modify(long long id, long long x) {
  seg[id] += x;
  lazy[id] += x;
}
void shift(long long id) {
  modify(id << 1, lazy[id]);
  modify(id << 1 | 1, lazy[id]);
  lazy[id] = 0;
}
void add(long long id, long long lq, long long rq, long long x, long long l,
         long long r) {
  if (rq <= l || r <= lq) return;
  if (lq <= l && r <= rq) {
    modify(id, x);
    return;
  }
  long long md = (l + r) >> 1;
  shift(id);
  add(id << 1, lq, rq, x, l, md);
  add(id << 1 | 1, lq, rq, x, md, r);
  seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
long long get(long long id, long long lq, long long rq, long long l,
              long long r) {
  if (rq <= l || r <= lq) return 0;
  if (lq <= l && r <= rq) {
    return seg[id];
  }
  long long md = (l + r) >> 1;
  shift(id);
  return max(get(id << 1, lq, rq, l, md), get(id << 1 | 1, lq, rq, md, r));
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  for (long long i = 1; i < N; i++) add(1, i, i + 1, i, 1, N + 1);
  for (long long i = 1; i <= q; i++) {
    char c;
    cin >> c;
    if (c == '+') {
      cin >> t[i] >> d[i];
      add(1, 1, t[i] + 1, d[i], 1, N + 1);
    } else if (c == '-') {
      long long x;
      cin >> x;
      add(1, 1, t[x] + 1, -d[x], 1, N + 1);
    } else {
      long long T;
      cin >> T;
      long long res = get(1, 1, T + 1, 1, N + 1);
      res -= get(1, T + 1, T + 2, 1, N + 1) - (T + 1);
      cout << res - T << '\n';
    }
  }
  return 0;
}
