#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lli = long long int;
using ull = unsigned long long;
using uli = unsigned long long int;
using ld = long double;
using db = double;
using ii = pair<int, int>;
using iii = pair<ii, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using si = pair<int, string>;
using ti = tuple<int, int, int>;
using tll = tuple<ll, ll, ll>;
using tld = tuple<ld, ld, ld>;
using vi = vector<int>;
using vd = vector<ld>;
using vl = vector<ll>;
using vii = vector<ii>;
using vpl = vector<pl>;
using vc = vector<char>;
using vs = vector<string>;
using mii = unordered_map<int, int>;
using mll = map<ll, ll>;
using mci = map<char, int>;
using msi = map<string, int>;
using mss = map<string, string>;
int primes[101];
const int N = 1e5 + 24;
const int M = 5024;
const int inf = 1e9;
const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0};
const int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1},
          dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const long long INF = 1e18;
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;
enum state { unvisited, visited, explored };
set<char> vowel = {'A', 'O', 'Y', 'E', 'U', 'I', 'a', 'o', 'y', 'e', 'u', 'i'};
string to_binary(ll x) { return bitset<64>(x).to_string(); }
bool comp(const string a, const string b) { return a + b < b + a; }
ld dist(ld x, ld y, ld a, ld b) {
  return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll fact(long long n) { return n > 1 ? (n * fact(n - 1)) : 1; }
void prime() {
  for (int k = 0; k < 101; k++) {
    primes[k] = 1;
  }
  primes[1] = 0;
  for (int k = 2; k < 101; k++) {
    if (primes[k]) {
      for (int j = 2 * k; j < 101; j += k) {
        primes[j] = 0;
      }
    }
  }
}
void IO() {}
class UnionFind {
 private:
  vi parents, sizes;

 public:
  UnionFind(int N) {
    sizes.assign(N, 1);
    parents.assign(N, 0);
    for (int i = 0; i < N; i++) parents[i] = i;
  }
  int findSet(int i) {
    return (i == parents[i]) ? i : (parents[i] = findSet(parents[i]));
  }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void UnionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (sizes[x] < sizes[y]) swap(x, y);
      sizes[x] += sizes[y];
      parents[y] = x;
    }
  }
};
struct SegmentTree {
  int sizes;
  vl st, a;
  void init(int n) {
    sizes = 1;
    while (sizes < n) sizes *= 2;
    st.assign(sizes * 4, 0LL);
  }
  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  void build(int p, int L, int R) {
    if (L == R) {
      if (L < ((int)a.size())) st[p] = a[L];
    } else {
      int mid = (L + R) / 2;
      build(left(p), L, mid);
      build(right(p), mid + 1, R);
      st[p] = st[left(p)] + st[right(p)];
    }
  }
  void update(int p, int L, int R, int i, int j) {
    if (L == R)
      st[p] = j;
    else {
      int mid = (L + R) / 2;
      if (i <= mid)
        update(left(p), L, mid, i, j);
      else
        update(right(p), mid + 1, R, i, j);
      st[p] = st[left(p)] + st[right(p)];
    }
  }
  long long query(int p, int L, int R, int i, ll j) {
    if (L > j || R < i) return 0LL;
    if (L >= i && R <= j) return st[p];
    ll p1 = query(left(p), L, (L + R) / 2, i, j);
    ll p2 = query(right(p), (L + R) / 2 + 1, R, i, j);
    return p1 + p2;
  }
  void build(vl& _a) {
    a = _a;
    build(1, 0, sizes - 1);
  }
  void update(int i, int j) { update(1, 0, sizes - 1, i, j); }
  long long query(int i, int j) { return query(1, 0, sizes - 1, i, j); }
};
void solve() {
  int n, m, k;
  cin >> n >> m;
  vl c, t;
  ll ans = 0;
  for (int l = 0; l < n; l++) {
    cin >> k;
    c.push_back(k);
  }
  for (int i = 0; i < m; i++) {
    cin >> k;
    t.push_back(k);
  }
  int lo, hi;
  int l = 0, r = 0;
  for (auto u : c) {
    lo = -1;
    hi = m;
    while (lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      if (t[mid] <= u) {
        lo = mid;
      } else
        hi = mid;
    }
    l = lo;
    lo = -1;
    hi = m;
    ll d = -1;
    while (lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      if (t[mid] >= u) {
        hi = mid;
      } else
        lo = m;
    }
    r = hi;
    if (r < m) d = max(d, abs(u - t[r]));
    if (l != -1 && d > 0) {
      d = min(d, abs(u - t[l]));
    } else if (l != -1 && d < 0)
      d = abs(u - t[l]);
    ans = max(ans, d);
  }
  cout << ans << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  IO();
  solve();
  return 0;
}
