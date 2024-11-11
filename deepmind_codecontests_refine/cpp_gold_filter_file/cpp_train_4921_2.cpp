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
const int M = 999999937;
const int N = 2e6 + 100;
const int ppp = 73;
const int block = 320;
auto rnd = bind(uniform_int_distribution<long long>(1, 125), mt19937(time(0)));
void bad() {
  cout << "NO SOLUTION";
  exit(0);
}
int nxt[N];
int c1[N], c2[N], o1[N], o2[N];
int get(int l, int r, int w) {
  if (r < 0 || l < 0) return 0;
  if (w == 2) return c2[r] - (l == 0 ? 0 : c2[l - 1]);
  if (w == 1) return c1[r] - (l == 0 ? 0 : c1[l - 1]);
}
int ans = 0;
int n;
int go(int pos, int how) {
  if (pos >= n) return n;
  if (get(pos, pos + how - 1, 1) == how || get(pos, pos + how - 1, 2) == how) {
    return pos;
  } else {
    return nxt[pos] = go(nxt[pos], how);
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  cin >> n;
  string second;
  cin >> second;
  for (int i = 0; i < n; i++) {
    if (second[i] == '?' || second[i] == '0') {
      c1[i] = 1;
    }
    if (second[i] == '?' || second[i] == '1') {
      c2[i] = 1;
    }
    if (i) c1[i] += c1[i - 1], c2[i] += c2[i - 1];
    ;
  }
  for (int i = N - 1; i >= 0; i--) {
    nxt[i] = i + 1;
  }
  for (int i = 1; i <= n; i++) {
    int pos = 0;
    ans = 0;
    while (pos < n) {
      if (get(pos, pos + i - 1, 1) == i || get(pos, pos + i - 1, 2) == i)
        pos += i, ans++;
      else
        pos = go(pos, i);
    }
    cout << ans << ' ';
  }
  return 0;
}
