#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << ' ' << *it << " = " << a;
  err(++it, args...);
}
inline void op() { cout << '\n'; }
template <typename T, typename... Types>
inline void op(T var1, Types... var2) {
  cout << var1 << ' ';
  op(var2...);
}
inline void ip() {}
template <typename T, typename... Types>
inline void ip(T& var1, Types&... var2) {
  cin >> var1;
  ip(var2...);
}
template <typename T, typename U>
inline void min_self(T& x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void max_self(T& x, U y) {
  if (x < y) x = y;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
template <class T>
ostream& operator<<(ostream& out, vector<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ' ';
  return out << ")";
}
template <class T>
ostream& operator<<(ostream& out, set<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
template <class L, class R>
ostream& operator<<(ostream& out, map<L, R> vec) {
  out << "(";
  for (auto& v : vec) out << "[" << v.first << ", " << v.second << "]";
  return out << ")";
}
template <class A, class B>
istream& operator>>(istream& in, pair<A, B>& a) {
  return in >> a.first >> a.second;
}
template <class A>
istream& operator>>(istream& in, vector<A>& a) {
  for (A& i : a) in >> i;
  return in;
}
template <class Container>
void split(const std::string& str, Container& cont, char delim = ',') {
  stringstream ss(str);
  string token;
  while (std::getline(ss, token, delim)) {
    cont.push_back(token);
  }
}
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
struct edge {
  int u, v, wt;
  edge(int a = 0, int b = 0, int c = 0) : u(a), v(b), wt(c) {}
  bool operator<(edge const& other) { return wt < other.wt; }
  friend ostream& operator<<(ostream& out, const edge& x) {
    return out << "(" << x.u << ", " << x.v << ", " << x.wt << ")";
  }
};
long long n;
long double w;
void solve() {
  long long i, j, k;
  cin >> n >> w;
  long double a[2 * n];
  for (i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a, a + 2 * n);
  long double x, y;
  x = a[0];
  y = a[n];
  long double ii = 0, jj = a[0];
  long double ans;
  while ((jj - ii) > (1e-10)) {
    long double mid = (ii + jj) / 2.000;
    long double p = ((n * mid) + (2 * mid * n));
    if (2 * mid <= y && p <= w) {
      ans = p;
      ii = mid;
    } else {
      jj = mid;
    }
  }
  cout << fixed << setprecision(10) << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
