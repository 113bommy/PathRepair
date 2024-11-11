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
auto dud(c* x) -> decltype(cout << *x, 0);
template <class c>
char dud(...);
struct debug {
  ~debug() { cout << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
    cout << boolalpha << i;
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
void binary(long long val, int to) {
  for (int i = 0; i < to; i++) cerr << ((1ll << i) & val ? 1 : 0);
  cerr << "\n";
}
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
const long long tx[4] = {1, 0, -1, 0};
const long long ty[4] = {0, 1, 0, -1};
const char rev_to[4] = {'E', 'W', 'N', 'S'};
const int N = 5e5 + 1;
const int M = 1e9 + 7;
auto rnd = bind(uniform_int_distribution<long long>(1, 1e12), mt19937(time(0)));
void bad() {
  cout << -1;
  exit(0);
}
pair<int, int> h[N];
bool us[N];
vector<int> w[N];
int a[N];
void add(int id, int to) {
  if (us[id]) {
    int n = (long long)w[id].size();
    for (int mask = 0; mask < (1ll << n); mask++) {
      int vl = 1;
      for (int j = 0; j < n; j++) {
        if ((1ll << j) & mask) vl *= w[id][j];
      }
      h[vl].second = __builtin_popcount(mask);
    }
    us[id] = 1;
  } else {
    int x = a[id];
    vector<int> c;
    for (int i = 2; 1ll * i * i <= x; i++) {
      if (x % i) continue;
      while (x % i == 0) x /= i;
      c.push_back(i);
    }
    if (x != 1) c.push_back(x);
    w[id] = c;
    us[id] = 1;
    add(id, 1);
  }
}
bool here[N];
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i], add(i, 0);
  long long a1 = 0;
  while (q--) {
    int x;
    cin >> x;
    --x;
    int vl = 1;
    int to;
    if (!here[x]) {
      to = -1;
    } else {
      to = 1;
    }
    int id = x;
    int n = (long long)w[id].size();
    for (int mask = 0; mask < (1ll << n); mask++) {
      int vl = 1;
      for (int j = 0; j < n; j++) {
        if ((1ll << j) & mask) vl *= w[id][j];
      }
      if (h[vl].second % 2 == 0)
        a1 -= (h[vl].first * 1ll * (h[vl].first - 1)) / 2;
      else
        a1 += (h[vl].first * 1ll * (h[vl].first - 1)) / 2;
      h[vl].first += to;
      if (h[vl].second % 2 == 0)
        a1 += (h[vl].first * 1ll * (h[vl].first - 1)) / 2;
      else
        a1 -= (h[vl].first * 1ll * (h[vl].first - 1)) / 2;
    }
    here[x] ^= 1;
    cout << a1 - 1 << "\n";
  }
  return 0;
}
