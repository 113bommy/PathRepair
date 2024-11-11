#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<long long>;
using pii = pair<long long, long long>;
const signed INF_ = 1001001001;
const long long INF = 1001001001001001001LL;
const long long DX[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0},
                DY[9] = {-1, 0, 1, 0, -1, 1, 1, -1, 0};
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto i = (begin(v)); i != (end(v)); ++i)
    os << *i << (i == end(v) - 1 ? "" : " ");
  return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto i = (begin(v)); i != (end(v)); ++i) is >> *i;
  return is;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <class T, class U>
bool chmax(T &a, const U &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class U>
bool chmin(T &a, const U &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
using heap = priority_queue<T, vector<T>, greater<T>>;
struct before_main_function {
  before_main_function() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
  }
} before_main_function;
signed main() {
  long long n, m, __;
  cin >> n >> __;
  vi a(n);
  cin >> a;
  cin >> m >> __;
  vi b(m);
  cin >> b;
  long long ans = 0;
  for (long long k = 0, klen = (long long)(40); k < klen; ++k) {
    long long d = 1LL << k;
    map<long long, long long> cnt;
    for (auto &x : a) cnt[x % (2 * d)]++;
    for (auto &x : b) cnt[(x + d) % (2 * d)]++;
    for (auto &p : cnt) chmax(ans, p.second);
  }
  cout << ans << "\n";
  return (0 ^ 0 ^ 0);
}
