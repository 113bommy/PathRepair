#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const long long maxn = (long long)3e6 + 5;
const long long mod = 998244353;
const long long inf = 0x3f3f3f3f;
long long T = 1;
bool rev[25];
long long n, q;
long long t[maxn];
void build(long long st, long long l, long long r) {
  if (l == r) {
    cin >> t[st];
    return;
  }
  long long mid = (l + r) >> 1;
  build(st << 1, l, mid);
  build(st << 1 | 1, mid + 1, r);
  t[st] = t[st << 1] + t[st << 1 | 1];
}
void update(long long st, long long l, long long r, long long dep, long long p,
            long long v) {
  if (l == r) {
    t[st] = v;
    return;
  }
  long long mid = (l + r) >> 1;
  if (p <= mid)
    update(st << 1 | rev[dep], l, mid, dep - 1, p, v);
  else
    update(st << 1 | rev[dep] ^ 1, mid + 1, r, dep - 1, p, v);
  t[st] = t[st << 1] + t[st << 1 | 1];
}
long long query(long long st, long long l, long long r, long long dep,
                long long ql, long long qr) {
  if (ql <= l && r <= qr) return t[st];
  long long mid = (l + r) >> 1;
  long long res = 0;
  if (ql <= mid) res += query(st << 1 | rev[dep], l, mid, dep - 1, ql, qr);
  if (qr > mid)
    res += query(st << 1 | rev[dep] ^ 1, mid + 1, r, dep - 1, ql, qr);
  return res;
}
void solve() {
  cin >> n >> q;
  build(1, 1, 1 << n);
  while (q--) {
    long long op;
    cin >> op;
    long long x, y;
    if (op == 1) {
      cin >> x >> y;
      update(1, 1, 1 << n, n, x, y);
    } else if (op == 2) {
      cin >> x;
      for (long long i = 2; i <= x; ++i) rev[i] ^= 1;
    } else if (op == 3) {
      cin >> x;
      rev[x + 1] ^= 1;
    } else {
      cin >> x >> y;
      cout << query(1, 1, 1 << n, n, x, y) << '\n';
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  while (T--) solve();
  return 0;
}
