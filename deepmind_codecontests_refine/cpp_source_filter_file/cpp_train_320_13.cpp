#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long MAX = 200007;
long long sum(long long a, long long b) {
  return a + b >= MOD ? a + b - MOD : a + b;
}
long long sub(long long a, long long b) {
  return a - b < 0 ? a - b + MOD : a - b;
}
long long mul(long long a, long long b) { return (a * b) % MOD; }
long long ps[MAX];
long long ar[MAX];
long long tr[4 * MAX];
long long tr2[4 * MAX];
long long tr3[4 * MAX];
void init(long long u, long long l, long long r) {
  if (l == r) {
    tr[u] = ar[l];
    tr2[u] = mul(ar[l], ps[l]);
    tr3[u] = mul(ar[l], l);
    return;
  }
  long long mid = (l + r) / 2;
  init(u * 2, l, mid);
  init(u * 2 + 1, mid + 1, r);
  tr[u] = tr[u * 2] + tr[u * 2 + 1];
  tr2[u] = sum(tr2[u * 2], tr2[u * 2 + 1]);
  tr3[u] = sum(tr3[u * 2], tr3[u * 2 + 1]);
}
void update(long long u, long long l, long long r, long long idx, long long v) {
  if (l == r) {
    ar[l] = v;
    tr[u] = ar[l];
    tr2[u] = mul(ar[l], ps[l]);
    tr3[u] = mul(ar[l], l);
    return;
  }
  long long mid = (l + r) / 2;
  if (idx <= mid)
    update(u * 2, l, mid, idx, v);
  else
    update(u * 2 + 1, mid + 1, r, idx, v);
  tr[u] = tr[u * 2] + tr[u * 2 + 1];
  tr2[u] = sum(tr2[u * 2], tr2[u * 2 + 1]);
  tr3[u] = sum(tr3[u * 2], tr3[u * 2 + 1]);
}
pair<long long, long long> binSearch(long long u, long long l, long long r,
                                     long long x, long long y, long long sm,
                                     long long lft = 0) {
  if (r < x || y < l) return pair<long long, long long>(0, 0);
  if (x <= l && r <= y) {
    if (lft + tr[u] <= sm / 2 || l == r)
      return pair<long long, long long>(r, lft + tr[u]);
  }
  long long mid = (l + r) / 2;
  pair<long long, long long> _l = binSearch(u * 2, l, mid, x, y, sm, lft);
  if (_l.second <= sm / 2)
    return binSearch(u * 2 + 1, mid + 1, r, x, y, sm, lft + _l.second);
  else
    return _l;
}
long long query(long long u, long long l, long long r, long long x,
                long long y) {
  if (x > y) return 0;
  if (r < x || y < l) return 0;
  if (x <= l && r <= y) return tr[u];
  long long mid = (l + r) / 2;
  return query(u * 2, l, mid, x, y) + query(u * 2 + 1, mid + 1, r, x, y);
}
long long query2(long long u, long long l, long long r, long long x,
                 long long y) {
  if (x > y) return 0;
  if (r < x || y < l) return 0;
  if (x <= l && r <= y) return tr2[u];
  long long mid = (l + r) / 2;
  return sum(query2(u * 2, l, mid, x, y), query2(u * 2 + 1, mid + 1, r, x, y));
}
long long query3(long long u, long long l, long long r, long long x,
                 long long y) {
  if (x > y) return 0;
  if (r < x || y < l) return 0;
  if (x <= l && r <= y) return tr3[u];
  long long mid = (l + r) / 2;
  return sum(query3(u * 2, l, mid, x, y), query3(u * 2 + 1, mid + 1, r, x, y));
}
long long n;
long long wut(long long l, long long r, long long x) {
  long long ans = 0;
  long long leftsum = query(1, 1, n, l, x) % MOD;
  long long rightsum = query(1, 1, n, x, r) % MOD;
  long long leftsum2 = query2(1, 1, n, l, x);
  long long rightsum2 = query2(1, 1, n, x, r);
  long long leftsum3 = query3(1, 1, n, l, x);
  long long rightsum3 = query3(1, 1, n, x, r);
  ans = sum(ans, sub(mul(ps[x], leftsum), leftsum2));
  ans = sub(ans, sub(mul(x, leftsum), leftsum3));
  ans = sum(ans, sub(rightsum2, mul(ps[x], rightsum)));
  ans = sub(ans, sub(rightsum3, mul(x, rightsum)));
  return ans;
}
long long solve(long long l, long long r) {
  if (l == r) return 0;
  long long sm = query(1, 1, n, l, r);
  long long y = binSearch(1, 1, n, l, r, sm).first;
  long long x = y - 1;
  long long leftsum = query(1, 1, n, l, x);
  long long rightsum = query(1, 1, n, y, r);
  if (leftsum <= rightsum) return wut(l, r, y);
  return wut(l, r, x);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long q;
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) cin >> ps[i];
  for (long long i = 1; i <= n; i++) cin >> ar[i];
  init(1, 1, n);
  while (q--) {
    long long a, b;
    cin >> a >> b;
    if (a < 0)
      update(1, 1, n, -a, b);
    else
      cout << solve(a, b) << '\n';
  }
  return 0;
}
