#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
int scan() { return getchar(); }
template <class T>
void scan(T a) {
  cin >> a;
}
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T>
void scan(vector<T> &);
template <class T, size_t size>
void scan(array<T, size> &);
template <class T, class L>
void scan(pair<T, L> &);
template <class T, size_t size>
void scan(T (&)[size]);
template <class T>
void scan(vector<T> &a) {
  for (auto &i : a) scan(i);
}
template <class T>
void scan(deque<T> &a) {
  for (auto &i : a) scan(i);
}
template <class T, size_t size>
void scan(array<T, size> &a) {
  for (auto &i : a) scan(i);
}
template <class T, class L>
void scan(pair<T, L> &p) {
  scan(p.first);
  scan(p.second);
}
template <class T, size_t size>
void scan(T (&a)[size]) {
  for (auto &i : a) scan(i);
}
template <class T>
void scan(T &a) {
  cin >> a;
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &...tail) {
  scan(head);
  IN(tail...);
}
string stin() {
  string s;
  cin >> s;
  return s;
}
template <class T, class S>
inline bool chmax(T &a, S b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class S>
inline bool chmin(T &a, S b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
vector<int> iota(int n) {
  vector<int> a(n);
  iota(begin(a), end(a), 0);
  return a;
}
template <class T>
void UNIQUE(vector<T> &x) {
  sort(begin(x), end(x));
  x.erase(unique(begin(x), end(x)), x.end());
}
int in() {
  int x;
  cin >> x;
  return x;
}
long long lin() {
  unsigned long long x;
  cin >> x;
  return x;
}
void print() { putchar(' '); }
void print(bool a) { cout << a; }
void print(int a) { cout << a; }
void print(long long a) { cout << a; }
void print(char a) { cout << a; }
void print(string &a) { cout << a; }
void print(double a) { cout << a; }
template <class T>
void print(const vector<T> &);
template <class T, size_t size>
void print(const array<T, size> &);
template <class T, class L>
void print(const pair<T, L> &p);
template <class T, size_t size>
void print(const T (&)[size]);
template <class T>
void print(const vector<T> &a) {
  if (a.empty()) return;
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    cout << " ";
    print(*i);
  }
  cout << endl;
}
template <class T>
void print(const deque<T> &a) {
  if (a.empty()) return;
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    cout << " ";
    print(*i);
  }
}
template <class T, size_t size>
void print(const array<T, size> &a) {
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    cout << " ";
    print(*i);
  }
}
template <class T, class L>
void print(const pair<T, L> &p) {
  cout << '(';
  print(p.first);
  cout << ",";
  print(p.second);
  cout << ')';
}
template <class T>
void print(set<T> &x) {
  for (auto e : x) print(e), cout << " ";
  cout << endl;
}
template <class T>
void print(multiset<T> &x) {
  for (auto e : x) print(e), cout << " ";
  cout << endl;
}
template <class T, size_t size>
void print(const T (&a)[size]) {
  print(a[0]);
  for (auto i = a; ++i != end(a);) {
    cout << " ";
    print(*i);
  }
}
template <class T>
void print(const T &a) {
  cout << a;
}
int out() {
  putchar('\n');
  return 0;
}
template <class T>
int out(const T &t) {
  print(t);
  putchar('\n');
  return 0;
}
template <class Head, class... Tail>
int out(const Head &head, const Tail &...tail) {
  print(head);
  putchar(' ');
  out(tail...);
  return 0;
}
long long gcd(long long a, long long b) {
  while (b) {
    long long c = b;
    b = a % b;
    a = c;
  }
  return a;
}
long long lcm(long long a, long long b) {
  if (!a || !b) return 0;
  return a * b / gcd(a, b);
}
vector<pair<long long, long long>> factor(long long x) {
  vector<pair<long long, long long>> ans;
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) {
      ans.push_back({i, 1});
      while ((x /= i) % i == 0) ans.back().second++;
    }
  if (x != 1) ans.push_back({x, 1});
  return ans;
}
vector<int> divisor(int x) {
  vector<int> ans;
  for (int i = 1; i * i <= x; i++)
    if (x % i == 0) {
      ans.push_back(i);
      if (i * i != x) ans.push_back(x / i);
    }
  return ans;
}
template <typename T>
void zip(vector<T> &x) {
  vector<T> y = x;
  sort(begin(y), end(y));
  for (int i = 0; i < x.size(); ++i) {
    x[i] = distance((y).begin(), lower_bound(begin(y), end(y), (x[i])));
  }
}
int popcount(long long x) { return __builtin_popcountll(x); }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n) { return uniform_int_distribution<int>(0, n - 1)(rng); }
template <typename T>
void shuffle(vector<T> &v) {
  for (long long i = v.size() - 1; i >= 1; --i) {
    swap(v[i], v[rnd(i)]);
  }
}
vector<string> YES{"NO", "YES"};
vector<string> Yes{"No", "Yes"};
vector<string> yes{"no", "yes"};
template <class... T>
void err(const T &...) {}
template <typename T>
struct edge {
  int from, to;
  T cost;
  int id;
  edge(int to, T cost) : from(-1), to(to), cost(cost) {}
  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
struct Graph : vector<vector<int>> {
  using vector<vector<int>>::vector;
  inline void add(int a, int b, bool directed = false) {
    (*this)[a].emplace_back(b);
    if (!directed) (*this)[b].emplace_back(a);
  }
  void read(int n = -1, int offset = 1) {
    if (n == -1) n = this->size() - 1;
    int a, b;
    while (n--) {
      cin >> a >> b;
      Graph::add(a - offset, b - offset);
    }
  }
};
template <typename T>
struct WeightedGraph : vector<Edges<T>> {
  using vector<Edges<T>>::vector;
  inline void add(int a, int b, T c, bool directed = false) {
    (*this)[a].emplace_back(b, c);
    if (!directed) (*this)[b].emplace_back(a, c);
  }
  void read(int n = -1, int offset = 1) {
    if (n == -1) n = this->size() - 1;
    int a, b;
    while (n--) {
      cin >> a >> b;
      Graph::add(a - offset, b - offset);
    }
  }
};
struct Setup_io {
  Setup_io() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
  }
} setup_io;
template <typename T, typename E>
struct LazySegmentTree {
  typedef function<T(T, T)> F;
  typedef function<T(T, E)> G;
  typedef function<E(E, E)> H;
  typedef function<E(E, int)> P;
  int n;
  F f;
  G g;
  H h;
  P p;
  T d1;
  E d0;
  vector<T> dat;
  vector<E> laz;
  LazySegmentTree(
      int n_, F _f, G _g, H _h, T _d1, E _d0, vector<T> v = vector<T>(),
      P _p = [](E a, int b) { return a; })
      : f(_f), g(_g), h(_h), d1(_d1), d0(_d0), p(_p) {
    init(n_);
    if (n_ == (int)v.size()) build(n_, v);
  }
  void init(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    dat.clear();
    dat.resize(2 * n - 1, d1);
    laz.clear();
    laz.resize(2 * n - 1, d0);
  }
  void build(int n_, vector<T> v) {
    for (int i = 0; i < n_; i++) dat[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--) dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
  }
  inline void eval(int len, int k) {
    if (laz[k] == d0) return;
    if (k * 2 + 1 < n * 2 - 1) {
      laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
      laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
    }
    dat[k] = g(dat[k], p(laz[k], len));
    laz[k] = d0;
  }
  T update(int a, int b, E x, int k, int l, int r) {
    eval(r - l, k);
    if (r <= a || b <= l) return dat[k];
    if (a <= l && r <= b) {
      laz[k] = h(laz[k], x);
      return g(dat[k], p(laz[k], r - l));
    }
    return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
                      update(a, b, x, k * 2 + 2, (l + r) / 2, r));
  }
  T update(int a, int b, E x) { return update(a, b, x, 0, 0, n); }
  T query(int a, int b, int k, int l, int r) {
    eval(r - l, k);
    if (r <= a || b <= l) return d1;
    if (a <= l && r <= b) return dat[k];
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return f(vl, vr);
  }
  T query(int a, int b) { return query(a, b, 0, 0, n); }
  void print(int x) {
    for (long long i = 0; i < x; ++i) {
      cout << query(i, i + 1) << " ";
    }
    cout << '\n';
  }
};
constexpr int N = 301000;
auto f = [](int x, int y) { return min(x, y); };
auto g = plus<int>();
int main() {
  int n;
  IN(n);
  LazySegmentTree<int, int> seg(n, f, g, g, INT_MAX, 0);
  seg.build(n, vector<int>(n));
  vector<int> ans(n);
  set<int> rem;
  for (long long i = 0; i < n; ++i) {
    int p, t;
    IN(p, t);
    p--;
    vector<int> proc;
    if (t) {
      int x;
      IN(x);
      ans[p] = x;
      seg.update(p, n, 1);
      auto it = rem.upper_bound(p);
      if (it != rem.end()) proc.emplace_back(*it), rem.erase(it);
    } else {
      if (seg.query(p, p + 1))
        proc.emplace_back(p);
      else
        rem.emplace(p);
    }
    for (auto p : proc) {
      int l = p, r = n + 1;
      while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (seg.query(p, mid) == 0)
          r = mid;
        else
          l = mid;
      }
      seg.update(p, l, -1);
      if (l != n) rem.emplace(l);
    }
    int now = seg.query(n - 1, n);
    if (now == 0) {
      cout << -1 << '\n';
      continue;
    }
    int l = -1, r = n - 1;
    while (r - l > 1) {
      int mid = (r + l) >> 1;
      if (seg.query(mid, n) >= now)
        r = mid;
      else
        l = mid;
    }
    cout << ans[r] << '\n';
  }
}
