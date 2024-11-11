#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
inline long long add(long long a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
inline long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
  return a;
}
inline long long mul(long long a, long long b) {
  return (long long)((long long)a * b % 1000000007);
}
long long v2[2 * 100000 + 1 + 1];
long long v1[2 * 100000 + 1 + 1];
long long segtree[4 * (2 * 100000 + 1 + 1)];
long long lazy[4 * (2 * 100000 + 1 + 1)];
long long v[2 * 100000 + 1 + 1];
long long create_segtree(long long si, long long l, long long r) {
  lazy[si] = 0;
  if (l == r) return segtree[si] = v[l];
  auto t1 = create_segtree(2 * si, l, (l + r) / 2);
  auto t2 = create_segtree(2 * si + 1, (l + r) / 2 + 1, r);
  return segtree[si] = min(t1, t2);
}
long long query_segtree(long long si, long long l, long long r, long long ql,
                        long long qr) {
  if (lazy[si]) {
    segtree[si] += lazy[si];
    if (l != r) {
      lazy[2 * si] += lazy[si];
      lazy[2 * si + 1] += lazy[si];
    }
    lazy[si] = 0;
  }
  if (l > qr || r < ql) return LLONG_MAX;
  if (ql <= l && qr >= r) return segtree[si];
  auto t1 = query_segtree(2 * si, l, (l + r) / 2, ql, qr);
  auto t2 = query_segtree(2 * si + 1, (l + r) / 2 + 1, r, ql, qr);
  return min(t1, t2);
}
void update_segtree(long long si, long long l, long long r, long long ql,
                    long long qr, long long s) {
  if (lazy[si]) query_segtree(si, l, r, l, r);
  if (l > qr || r < ql) return;
  if (ql <= l && qr >= r) {
    segtree[si] = segtree[si] + s;
    if (l != r) {
      lazy[2 * si] += s;
      lazy[2 * si + 1] += s;
    }
    return;
  }
  update_segtree(2 * si, l, (l + r) / 2, ql, qr, s);
  update_segtree(2 * si + 1, (l + r) / 2 + 1, r, ql, qr, s);
  auto t1 = segtree[2 * si];
  auto t2 = segtree[2 * si + 1];
  segtree[si] = min(t1, t2);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  long long T = t;
  while (t--) {
    long long n;
    cin >> n;
    map<long long, long long> rmp;
    for (long long i = 0; i < n; i += 1)
      cin >> v2[i + 1], rmp[v2[i + 1]] = i + 1;
    for (long long i = 0; i < n; i += 1) cin >> v1[i + 1];
    for (long long i = 0; i < n; i += 1) v[i + 1] = v[i] + v1[i + 1];
    create_segtree(1, 1, n);
    long long ans = min(v1[1], v1[n]);
    for (long long i = 1; i < n + 1; i += 1) {
      update_segtree(1, 1, n, 1, rmp[i] - 1, v1[rmp[i]]);
      update_segtree(1, 1, n, rmp[i], n, -v1[rmp[i]]);
      ans = min(ans, query_segtree(1, 1, n, 1, n - 1));
    }
    cout << ans;
  }
}
