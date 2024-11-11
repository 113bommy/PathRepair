#include <bits/stdc++.h>
using namespace std;
const int inf_int = 1e9 + 100;
const long long inf_ll = 1e16;
const double pi = 3.1415926535898;
bool debug = 0;
const int MAXN = 3e5 + 100;
const int LOG = 20;
const long long mod = 998244353;
const int MX = 1e6 + 100;
struct obj {
  long long l;
  long long free;
  long long r;
  obj() {}
};
;
obj t[4 * MX];
obj def;
obj mer(obj a, obj b) {
  if (b.r < b.l) {
    return a;
  }
  if (a.r < a.l) {
    return b;
  }
  obj res;
  res.l = a.l;
  if (a.r < b.l) {
    res.r = b.r;
    res.free = a.free + b.free + (b.l - a.r - 1);
    return res;
  }
  long long sh = abs(a.r - b.l) + 1;
  long long add = 0;
  if (b.free < sh) add = sh - b.free;
  res.free = a.free + max(b.free - sh, 0ll);
  res.r = b.r + add;
  return res;
}
void build(long long v, long long tl, long long tr) {
  if (tl == tr) {
    obj temp;
    temp.l = tl;
    temp.free = 0;
    temp.r = tr - 1;
    t[v] = temp;
  } else {
    long long tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = mer(t[v << 1], t[v << 1 | 1]);
  }
}
void update(long long v, long long tl, long long tr, long long pos,
            long long x) {
  if (tl == tr) {
    if (x > 0) {
      obj temp;
      temp.l = tl;
      temp.free = 0;
      temp.r = tl + x - 1;
      t[v] = temp;
    } else {
      obj temp;
      temp.l = tl;
      temp.free = 0;
      temp.r = tr - 1;
      t[v] = temp;
    }
  } else {
    long long tm = (tl + tr) >> 1;
    if (pos <= tm) {
      update(v << 1, tl, tm, pos, x);
    } else {
      update(v << 1 | 1, tm + 1, tr, pos, x);
    }
    t[v] = mer(t[v << 1], t[v << 1 | 1]);
  }
}
obj get(long long v, long long tl, long long tr, long long l, long long r) {
  if (l > tr || r < tl) {
    return def;
  }
  if (l <= tl && tr <= r) return t[v];
  long long tm = (tl + tr) >> 1;
  return mer(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
}
long long st[MAXN];
long long len[MAXN];
void solve() {
  def.l = 0;
  def.r = -1;
  long long q;
  cin >> q;
  long long L = 0, R = 1e6 + 10;
  build(1, L, R);
  for (long long i = 1; i <= q; ++i) {
    char t;
    cin >> t;
    if (t == '+') {
      cin >> st[i] >> len[i];
      update(1, L, R, st[i], len[i]);
    } else if (t == '-') {
      long long v;
      cin >> v;
      update(1, L, R, st[v], -len[v]);
    } else {
      long long st;
      cin >> st;
      obj res = get(1, L, R, 0, st);
      if (debug)
        cout << "res : " << res.l << " " << res.r << " = " << res.free << endl;
      if (res.r < res.l) {
        cout << "0\n";
        continue;
      }
      if (res.r < st) {
        cout << "0\n";
        continue;
      }
      cout << res.r - st + 1 << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  long long t = 1;
  while (t--) solve();
}
