#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int N = (int)2e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const long long linf = (long long)1e18 + 7;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
using namespace std;
struct line {
  long long k, b;
  int id;
  line() {}
  line(long long k, long long b, int id) : k(k), b(b), id(id) {}
  long long get(long long x) { return k * x + b; }
  bool operator<(const line &R) const {
    if (k != R.k) return k > R.k;
    return b < R.b;
  }
};
int n;
class CHT {
 private:
  vector<line> v;

 public:
  long double inter(line a, line b) {
    return (b.b - a.b) / (double)(a.k - b.k);
  }
  void add(line x) {
    while ((int)v.size() > 1 && inter(v[(int)v.size() - 2], x) >=
                                    inter(v[(int)v.size() - 2], v.back()))
      v.pop_back();
    v.push_back(x);
  }
  void push(line x) { v.push_back(x); }
  void build() {
    vector<line> b;
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); i++) {
      if ((int)b.size() && b.back().k == v[i].k) continue;
      b.push_back(v[i]);
    }
    v.clear();
    for (auto it : b) {
      add(it);
    }
  }
  line get(long long x) {
    int l = 0, r = (int)v.size() - 2, res = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      if (v[mid].get(x) <= v[mid + 1].get(x))
        res = mid + 1, l = mid + 1;
      else
        r = mid - 1;
    }
    return v[res];
  }
};
struct SegTree {
  CHT t[N << 2];
  void upd(int p, line x, int v = 1, int tl = 1, int tr = n) {
    t[v].push(x);
    if (tl == tr) return;
    int tm = tl + tr >> 1;
    if (p <= tm)
      upd(p, x, v << 1, tl, tm);
    else
      upd(p, x, v << 1 | 1, tm + 1, tr);
  }
  void build(int v = 1, int tl = 1, int tr = n) {
    if (tl == tr) return;
    int tm = tl + tr >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v].build();
  }
  line maxi(line a, line b, int x) {
    if (a.get(x) >= b.get(x)) return a;
    return b;
  }
  line get(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
    if (l <= tl && tr <= r) return t[v].get(x);
    int tm = tl + tr >> 1;
    if (r <= tm) return get(l, r, x, v << 1, tl, tm);
    if (tm < l) return get(l, r, x, v << 1 | 1, tm + 1, tr);
    return maxi(get(l, r, x, v << 1, tl, tm),
                get(l, r, x, v << 1 | 1, tm + 1, tr), x);
  }
} t;
int a[N];
long long s1[N], s2[N];
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s1[i] = (long long)a[i] * i;
    s2[i] = a[i];
  }
  for (int i = n; i >= 1; i--) {
    s1[i] += s1[i + 1];
    s2[i] += s2[i + 1];
    t.upd(i, line(s2[i + 1], -s1[i + 1], i));
  }
  t.build();
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, t.get(i, n, i - 1).get(i - 1) + s1[i] - (i - 1) * s2[i]);
  }
  cout << ans;
  exit(0);
}
