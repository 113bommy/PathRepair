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
template <typename T>
bool umax(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
bool umin(T& a, T b) {
  return b < a ? a = b, 1 : 0;
}
bool is_prime(long long val) {
  for (long long i = 2; i <= sqrt(val); i++)
    if (val % i == 0) return 0;
  return 1;
}
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
const long long RR = 1e4;
const long long tx[8] = {1, -1, 2, -2, -1, -2};
const long long ty[8] = {-2, -2, -1, -1, 2, 1};
const char rev_to[4] = {'E', 'W', 'N', 'S'};
const int M = 1e9 + 7;
const int N = 5000;
const int ppp = 73;
const int pr = 3;
const int block = 320;
auto rnd = bind(uniform_int_distribution<long long>(1, 125), mt19937(time(0)));
void bad() {
  cout << "-1";
  exit(0);
}
struct bigint {
  int kek[N];
  int to = 1;
  void init() {
    for (int i = 0; i < N; i++) kek[i] = 0;
  }
};
bigint operator+(const bigint& a, const bigint& b) {
  bigint lulw;
  lulw.init();
  for (int i = 0; i < max(b.to, a.to) + 1; i++) {
    int val = a.kek[i] + b.kek[i];
    lulw.kek[i + 1] += (val + lulw.kek[i]) / 10;
    lulw.kek[i] = (val + lulw.kek[i]) % 10;
  }
  for (int i = N - 1; ~i; --i)
    if (lulw.kek[i]) {
      lulw.to = i + 1;
      break;
    }
  return lulw;
}
bigint pows[2001];
int st[2001];
int nd[2001];
bool is[N];
vector<int> pos[2001];
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < 2001; i++) {
    pows[i].init();
  }
  pows[0].kek[0] = 1;
  for (int i = 1; i < 2001; i++) {
    pows[i].init();
    pows[i] = pows[i - 1] + pows[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    string second;
    cin >> second;
    int x;
    cin >> x;
    if (second == "win") {
      if (!nd[x]) {
        st[x] = i;
      }
    } else {
      if (st[x]) nd[x] = i;
    }
  }
  int posd = n + 1;
  bigint ans;
  ans.init();
  for (int i = 2000; i >= 0; i--) {
    if (nd[i]) {
      bool ok = 1;
      for (int j = st[i]; j <= nd[i]; j++) {
        if (is[j]) {
          ok = 0;
          break;
        }
      }
      if (!ok) continue;
      for (int j = st[i]; j <= nd[i]; j++) {
        is[j] = 1;
      }
      ans = ans + pows[i];
    }
  }
  for (int i = ans.to - 1; i >= 0; i--) cout << ans.kek[i];
  return 0;
}
