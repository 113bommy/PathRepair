#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& prnt(ostream& out, T v) {
  out << v.size() << '\n';
  for (auto e : v) out << e << ' ';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, vector<T> v) {
  return prnt(out, v);
}
template <class T>
ostream& operator<<(ostream& out, set<T> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, map<T1, T2> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ' ' << p.second << ')';
}
const long long N = 200100;
const long long MARGIN = 1e9;
const long long MOD = 1e9 + 7;
long long n, k, m, a[N], w[N], x, y;
struct first {
  long long val[4 * N];
  first() { memset(val, 0, sizeof val); };
  void upd(long long nod, long long l, long long r, long long pos,
           long long value) {
    if (l == r) {
      val[nod] = value % MOD;
      return;
    }
    long long mid = (l + r) / 2, ans = 0;
    if (pos <= mid)
      upd(2 * nod, l, mid, pos, value);
    else
      upd(2 * nod + 1, mid + 1, r, pos, value);
    val[nod] = val[2 * nod] + val[2 * nod + 1];
    if (val[nod] >= MOD) val[nod] -= MOD;
  }
  long long que(long long nod, long long l, long long r, long long x,
                long long y) {
    if (x <= l && r <= y) return val[nod];
    long long mid = (l + r) / 2, ans = 0;
    if (x <= mid) ans += que(2 * nod, l, mid, x, y), ans %= MOD;
    if (y > mid) ans += que(2 * nod + 1, mid + 1, r, x, y), ans %= MOD;
    return ans;
  }
  void update(long long pos, long long val) { upd(1, 1, n, pos, val); }
  long long query(long long x, long long y) {
    if (x > y) return 0;
    return que(1, 1, n, x, y);
  }
} stl, str;
long long aib[N];
long long lsb(long long x) { return x & (-x); }
long long que(long long pos) {
  long long ret = 0;
  for (; pos; pos -= lsb(pos)) ret += aib[pos];
  return ret;
}
long long query(long long l, long long r) { return que(r) - que(l - 1); }
void update(long long pos, long long val) {
  long long prev = query(pos, pos);
  val = val - prev;
  for (; pos < N; pos += lsb(pos)) aib[pos] += val;
}
long long vv(long long mid, long long l, long long r) {
  return query(l, mid - 1) - query(mid, r);
}
long long cb(long long l, long long r, long long x, long long y) {
  if (l == r) return l;
  long long mid = (l + r + 1) / 2;
  if (vv(mid, x, y) <= 0) return cb(mid, r, x, y);
  return cb(l, mid - 1, x, y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    cin >> w[i];
    stl.update(i, (w[i] * (a[i] - i)) % MOD);
    str.update(i, (w[i] * ((long long)MARGIN - n + i - a[i])) % MOD);
    update(i, w[i]);
  }
  for (long long i = 1; i <= m; i++) {
    cin >> x >> y;
    if (x < 0) {
      x = -x;
      stl.update(x, (y * (a[x] - x)) % MOD);
      str.update(x, (y * ((long long)MARGIN - n + x - a[x])) % MOD);
      update(x, y);
    } else {
      long long l = x, r = y;
      long long fix = cb(l, r, l, r);
      long long ans = 0;
      ans +=
          (str.query(l, fix) -
           (((query(l, fix) % MOD) * ((long long)MARGIN - n + fix - a[fix])) %
            MOD)) %
          MOD;
      ans += (stl.query(fix + 1, r) -
              (((query(fix + 1, r) % MOD) * (a[fix] + 1 - fix - 1)) % MOD)) %
             MOD;
      cout << (ans % MOD + MOD) % MOD << '\n';
    }
  }
}
