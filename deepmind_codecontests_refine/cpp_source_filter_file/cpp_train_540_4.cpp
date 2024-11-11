#include <bits/stdc++.h>
using namespace std;
void solve();
using ll = long long;
template <class T = ll>
using V = vector<T>;
using vi = V<int>;
using vl = V<>;
using vvi = V<V<int> >;
constexpr int inf = 1001001001;
constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {
  IoSetupNya() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(7);
  }
} iosetupnya;
template <typename T, typename U>
inline bool amin(T &x, U y) {
  return (y < x) ? (x = y, true) : false;
}
template <typename T, typename U>
inline bool amax(T &x, U y) {
  return (x < y) ? (x = y, true) : false;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  int s = (int)v.size();
  for (long long i = 0; i < (long long)(s); i++) os << (i ? " " : "") << v[i];
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
void in() {}
template <typename T, class... U>
void in(T &t, U &...u) {
  cin >> t;
  in(u...);
}
void out() { cout << "\n"; }
template <typename T, class... U>
void out(const T &t, const U &...u) {
  cout << t;
  if (sizeof...(u)) cout << " ";
  out(u...);
}
template <typename T>
void die(T x) {
  out(x);
  exit(0);
}
int main() { solve(); }
using vd = V<double>;
using vs = V<string>;
using vvl = V<V<> >;
template <typename T>
using heap = priority_queue<T, V<T>, greater<T> >;
using P = pair<ll, ll>;
using vp = V<P>;
constexpr int MOD = 1000000007;
void q() {
  int N, M, K;
  in(N, M, K);
  vi a(N);
  in(a);
  K = min(K, M - 1);
  multiset<int> s;
  int l = M - 1, r = N - 1;
  while (K <= l) {
    s.emplace(max(a[l], a[r]));
    l--;
    r--;
  }
  int ans = *s.begin();
  while (l >= 0) {
    s.erase(max(a[l + M - K], a[r + M - K]));
    s.emplace(max(a[l], a[r]));
    amax(ans, *s.begin());
    l--;
    r--;
  }
  out(ans);
}
void solve() {
  int Q;
  in(Q);
  for (long long i = 0; i < (long long)(Q); i++) q();
}
