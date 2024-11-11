#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
std::istream &operator>>(std::istream &i, pair<T, U> &p) {
  i >> p.first >> p.second;
  return i;
}
template <typename T>
std::istream &operator>>(std::istream &i, vector<T> &t) {
  for (auto &v : t) {
    i >> v;
  }
  return i;
}
template <typename T, typename U>
std::ostream &operator<<(std::ostream &o, const pair<T, U> &p) {
  o << p.first << ' ' << p.second;
  return o;
}
template <typename T>
std::ostream &operator<<(std::ostream &o, const vector<T> &t) {
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
unsigned int logceil(int first) {
  return 8 * sizeof(int) - __builtin_clz(first);
}
namespace std {
template <typename T, typename U>
struct hash<pair<T, U>> {
  hash<T> t;
  hash<U> u;
  size_t operator()(const pair<T, U> &p) const {
    return t(p.first) ^ (u(p.second) << 7);
  }
};
}  // namespace std
template <typename T, typename F>
T bsh(T l, T h, const F &f) {
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
double bshd(double l, double h, const F &f, double p = 1e-9) {
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
T bsl(T l, T h, const F &f) {
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
double bsld(double l, double h, const F &f, double p = 1e-9) {
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
template <typename T>
struct bounded_priority_queue {
  inline bounded_priority_queue(unsigned int X) : A(X), B(0), s(0) {}
  inline void push(unsigned int L, T V) {
    B = max(B, L);
    A[L].push(V);
    ++s;
  }
  inline const T &top() const { return A[B].front(); }
  inline void pop() {
    --s;
    A[B].pop();
    while (B > 0 && A[B].empty()) --B;
  }
  inline bool empty() const { return A[B].empty(); }
  inline void clear() {
    s = B = 0;
    for (auto &a : A) a = queue<T>();
  }
  inline unsigned int size() const { return s; }

 private:
  vector<queue<T>> A;
  unsigned int B;
  int s;
};
struct UnionFind {
  UnionFind(size_t N) : P(N, -1), comp(N) {}
  int find(int first) {
    while (P[first] > 0) {
      first = P[first] - 1;
    }
    return first;
  }
  bool united(int first, int second) { return find(first) == find(second); }
  bool unite(int first, int second) {
    first = find(first);
    second = find(second);
    if (first == second) {
      return false;
    }
    --comp;
    if (P[first] > P[second]) {
      swap(first, second);
    }
    P[first] += P[second];
    P[second] = first + 1;
    return true;
  }
  inline unsigned int size(int u) { return -P[find(u)]; }
  vector<int> P;
  size_t comp;
};
unsigned long long mulull(unsigned long long a, unsigned long long z,
                          unsigned long long mod) {
  __int128 result = ((__int128)a * (__int128)z) % (__int128)mod;
  return (unsigned long long)result;
}
pair<unsigned long long, unsigned long long> mulull(unsigned long long a,
                                                    unsigned long long b) {
  __int128 result = (__int128)a * (__int128)b;
  return {(unsigned long long)(result >> 64), (unsigned long long)result};
}
bool fractionGreaterOrEqual(long long a, long long b, long long c,
                            long long d) {
  if (b < 0) {
    b = -b;
    a = -a;
  }
  if (d < 0) {
    d = -d;
    c = -c;
  }
  return a < 0 && c < 0 ? mulull(-a, d) <= mulull(-c, b)
                        : (a >= 0) && (c < 0 || mulull(a, d) >= mulull(c, b));
}
bool fractionGreaterOrEqual(pair<long long, long long> a,
                            pair<long long, long long> b) {
  return fractionGreaterOrEqual(a.first, a.second, b.first, b.second);
}
bool fractionGreaterOrEqual(double a, double b, double c, double d) {
  return a / b >= c / d;
}
namespace Envelope {
template <typename T>
struct Line {
  T m, b;
  int id;
  mutable function<const Line<T> *()> succ;
  bool operator<(const Line &rhs) const {
    if (rhs.b != numeric_limits<T>::min()) return m < rhs.m;
    const Line *s = succ();
    if (!s) return 0;
    return b - s->b < (s->m - m) * rhs.m;
  }
};
template <typename T>
struct Upper : public multiset<Envelope::Line<T>> {
  using parent = multiset<Line<T>>;
  bool bad(typename parent::iterator second) {
    auto z = next(second);
    if (second == parent::begin()) {
      return z != parent::end() && second->m == z->m && second->b <= z->b;
    } else {
      auto first = prev(second);
      if (z == parent::end()) {
        return second->m == first->m && second->b <= first->b;
      } else {
        return fractionGreaterOrEqual(first->b - second->b,
                                      second->m - first->m, second->b - z->b,
                                      z->m - second->m);
      }
    }
  }
  void insert_line(T m, T b, int i = 0) {
    auto second = parent::insert({m, b, i});
    second->succ = [=] {
      return next(second) == parent::end() ? 0 : &*next(second);
    };
    if (bad(second)) {
      parent::erase(second);
      return;
    }
    while (next(second) != parent::end() && bad(next(second)))
      parent::erase(next(second));
    while (second != parent::begin() && bad(prev(second)))
      parent::erase(prev(second));
  }
  T operator[](T first) const {
    auto l = parent::lower_bound({first, numeric_limits<T>::min()});
    return l == parent::end() ? numeric_limits<T>::min() : l->m * first + l->b;
  }
  int best(T first) const {
    auto l = parent::lower_bound({first, numeric_limits<T>::min()});
    return l == parent::end() ? -1 : l->id;
  }
};
template <typename T>
struct Lower : public Upper<T> {
  void insert_line(T m, T b, int i = 0) { Upper<T>::insert_line(-m, -b, i); }
  T operator[](T first) const { return -Upper<T>::operator[](first); }
};
}  // namespace Envelope
namespace LinearEnvelope {
template <typename T>
struct Line {
  T m, b;
  int id;
};
template <typename T>
struct Upper : public vector<Line<T>> {
  using parent = vector<Line<T>>;
  using parent::at;
  using parent::back;
  using parent::size;
  T t;
  int i;
  Upper() : t(0), i(0) {}
  void insert_line(T m, T b, int i = 0) {
    assert(t == 0);
    while (size() > 0 && ((back().b < b) || (back().b == b && back().m < m)))
      parent::pop_back();
    while (size() >= 2 && fractionGreaterOrEqual(at(size() - 2).b - back().b,
                                                 back().m - at(size() - 2).m,
                                                 back().b - b, m - back().m))
      parent::pop_back();
    parent::push_back({m, b, i});
  }
  pair<T, int> advance(T first) {
    assert(first >= 0);
    t += first;
    while (i + 1 < size() &&
           at(i).m * t + at(i).b < at(i + 1).m * t + at(i + 1).b)
      ++i;
    return {at(i).m * t + at(i).b, at(i).id};
  }
};
};  // namespace LinearEnvelope
class BeautifulRoad {
 public:
  unordered_map<int, int> S;
  unordered_map<std::pair<int, int>, long long> T;
  unordered_map<int, vector<int>> F;
  int size(int u, int v) {
    int z = T[{u, v}];
    if (z) return z;
    int tot = dfs(u, -1);
    dfs2(u, -1, tot);
    return T[{u, v}];
  }
  int dfs(int u, int p) {
    int z = S[u];
    for (int v : F[u]) {
      if (v != p) z += dfs(v, u);
    }
    return z;
  }
  int dfs2(int u, int p, int tot) {
    int z = T[{u, p}];
    if (z) return z;
    z = S[u];
    for (int v : F[u]) {
      if (v != p) {
        z += dfs2(v, u, tot);
      }
    }
    for (int v : F[u]) {
      if (v != p) {
        T[{u, v}] = tot - T[{v, u}];
      }
    }
    return T[{u, p}] = z;
  }
  void solve(istream &cin, ostream &cout) {
    int N;
    cin >> N;
    map<int, vector<pair<int, std::pair<int, int>>>> E;
    for (int i = 0; i < N - 1; ++i) {
      int u, v, d;
      cin >> u >> v >> d;
      E[d].push_back({i, {u - 1, v - 1}});
    }
    vector<long long> Ans(N - 1, 0);
    UnionFind UF(N);
    for (auto &e : E) {
      S.clear();
      T.clear();
      F.clear();
      for (auto &ee : e.second) {
        int u = UF.find(ee.second.first);
        int v = UF.find(ee.second.second);
        S[u] = UF.size(u);
        S[v] = UF.size(v);
        F[u].push_back(v);
        F[v].push_back(u);
      }
      for (auto &ee : e.second) {
        int u = UF.find(ee.second.first);
        int v = UF.find(ee.second.second);
        Ans[ee.first] = 2 * size(u, v) * size(v, u);
      }
      for (auto &ee : e.second) {
        UF.unite(ee.second.first, ee.second.second);
      }
    }
    long long best = *max_element(Ans.begin(), Ans.end());
    int cnt = count(Ans.begin(), Ans.end(), best);
    vector<int> Edges;
    for (int i = 0; i < N; ++i) {
      if (Ans[i] == best) Edges.push_back(i + 1);
    }
    cout << best << ' ' << cnt << endl << Edges;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  BeautifulRoad solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solve(in, out);
  return 0;
}
