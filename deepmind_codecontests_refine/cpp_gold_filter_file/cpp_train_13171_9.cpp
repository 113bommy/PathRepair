#include <bits/stdc++.h>
template <typename T>
class IntegerIterator
    : public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
 public:
  explicit IntegerIterator(int value) : value(value) {}
  IntegerIterator& operator++() {
    ++value;
    return *this;
  }
  IntegerIterator operator++(int) {
    IntegerIterator copy = *this;
    ++value;
    return copy;
  }
  IntegerIterator& operator--() {
    --value;
    return *this;
  }
  IntegerIterator operator--(int) {
    IntegerIterator copy = *this;
    --value;
    return copy;
  }
  T operator*() const { return value; }
  bool operator==(IntegerIterator rhs) { return value == rhs.value; }
  bool operator!=(IntegerIterator rhs) { return !(*this == rhs); }

 private:
  T value;
};
template <typename T>
class IntegerRange {
 public:
  IntegerRange(T begin, T end) : begin_(begin), end_(end) { ; }
  IntegerIterator<T> begin() const { return IntegerIterator<T>(begin_); }
  IntegerIterator<T> end() const { return IntegerIterator<T>(end_); }

 private:
  T begin_;
  T end_;
};
template <typename T>
class ReversedIntegerRange {
 public:
  ReversedIntegerRange(T begin, T end) : begin_(begin), end_(end) { ; }
  std::reverse_iterator<IntegerIterator<T>> begin() const {
    return std::reverse_iterator<IntegerIterator<T>>(
        IntegerIterator<T>(begin_));
  }
  std::reverse_iterator<IntegerIterator<T>> end() const {
    return std::reverse_iterator<IntegerIterator<T>>(IntegerIterator<T>(end_));
  }

 private:
  T begin_;
  T end_;
};
template <typename T>
IntegerRange<T> range(T to) {
  return IntegerRange<T>(0, to);
}
template <typename T>
IntegerRange<T> range(T from, T to) {
  return IntegerRange<T>(from, to);
}
template <typename T>
IntegerRange<T> inclusiveRange(T to) {
  return IntegerRange<T>(0, to + 1);
}
template <typename T>
IntegerRange<T> inclusiveRange(T from, T to) {
  return IntegerRange<T>(from, to + 1);
}
template <typename T>
ReversedIntegerRange<T> downrange(T from) {
  return ReversedIntegerRange<T>(from, 0);
}
template <typename T>
ReversedIntegerRange<T> downrange(T from, T to) {
  return ReversedIntegerRange<T>(from, to);
}
template <typename T>
ReversedIntegerRange<T> inclusiveDownrange(T from) {
  return ReversedIntegerRange<T>(from + 1, 0);
}
template <typename T>
ReversedIntegerRange<T> inclusiveDownrange(T from, T to) {
  return ReversedIntegerRange<T>(from + 1, to);
}
using namespace std;
class TaskE {
 public:
  vector<int> a;
  struct Res {
    int res1, max_res;
    bool full;
  };
  vector<vector<int>> g;
  Res dfs(int v, int p, int value) {
    if (a[v] < value) {
      Res res = {0, 0, false};
      for (int to : g[v]) {
        if (to != p) {
          res.max_res = max(res.max_res, dfs(to, v, value).max_res);
        }
      }
      return res;
    }
    Res res = {0, 0, true};
    int free = 1;
    int best1 = 0, best2 = 0;
    for (int to : g[v]) {
      if (to != p) {
        auto ch = dfs(to, v, value);
        if (ch.full) {
          free += ch.res1;
        } else {
          res.full = false;
          if (ch.res1 > best2) {
            best2 = ch.res1;
          }
          if (best2 > best1) {
            swap(best1, best2);
          }
        }
        res.max_res = max(res.max_res, ch.max_res);
      }
    }
    if (res.full) {
      return {free, free, true};
    }
    res.res1 = free + best1;
    res.max_res = max(res.max_res, free + best1 + best2);
    return res;
  }
  void solve(std::istream& in, std::ostream& out) {
    int n, k;
    in >> n >> k;
    a.resize(n);
    g.resize(n);
    for (int i : range(n)) {
      in >> a[i];
    }
    for (int i : range(n - 1)) {
      int x, y;
      in >> x >> y;
      --x, --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    int l = *min_element(a.begin(), a.end());
    int r = *max_element(a.begin(), a.end()) + 1;
    int start = 0;
    for (int i : range(n)) {
      if (l == a[i]) {
        start = i;
      }
    }
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (dfs(start, -1, m).max_res >= k) {
        l = m;
      } else {
        r = m;
      }
    }
    out << l;
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  TaskE solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  in.tie(0);
  out << std::fixed;
  out.precision(20);
  solver.solve(in, out);
  return 0;
}
