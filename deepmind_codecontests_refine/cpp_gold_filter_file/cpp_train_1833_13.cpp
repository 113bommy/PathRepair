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
const long long tx[4] = {0, 0, -1, 1};
const long long ty[4] = {-1, 1, 0, 0};
const char rev_to[4] = {'E', 'W', 'N', 'S'};
const int M = 2e5 + 3;
const int N = 3e5;
const int ppp = 73;
const int Y = 1;
const int X = 0;
const int L = 1;
const int R = 2;
const int U = 3;
const int D = 4;
auto rnd = bind(uniform_int_distribution<long long>(1, N), mt19937(time(0)));
void bad() {
  cout << "NE";
  exit(0);
}
int l[N], r[N], d[N], u[N];
int n;
int nax;
int get(int tl, int tr, int tp) {
  if (tp == L) return l[tr] - l[tl - 1];
  if (tp == R) return r[tr] - r[tl - 1];
  if (tp == U) return u[tr] - u[tl - 1];
  if (tp == D) return d[tr] - d[tl - 1];
}
struct divan {
  int x1, x2, y1, y2;
  divan(int _x1, int _x2, int _y1, int _y2)
      : x1(_x1), x2(_x2), y1(_y1), y2(_y2) {}
};
vector<divan> a;
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  cin >> n;
  cin >> nax >> nax;
  int x1, x2, y1, y2;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    r[x2]++;
    l[x1]++;
    u[y1]++;
    d[y2]++;
    a.emplace_back(x1, x2, y1, y2);
  }
  for (int i = 1; i < N; i++) {
    l[i] += l[i - 1];
    r[i] += r[i - 1];
    d[i] += d[i - 1];
    u[i] += u[i - 1];
  }
  int c1, c2, c3, c4;
  cin >> c1 >> c2 >> c3 >> c4;
  int ans = -2;
  for (int i = 0; i < n; i++) {
    x1 = a[i].x1;
    x2 = a[i].x2;
    y1 = a[i].y1;
    y2 = a[i].y2;
    int v1 = get(1, x2 - 1, L), v2 = get(x1 + 1, N - 1, R),
        v3 = get(1, y2 - 1, U), v4 = get(y1 + 1, N - 1, D);
    if (x1 < x2)
      v1--, v2--;
    else if (y1 < y2)
      v3--, v4--;
    if (v1 == c1 && v2 == c2 && v3 == c3 && v4 == c4) ans = i;
  }
  cout << ans + 1;
  return 0;
}
