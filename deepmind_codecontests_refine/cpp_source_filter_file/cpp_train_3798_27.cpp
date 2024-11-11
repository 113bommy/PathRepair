#include <bits/stdc++.h>
using std::vector;
template <class Node>
class Segtree {
  int _size, _lvl, _next_two_pow;
  int* kovk;
  int apa(int i);
  void updateline(int n) {
    while (update(n) && n) {
      n = (n - 1) / 2;
    }
  }
  bool update(int n) { return vct[n].update(vct[2 * n + 1], vct[2 * n + 2]); }
  vector<Node> vct;
  vector<int> _left, _right;

 public:
  Segtree(int size = 0) : _size(size) {
    kovk = new int[_size / 2];
    vct.resize(size);
    _lvl = log2(size);
    _next_two_pow = pow(2, _lvl + 1);
  }
  Segtree(vector<Node> v) : _size(v.size() * 2 - 1) {
    kovk = new int[_size / 2];
    _left.resize(_size);
    vct.resize(_size);
    _right.resize(_size);
    _lvl = log2(_size);
    _next_two_pow = pow(2, _lvl + 1);
    build(v);
  }
  void update_bottom(int n, Node a) {
    vct[apa(n)] = a;
    updateline((apa(n) - 1) / 2);
  }
  bool quarry(int l, int r, int b, int e) const;
  void build(vector<Node> from);
  Node top() { return vct[0]; }
  void block_update(int from, int to, vector<Node> val);
};
template <class Node>
void Segtree<Node>::block_update(int left, int right, vector<Node> val) {
  int l = apa(left), j = -1;
  int r = apa(right);
  int kdb;
  kdb = -1;
  if (l > r) {
    for (int i = l; i != _size; ++i) {
      vct[i] = val[++j];
    }
    for (int i = _size / 2; i != r; ++i) {
      vct[i] = val[++j];
      if (kovk[kdb] != (i - 1) / 2) kovk[++kdb] = (i - 1) / 2;
    }
    for (int i = (l - 1) / 2; i < (_size - 2) / 2; ++i) {
      if (update(i)) {
        if (kovk[kdb] != (i - 1) / 2) kovk[++kdb] = (i - 1) / 2;
      }
    }
  } else {
    for (int i = l; i != r; ++i) {
      vct[i] = val[++j];
      if (kovk[kdb] != (i - 1) / 2) kovk[++kdb] = (i - 1) / 2;
    }
  }
  int i = 0;
  while (kdb >= i) {
    if (update(kovk[i]) && kovk[kdb] != (kovk[i] - 1) / 2) {
      kovk[++kdb] = (kovk[i] - 1) / 2;
    }
    ++i;
  }
}
template <class Node>
void Segtree<Node>::build(vector<Node> from) {
  for (int i = 0; i != from.size(); ++i) {
    const int p = apa(i);
    _left[p] = _right[p] = i;
    vct[p] = from[i];
  }
  if (_size % 2 == 0) {
    vct[_size - from.size()] = vct[_size - 1];
  }
  for (int i = _size - from.size() - 1; i != -1; i--) {
    _left[i] = _left[1 + i * 2];
    _right[i] = _right[2 + i * 2];
    update(i);
  }
};
template <class Node>
int Segtree<Node>::apa(int i) {
  const int ff = (_size - 1) / 2;
  if (0 == _size % 2 && i / 2 - 1 + _next_two_pow / 2 - ff >= (_size + 2) / 2) {
    return ff + (i + _next_two_pow / 2 - ff) % ((_size + 2) / 2);
  } else {
    return ff + (i - 1 + _next_two_pow / 2 - ff) % ((_size + 2) / 2);
  }
}
template <class Node>
bool Segtree<Node>::quarry(int l, int r, int b, int e) const {
  int i = 0;
  bool delt = 1;
  while (delt) {
    delt = false;
    while (2 * i + 1 < _size && r <= _right[2 * i + 1]) {
      i = i * 2 + 1;
      delt = true;
    }
    while (2 * i + 2 < _size && l >= _left[2 * i + 2]) {
      i = i * 2 + 2;
      delt = true;
    }
  }
  if (_left[i] == l && _right[i] == r) {
    return (vct[i].findend(b)) >= e;
  }
  int j = 2 * i + 1;
  bool possible = 1;
  while (l != _left[j]) {
    if (_left[2 * j + 2] <= l) {
      j = 2 * j + 2;
    } else {
      j = 2 * j + 1;
      possible = possible && (vct[j + 1].findend(b) >= e);
    }
  }
  possible = possible && (vct[j].findend(b) >= e);
  i = 2 * i + 2;
  while (r != _right[i]) {
    if (_right[2 * i + 1] >= r) {
      i = 2 * i + 1;
    } else {
      i = 2 * i + 2;
      possible = possible && (vct[i - 1].findend(b) >= e);
    }
  }
  possible = possible && (vct[i].findend(b) >= e);
  return possible;
}
struct Interval {
  Interval(int b = 0, int e = 0) {
    begin = b;
    end = e;
  }
  int begin, end;
  bool operator<(const Interval& a) const { return begin < a.begin; };
};
int inf = 1000000000;
class Intervallist {
 public:
  std::vector<Interval> intervals;
  Intervallist merge(const Intervallist& a) const;
  int findend(int x) const;
  bool update(const Intervallist& a, const Intervallist& b) {
    *this = a.merge(b);
    return 1;
  }
};
Intervallist Intervallist::merge(const Intervallist& a) const {
  int i = 0, j = 0, N = 0;
  Intervallist ret;
  while (i < intervals.size() && j < a.intervals.size()) {
    int b = std::min(intervals[i].begin, a.intervals[j].begin);
    int e = std::max(intervals[i].end, a.intervals[j].end);
    ret.intervals.push_back(Interval(b, e));
    if (b == intervals[i].begin) {
      if (b == a.intervals[j].begin) ++j;
      ++i;
    } else {
      ++j;
    }
    ++N;
    if (N > 1 && ret.intervals[N - 2].end >= ret.intervals[N - 1].end) {
      ret.intervals[N - 2] = ret.intervals[N - 1];
      --N;
      ret.intervals.pop_back();
    }
  }
  return ret;
}
int Intervallist::findend(int x) const {
  int beg, end, mid;
  beg = -1;
  end = intervals.size() - 1;
  if (end == -1) return inf;
  while (beg + 1 < end) {
    mid = (beg + end) / 2;
    if (x > intervals[mid].begin) {
      beg = mid;
    } else {
      end = mid;
    }
  }
  if (intervals[end].begin < x) return inf;
  return intervals[end].end;
};
int main() {
  std::ios::sync_with_stdio(0);
  int n, m, k, p;
  std::cin >> n >> m >> k >> p;
  vector<Intervallist> lil;
  vector<Intervallist> ril;
  lil.resize(n);
  ril.resize(m);
  for (int i = 0; i != k; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    lil[u].intervals.push_back(Interval(v, v));
    ril[v].intervals.push_back(Interval(u, u));
  }
  for (auto& a : lil) std::sort(a.intervals.begin(), a.intervals.end());
  for (auto& a : ril) std::sort(a.intervals.begin(), a.intervals.end());
  Segtree<Intervallist> lines(ril);
  Segtree<Intervallist> rows(lil);
  for (int i = 0; i != p; ++i) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (a > c) std::swap(a, c);
    if (b > d) std::swap(d, b);
    --a;
    --b;
    --c;
    --d;
    int r = rows.quarry(a, c, b, d);
    int l = lines.quarry(b, d, a, c);
    if (r || l) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}
