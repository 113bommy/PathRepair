#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
long long a[100005];
struct rsq {
  vector<long long> t;
  long long sz;
  void init(long long n) {
    t.resize(4 * n);
    sz = n;
  }
  void modify(long long v, long long l, long long r, long long pos,
              long long val) {
    if (l == r) {
      t[v] = val;
      return;
    }
    long long m = (l + r) >> 1LL;
    if (pos <= m)
      modify(v + v, l, m, pos, val);
    else
      modify(v + v + 1, m + 1, r, pos, val);
    t[v] = t[v + v] + t[v + v + 1];
  }
  void set(long long v, long long val) { modify(1, 0, sz - 1, v, val); }
  long long get(long long v, long long tl, long long tr, long long l,
                long long r) {
    if (l <= tl && r >= tr) {
      return t[v];
    }
    long long tm = (tl + tr) >> 1LL;
    long long res = 0;
    if (l <= tm) res += get(v + v, tl, tm, l, r);
    if (r > tm) res += get(v + v + 1, tm + 1, tr, l, r);
    return res;
  }
  long long get(long long l, long long r) { return get(1, 0, sz - 1, l, r); }
} t;
int main(void) {
  long long n;
  cin >> n;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) cin >> a[i];
  t.init(1000005);
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    long long x = a[i];
    long long res = t.get(1, x) % mod;
    t.set(x, (res * x + x) % mod);
  }
  long long ans = 0;
  for (long long(i) = 0; (i) < (long long)(1000005); (i)++) ans += t.get(i, i);
  cout << ans << endl;
  return 0;
}
