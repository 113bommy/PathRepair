#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const vector<int> mods = {998244353, 1000000007, 1000000009};
const long long inf = 3e18;
const double pi = acos(-1.0);
const double eps = 0.0000001;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class... K>
using umap = unordered_map<K...>;
template <class... K>
using uset = unordered_set<K...>;
struct Tree {
  static constexpr int unit = 0;
  int f(int a, int b) { return a + b; }
  vector<int> s;
  int n;
  Tree(int n = 0, int def = unit) : s(2 * n, def), n(n) {}
  void update(int pos, int val) {
    for (s[pos += n] += val; pos /= 2;) s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  int query(int b, int e) {
    int ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};
long long n, q, x, y, bk;
vector<vector<long long> > qs;
vector<long long> a, res;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(13);
  cin >> n >> q;
  res.assign(q, 0);
  a.assign(n, 0);
  for (long long i = (0); i < (n); ++i) {
    cin >> a[i];
    a[i] = (i + 1) - a[i];
    if (a[i] < 0) continue;
  }
  for (long long _q = (0); _q < (q); ++_q) {
    cin >> x >> y;
    qs.push_back({n - y, x, _q});
  }
  sort(begin(qs), end(qs));
  Tree seg(n, 0);
  bk = 0;
  for (long long i = (0); i < (q); ++i) {
    x = qs[i][1], y = qs[i][0];
    for (; bk < y; bk++) {
      if (a[bk] < 0) continue;
      long long l = 0, r = bk + 1;
      while (l + 1 < r) {
        long long mid = (l + r) / 2;
        if (seg.query(mid, bk + 1) < a[bk]) {
          r = mid;
        } else {
          l = mid;
        }
      }
      if (seg.query(l, bk + 1) >= a[bk]) {
        seg.update(l, 1);
      }
    }
    res[qs[i][2]] = seg.query(x, y + 1);
  }
  for (long long i = (0); i < (((int)(res).size())); ++i)
    cout << res[i] << "\n";
  return 0;
}
