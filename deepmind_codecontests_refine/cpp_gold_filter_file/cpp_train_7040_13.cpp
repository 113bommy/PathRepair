#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int in() {
  int x;
  cin >> x;
  return x;
}
long long lin() {
  long long x;
  cin >> x;
  return x;
}
string stin() {
  string s;
  cin >> s;
  return s;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
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
void print() { putchar(' '); }
void print(bool a) { cout << a; }
void print(int a) { cout << a; }
void print(long long a) { cout << a; }
void print(char a) { cout << a; }
void print(string& a) { cout << a; }
void print(double a) { cout << a; }
template <class T>
void print(const vector<T>&);
template <class T, size_t size>
void print(const array<T, size>&);
template <class T, class L>
void print(const pair<T, L>& p);
template <class T, size_t size>
void print(const T (&)[size]);
template <class T>
void print(const vector<T>& a) {
  if (a.empty()) return;
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    cout << " ";
    print(*i);
  }
  cout << "\n";
}
template <class T>
void print(const deque<T>& a) {
  if (a.empty()) return;
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    cout << " ";
    print(*i);
  }
}
template <class T, size_t size>
void print(const array<T, size>& a) {
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    cout << " ";
    print(*i);
  }
}
template <class T, class L>
void print(const pair<T, L>& p) {
  cout << '(';
  print(p.first);
  cout << ",";
  print(p.second);
  cout << ')';
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
void print(const T& a) {
  cout << a;
}
int out() {
  putchar('\n');
  return 0;
}
template <class T>
int out(const T& t) {
  print(t);
  putchar('\n');
  return 0;
}
template <class Head, class... Tail>
int out(const Head& head, const Tail&... tail) {
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
template <class... T>
void err(const T&...) {}
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
      int n_, F f, G g, H h, T d1, E d0, vector<T> v = vector<T>(),
      P p = [](E a, int b) { return a; })
      : f(f), g(g), h(h), d1(d1), d0(d0), p(p) {
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
};
constexpr int N = 101000;
using vl = vector<long double>;
vl a;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  int n = in(), q = in();
  for (long long i = 0; i < n; i++) a.push_back(in());
  using P = pair<long double, long double>;
  LazySegmentTree<long double, P> seg(
      n, [](long double x, long double y) { return x + y; },
      [](long double x, P y) { return x * y.first + y.second; },
      [](P x, P y) {
        return P{x.first * y.first, x.second * y.first + y.second};
      },
      (long double)0, P{1, 0}, a,
      [](P x, int n) {
        return P{x.first, x.second * n};
      });
  for (long long i = 0; i < q; i++) {
    int id = in();
    if (id == 1) {
      int l1 = in() - 1, r1 = in() - 1, l2 = in() - 1, r2 = in() - 1;
      long long t = r1 - l1 + 1, s = r2 - l2 + 1;
      long double T = seg.query(l2, r2 + 1) / (long double)(t * s);
      long double S = seg.query(l1, r1 + 1) / (long double)(t * s);
      seg.update(l1, r1 + 1, P{(long double)(t - 1) / (long double)t, T});
      seg.update(l2, r2 + 1, P{(long double)(s - 1) / (long double)s, S});
    } else {
      int l = in() - 1, r = in() - 1;
      cout << seg.query(l, r + 1) << "\n";
    }
  }
}
