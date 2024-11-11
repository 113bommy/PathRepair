#include <bits/stdc++.h>
using namespace std;
template <class T>
bool setmax(T &_a, T _b) {
  if (_b > _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
bool setmin(T &_a, T _b) {
  if (_b < _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
T gcd(T _a, T _b) {
  return _b == 0 ? _a : gcd(_b, _a % _b);
}
template <class T>
class SegmentTree {
  std::vector<T> tr;
  int n;
  int v0;
  void release(int x) {
    if (tr[x] != v0) {
      tr[x * 2] = tr[x * 2 + 1] = tr[x];
      tr[x] = v0;
    }
  }
  void _paint(int x, int s, int t, int st, int en, int val) {
    if (st <= s && t <= en) {
      tr[x] = val;
      return;
    }
    release(x);
    int mid = (s + t) / 2;
    if (st <= mid) _paint(x * 2, s, mid, st, en, val);
    if (mid < en) _paint(x * 2 + 1, mid + 1, t, st, en, val);
  }
  T _get(int x, int s, int t, int ind) {
    if (s == t || tr[x] != v0) return tr[x];
    release(x);
    int mid = (s + t) / 2;
    if (ind <= mid)
      return _get(x * 2, s, mid, ind);
    else
      return _get(x * 2 + 1, mid + 1, t, ind);
  }

 public:
  SegmentTree() {}
  SegmentTree(int _n, T _v) : tr(size_t(_n + 1) * 4, _v), n(_n), v0(_v) {}
  void paint(int l, int r, T v) { _paint(1, 1, n, l, r, v); }
  T get(int x) { return _get(1, 1, n, x); }
};
template <class T>
class FenwickTree {
  std::vector<T> a;
  int n;
  T v0;

 public:
  FenwickTree() {}
  FenwickTree(int _n, T _v) : a(size_t(_n + 1), _v), n(_n), v0(_v) {}
  void add(int x, T v) {
    for (; x <= n; x += (x & -x)) a[(size_t)x] += v;
  }
  T get(int x) const {
    T r = v0;
    for (; x >= 1; x -= (x & -x)) r += a[(size_t)x];
    return r;
  }
};
const int MAXN = 500050;
char op[MAXN];
int ox[MAXN], oy[MAXN];
int n, m;
int ind[MAXN], pos[MAXN], l[MAXN], r[MAXN];
int last_clear[MAXN];
vector<int> to_clear[MAXN];
long long ans[MAXN];
void pre(int c1, int c2) {
  vector<bool> here(n + 1, true);
  vector<vector<int> > sons(n + 1);
  for (int k = int(1); k <= int(m); ++k)
    if (op[k] == c1) {
      sons[ox[k]].push_back(oy[k]);
      here[oy[k]] = false;
    }
  int cnt = 0;
  function<void(int)> dfs = [&cnt, &dfs, &sons](int x) -> void {
    ++cnt;
    ind[cnt] = x, pos[x] = cnt;
    for (int y : sons[x]) dfs(y);
  };
  for (int i = int(1); i <= int(n); ++i)
    if (here[i]) dfs(i);
  static pair<int, int> p[MAXN];
  for (int i = int(1); i <= int(n); ++i) p[i] = make_pair(pos[i], pos[i]);
  for (int k = int(1); k <= int(m); ++k) {
    auto merge = [](pair<int, int> a, pair<int, int> b) {
      return make_pair(min(a.first, b.first), max(a.second, b.second));
    };
    if (op[k] == c1) {
      p[ox[k]] = merge(p[ox[k]], p[oy[k]]);
    }
    if (op[k] == c2) {
      l[k] = p[ox[k]].first;
      r[k] = p[ox[k]].second;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = int(1); i <= int(m); ++i) {
    scanf("%s", op + i);
    scanf("%d", &ox[i]);
    if (op[i] == 'U' || op[i] == 'M') scanf("%d", &oy[i]);
  }
  pre('M', 'Z');
  memset(last_clear, 0, sizeof(last_clear));
  SegmentTree<int> tmax(n, 0);
  for (int k = int(1); k <= int(m); ++k) {
    if (op[k] == 'Z') {
      tmax.paint(l[k], r[k], k);
    }
    if (op[k] == 'Q') last_clear[k] = tmax.get(pos[ox[k]]);
  }
  for (int k = int(0); k <= int(m); ++k) to_clear[k].clear();
  for (int k = int(1); k <= int(m); ++k) to_clear[last_clear[k]].push_back(k);
  pre('U', 'A');
  FenwickTree<long long> tsum(n, 0);
  for (int k = int(1); k <= int(m); ++k) {
    if (op[k] == 'A') {
      int v = r[k] - l[k] + 1;
      tsum.add(l[k], v);
      tsum.add(r[k] + 1, -v);
    }
    if (op[k] == 'Q') {
      ans[k] += tsum.get(pos[ox[k]]);
    }
    for (int k2 : to_clear[k]) ans[k2] -= tsum.get(pos[ox[k2]]);
  }
  for (int k = int(1); k <= int(m); ++k)
    if (op[k] == 'Q') printf("%lld\n", ans[k]);
  return 0;
}
