#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
using u64 = uint64_t;
using u32 = uint32_t;
using i64 = int64_t;
using i32 = int32_t;
using namespace std;
template <typename T>
void print_vector(ostream &os, const vector<T> &v, const string &sep = " ",
                  const string &begin = "", const string &end = "\n") {
  os << begin;
  for (size_t i = 0, n{v.size()}; i < n; ++i) {
    if (i < n - 1) {
      os << v[i] << sep;
    } else {
      os << v[i];
    }
  }
  os << end;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  print_vector(os, v, ", ", "[", "]");
  return os;
}
template <typename _Key, typename _Compare = std::less<_Key>,
          typename _Alloc = std::allocator<_Key>>
ostream &operator<<(ostream &os, const set<_Key, _Compare, _Alloc> &s) {
  os << '{';
  if (s.size()) {
    auto pend = begin(s);
    advance(pend, s.size() - 1);
    for (auto it = begin(s); it != pend; ++it) {
      os << *it << ", ";
    }
    os << *s.rbegin();
  }
  return os << '}';
}
template <typename _Value, typename _Hash = hash<_Value>,
          typename _Pred = equal_to<_Value>,
          typename _Alloc = allocator<_Value>>
ostream &operator<<(ostream &os,
                    const unordered_set<_Value, _Hash, _Pred, _Alloc> &s) {
  os << '{';
  if (s.size()) {
    auto pend = begin(s);
    advance(pend, s.size() - 1);
    for (auto it = begin(s); it != pend; ++it) {
      os << *it;
      if (it != pend) {
        os << ", ";
      }
    }
  }
  return os << '}';
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << '(' << p.first << ',' << p.second << ')';
}
template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  os << '{';
  if (m.size()) {
    auto pend = begin(m);
    advance(pend, m.size() - 1);
    for (auto it = begin(m); it != pend; ++it) {
      os << *it << ", ";
    }
    os << m.back();
  }
  return os << '}';
}
template <typename K, typename V>
ostream &operator<<(ostream &os, const unordered_map<K, V> &m) {
  os << '{';
  if (m.size()) {
    auto pend = begin(m);
    advance(pend, m.size() - 1);
    for (auto it = begin(m); it != pend; ++it) {
      os << *it << ", ";
    }
    os << m.back();
  }
  return os << '}';
}
template <class T>
inline void hash_combine(std::size_t &seed, T const &v) {
  seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
struct HashValueImpl {
  static void apply(size_t &seed, Tuple const &tuple) {
    HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);
    hash_combine(seed, std::get<Index>(tuple));
  }
};
template <class Tuple>
struct HashValueImpl<Tuple, 0> {
  static void apply(size_t &seed, Tuple const &tuple) {
    hash_combine(seed, std::get<0>(tuple));
  }
};
template <typename... TT>
struct hash<std::tuple<TT...>> {
  size_t operator()(std::tuple<TT...> const &tt) const {
    size_t seed = 0;
    HashValueImpl<std::tuple<TT...>>::apply(seed, tt);
    return seed;
  }
};
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
void solve() {
  int m = 1, n = 1;
  cin >> m >> n;
  vector<vector<ll>> v(m, vector<ll>(n));
  for (auto &r : v) {
    for (auto &x : r) {
      cin >> x;
    }
  }
  auto test = [&](ll threshold) {
    vector<bool> possible(n, false);
    bool has_pair = false;
    for (int i = 0; i < m; ++i) {
      int satisfied_cols = 0;
      for (int j = 0; j < n; ++j) {
        possible[j] = possible[j] or v[i][j] >= threshold;
        satisfied_cols += v[i][j] >= threshold;
      }
      has_pair = has_pair or satisfied_cols >= 2;
    }
    return has_pair and all_of((possible).begin(), (possible).end(),
                               [](bool x) { return x; });
  };
  ll lo = 0, hi = ll(1e9) + 1;
  while (lo < hi) {
    ll mid = lo + (hi - lo + 1) / 2;
    if (test(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << lo << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    solve();
  }
  return 0;
}
