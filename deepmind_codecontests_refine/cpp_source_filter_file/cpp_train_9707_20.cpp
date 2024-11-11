#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
  fast_ios() {
    cin.tie(nullptr), ios::sync_with_stdio(false),
        cout << fixed << setprecision(20);
  };
} fast_ios_;
template <typename T, typename V>
void ndarray(vector<T> &vec, const V &val, int len) {
  vec.assign(len, val);
}
template <typename T, typename V, typename... Args>
void ndarray(vector<T> &vec, const V &val, int len, Args... args) {
  vec.resize(len),
      for_each(begin(vec), end(vec), [&](T &v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool chmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first + r.first, l.second + r.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first - r.first, l.second - r.second);
}
template <typename T>
vector<T> sort_unique(vector<T> vec) {
  sort(vec.begin(), vec.end()),
      vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
template <typename T>
int arglb(const std::vector<T> &v, const T &x) {
  return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x));
}
template <typename T>
int argub(const std::vector<T> &v, const T &x) {
  return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x));
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '[';
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <typename T, size_t sz>
ostream &operator<<(ostream &os, const array<T, sz> &arr) {
  os << '[';
  for (auto v : arr) os << v << ',';
  os << ']';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec) {
  os << "deq[";
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T, typename TH>
ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa) {
  os << '(' << pa.first << ',' << pa.second << ')';
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp) {
  os << '{';
  for (auto v : mp) os << v.first << "=>" << v.second << ',';
  os << '}';
  return os;
}
template <typename TK, typename TV, typename TH>
ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) {
  os << '{';
  for (auto v : mp) os << v.first << "=>" << v.second << ',';
  os << '}';
  return os;
}
struct Cubic {
  using Int = __int128;
  Int a;
  Int lb, ub;
  Cubic(Int a, Int ub) : a(a), lb(0), ub(ub) {}
  Int slope(Int s) const {
    Int lo = lb, hi = ub + 1;
    while (hi - lo > 1) {
      Int x = (lo + hi) / 2;
      (next_cost(x) <= s ? lo : hi) = x;
    }
    return lo;
  }
  Int eval(Int x) const noexcept { return (x * x - a) * x; }
  Int next_cost(Int x) const noexcept { return 3 * x * x - 3 * x + 1 - a; }
};
template <typename F, typename Int, Int INF>
struct QuadraticSumMinimizationUnderLinearConstraint {
  std::pair<Int, std::vector<std::vector<std::pair<Int, Int>>>> operator()(
      const std::vector<Int> &k, const std::vector<F> &f, Int C) {
    assert(k.size() == f.size());
    assert(k.size() > 0);
    Int lbsum = 0, ubsum = 0;
    for (auto func : f) lbsum += func.lb, ubsum += func.ub;
    if (lbsum > C or ubsum < C) return {};
    const int N = k.size();
    Int few = -INF, enough = INF;
    Int fewc = 0;
    while (enough - few > 1) {
      auto slope = few + (enough - few) / 2;
      Int cnt = 0;
      for (int i = 0; i < N; i++) {
        auto tmp = f[i].slope(slope);
        cnt += tmp * k[i];
        if (cnt >= C) break;
      }
      if (cnt >= C) {
        enough = slope;
      } else {
        few = slope;
        fewc = cnt;
      }
    }
    std::vector<std::vector<std::pair<Int, Int>>> ret(N);
    std::vector<int> additional;
    Int ctmp = 0;
    Int sol = 0;
    for (int i = 0; i < N; i++) {
      auto xlo = f[i].slope(few);
      auto xhi = f[i].slope(few + 1);
      ctmp += k[i] * xlo;
      ret[i].emplace_back(xlo, k[i]);
      if (xlo < xhi) additional.push_back(i);
      sol += k[i] * f[i].eval(xlo);
    }
    sol += (C - ctmp) * (few + 1);
    while (additional.size()) {
      int i = additional.back();
      additional.pop_back();
      Int add = C - ctmp > k[i] ? k[i] : C - ctmp;
      auto x = ret[i][0].first;
      if (add) {
        ret[i][0].second -= add;
        if (ret[i][0].second == 0) ret[i].pop_back();
        ret[i].emplace_back(x + 1, add);
        ctmp += add;
      }
    }
    return {sol, ret};
  }
};
__int128 eval(lint a, __int128 x) { return x * (a - x * x); }
__int128 differential(lint a, __int128 x) {
  if (x <= 0) return 1e12;
  return eval(a, x) - eval(a, x - 1);
}
lint argmaxf(lint a) {
  lint bcand = sqrt(a / 3 + 1);
  __int128 ret = max<lint>(0LL, min<lint>(bcand, a + 1));
  for (int b = (max<lint>(bcand - 10, 0)),
           b_end_ = (min<lint>(a + 1, bcand + 10));
       b < b_end_; b++) {
    if (eval(a, b) >= eval(a, ret)) ret = b;
  }
  return ret;
}
int main() {
  int N;
  lint K;
  cin >> N >> K;
  vector<lint> A(N);
  cin >> A;
  vector<Cubic> functions;
  for (int i = (0), i_end_ = (N); i < i_end_; i++)
    functions.emplace_back(A[i], A[i]);
  QuadraticSumMinimizationUnderLinearConstraint<Cubic, __int128, 1LL << 60>
      solver;
  auto ret = solver(vector<__int128>(N, 1), functions, K);
  if (ret.second.empty()) return 0;
  for (auto p : ret.second) cout << lint(p[0].first) << ' ';
  cout << '\n';
}
