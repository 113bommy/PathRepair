#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  ~debug() { cerr << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug& operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug& operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
};
long double eps = (long double)1 / 1e6;
const long double pi = 3.14159265359;
long long inf = 1e18, mod1 = 1e9 + 7;
long long sqr(long long a) { return a * a; }
long long qb(long long a) { return a * a * a; }
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long binpow(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod
                    : sqr(binpow(a, b / 2, mod)) % mod)
           : 1;
}
long long binmult(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod
                    : (2 * binmult(a, b / 2, mod)) % mod)
           : 0;
}
const long long R = 1e4;
const long long tx[4] = {0, 0, -1, 1};
const long long ty[4] = {-1, 1, 0, 0};
const char rev_to[4] = {'E', 'W', 'N', 'S'};
const int N = 2e3 + 1;
int a[N][N], n, m;
long long lf[N][N], rd[N][N];
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  cin >> n;
  m = n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int j = 0; j < m; j++) {
    long long first = n - 1, second = j;
    long long o = 0;
    while (first >= 0 && second >= 0) {
      o += a[first][second];
      --first;
      --second;
    }
    first = n - 1, second = j;
    while (first >= 0 && second >= 0) {
      lf[first][second] = o - a[first][second];
      --first;
      --second;
    }
  }
  for (int j = 0; j < m; j++) {
    long long first = j, second = n - 1;
    long long o = 0;
    while (first >= 0 && second >= 0) {
      o += a[first][second];
      --first;
      --second;
    }
    first = j, second = n - 1;
    while (first >= 0 && second >= 0) {
      lf[first][second] = o - a[first][second];
      --first;
      --second;
    }
  }
  for (int j = 0; j < m; j++) {
    long long first = j, second = 0;
    long long o = 0;
    while (first >= 0 && second < m) {
      o += a[first][second];
      --first;
      ++second;
    }
    first = j, second = 0;
    while (first >= 0 && second < m) {
      rd[first][second] = o - a[first][second];
      --first;
      ++second;
    }
  }
  for (int j = 0; j < m; j++) {
    long long first = n - 1, second = j;
    long long o = 0;
    while (first >= 0 && second < m) {
      o += a[first][second];
      --first;
      ++second;
    }
    first = n - 1, second = j;
    while (first >= 0 && second < m) {
      rd[first][second] = o - a[first][second];
      --first;
      ++second;
    }
  }
  long long mx[2];
  pair<long long, long long> lol[2];
  mx[0] = -inf;
  mx[1] = -inf;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] + lf[i][j] + rd[i][j] > mx[(i + j) % 2]) {
        mx[(i + j) % 2] = a[i][j] + lf[i][j] + rd[i][j];
        lol[(i + j) % 2] = {i, j};
      }
    }
  }
  cout << mx[0] << ' ' << mx[1] << "\n";
  cout << lol[0].first + 1 << ' ' << lol[0].second + 1 << ' '
       << lol[1].first + 1 << ' ' << lol[1].second + 1;
  return 0;
}
