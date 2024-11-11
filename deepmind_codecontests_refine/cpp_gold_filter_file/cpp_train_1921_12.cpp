#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
namespace fio {
template <typename T>
void scan(T &x) {
  cin >> x;
}
template <class T>
void scan(vector<T> &a);
template <class T>
void scan(vector<T> &a) {
  for (int i = 0; i < ((int)(a).size()); ++i) scan(a[i]);
}
template <class T, class... Ts>
void scan(T &t, Ts &...ts) {
  scan(t);
  scan(ts...);
}
template <typename T>
void print(T x) {
  cout << x << endl;
}
template <class T, class... Ts>
void print(const T &t, const Ts &...ts) {
  print(t);
  print(ts...);
}
}  // namespace fio
using namespace fio;
const int N = 101;
struct DSU {
  vector<int> e;
  void init(int n) { e = vector<int>(n, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool sameSet(int a, int b) { return get(a) == get(b); }
  int size(int x) { return -e[get(x)]; }
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return 0;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return 1;
  }
};
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, m;
  scan(n, m);
  DSU d;
  d.init(N);
  while (m--) {
    int a, b;
    scan(a, b);
    d.unite(a, b);
  }
  set<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(d.get(i));
  }
  cout << (1LL << (n - (int)(s).size()));
  return 0;
}
