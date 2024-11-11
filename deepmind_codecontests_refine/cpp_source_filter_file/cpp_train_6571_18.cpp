#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
std::istream& operator>>(std::istream& i, pair<T, U>& p) {
  i >> p.first >> p.second;
  return i;
}
template <typename T>
std::istream& operator>>(std::istream& i, vector<T>& t) {
  for (auto& v : t) {
    i >> v;
  }
  return i;
}
template <typename T, typename U>
std::ostream& operator<<(std::ostream& o, const pair<T, U>& p) {
  o << p.first << ' ' << p.second;
  return o;
}
template <typename T>
std::ostream& operator<<(std::ostream& o, const vector<T>& t) {
  if (t.empty()) o << '\n';
  for (size_t i = 0; i < t.size(); ++i) {
    o << t[i] << " \n"[i == t.size() - 1];
  }
  return o;
}
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T>
bool in(T a, T b, T c) {
  return a <= b && b < c;
}
unsigned int logceil(long long first) {
  return first ? 8 * sizeof(long long) - __builtin_clzll(first) : 0;
}
namespace std {
template <typename T, typename U>
struct hash<pair<T, U>> {
  hash<T> t;
  hash<U> u;
  size_t operator()(const pair<T, U>& p) const {
    return t(p.first) ^ (u(p.second) << 7);
  }
};
}  // namespace std
template <typename T, typename F>
T bsh(T l, T h, const F& f) {
  T r = -1, m;
  while (l <= h) {
    m = (l + h) / 2;
    if (f(m)) {
      l = m + 1;
      r = m;
    } else {
      h = m - 1;
    }
  }
  return r;
}
template <typename F>
double bshd(double l, double h, const F& f, double p = 1e-9) {
  unsigned int r = 3 + (unsigned int)log2((h - l) / p);
  while (r--) {
    double m = (l + h) / 2;
    if (f(m)) {
      l = m;
    } else {
      h = m;
    }
  }
  return (l + h) / 2;
}
template <typename T, typename F>
T bsl(T l, T h, const F& f) {
  T r = -1, m;
  while (l <= h) {
    m = (l + h) / 2;
    if (f(m)) {
      h = m - 1;
      r = m;
    } else {
      l = m + 1;
    }
  }
  return r;
}
template <typename F>
double bsld(double l, double h, const F& f, double p = 1e-9) {
  unsigned int r = 3 + (unsigned int)log2((h - l) / p);
  while (r--) {
    double m = (l + h) / 2;
    if (f(m)) {
      h = m;
    } else {
      l = m;
    }
  }
  return (l + h) / 2;
}
template <typename T>
T gcd(T a, T b) {
  if (a < b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}
template <typename T>
class vector2 : public vector<vector<T>> {
 public:
  vector2() {}
  vector2(size_t a, size_t b, T t = T())
      : vector<vector<T>>(a, vector<T>(b, t)) {}
};
template <typename T>
class vector3 : public vector<vector2<T>> {
 public:
  vector3() {}
  vector3(size_t a, size_t b, size_t c, T t = T())
      : vector<vector2<T>>(a, vector2<T>(b, c, t)) {}
};
template <typename T>
class vector4 : public vector<vector3<T>> {
 public:
  vector4() {}
  vector4(size_t a, size_t b, size_t c, size_t d, T t = T())
      : vector<vector3<T>>(a, vector3<T>(b, c, d, t)) {}
};
template <typename T>
class vector5 : public vector<vector4<T>> {
 public:
  vector5() {}
  vector5(size_t a, size_t b, size_t c, size_t d, size_t e, T t = T())
      : vector<vector4<T>>(a, vector4<T>(b, c, d, e, t)) {}
};
class AConnectThree {
 public:
  void solve(istream& cin, ostream& cout) {
    vector<std::pair<int, int>> P(3);
    cin >> P;
    vector2<int> D(1001, 1001, 0);
    pair<int, std::pair<int, int>> best = {1e4, {0, 0}};
    for (int i = 0; i <= 1000; ++i) {
      for (int j = 0; j <= 1000; ++j) {
        for (int k = 0; k < 3; ++k) {
          D[i][j] += abs(P[k].first - i) + abs(P[k].second - j);
        }
        best = min(best, {D[i][j], {i, j}});
      }
    }
    set<std::pair<int, int>> G;
    for (int k = 0; k < 3; ++k) {
      for (int i = min(best.second.first, P[k].first);
           i <= max(best.second.first, P[k].first); ++i) {
        G.insert({i, P[i].second});
      }
      for (int i = min(best.second.second, P[k].second);
           i <= max(best.second.second, P[k].second); ++i) {
        G.insert({best.second.first, i});
      }
    }
    cout << G.size() << '\n';
    for (std::pair<int, int> g : G) cout << g << '\n';
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  AConnectThree solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
