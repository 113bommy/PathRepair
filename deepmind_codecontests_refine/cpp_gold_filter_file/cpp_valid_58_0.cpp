#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
using namespace std;
struct edge {
  long long to, cost;
  edge() {}
  edge(long long a, long long b) { to = a, cost = b; }
};
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int mod = 998244353;
struct mint {
  int x;
  mint(long long y = 0) {
    x = y;
    if (x < 0 || x >= mod) x = (x % mod + mod) % mod;
  }
  mint(const mint& ope) { x = ope.x; }
  mint operator-() { return mint(-x); }
  mint operator+(const mint& ope) { return mint(x) += ope; }
  mint operator-(const mint& ope) { return mint(x) -= ope; }
  mint operator*(const mint& ope) { return mint(x) *= ope; }
  mint operator/(const mint& ope) { return mint(x) /= ope; }
  mint& operator+=(const mint& ope) {
    x += ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint& ope) {
    x += mod - ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint& ope) {
    long long tmp = x;
    tmp *= ope.x, tmp %= mod;
    x = tmp;
    return *this;
  }
  mint& operator/=(const mint& ope) {
    long long n = mod - 2;
    mint mul = ope;
    while (n) {
      if (n & 1) *this *= mul;
      mul *= mul;
      n >>= 1;
    }
    return *this;
  }
  mint inverse() { return mint(1) / *this; }
  bool operator==(const mint& ope) { return x == ope.x; }
  bool operator!=(const mint& ope) { return x != ope.x; }
  bool operator<(const mint& ope) { return x < ope.x; }
};
mint modpow(mint a, long long n) {
  if (n == 0) return mint(1);
  if (n % 2)
    return a * modpow(a, n - 1);
  else
    return modpow(a * a, n / 2);
}
istream& operator>>(istream& is, mint& ope) {
  long long t;
  is >> t, ope.x = t;
  return is;
}
ostream& operator<<(ostream& os, mint& ope) { return os << ope.x; }
ostream& operator<<(ostream& os, const mint& ope) { return os << ope.x; }
vector<mint> fact, fact_inv;
void make_fact(int n) {
  fact.resize(n + 1), fact_inv.resize(n + 1);
  fact[0] = mint(1);
  for (long long i = (1); (i) <= (n); (i)++) fact[i] = fact[i - 1] * mint(i);
  fact_inv[n] = fact[n].inverse();
  for (long long i = (n - 1); (i) >= (0); (i)--)
    fact_inv[i] = fact_inv[i + 1] * mint(i + 1);
}
mint comb(int n, int k) {
  if (n < 0 || k < 0 || n < k) return mint(0);
  return fact[n] * fact_inv[k] * fact_inv[n - k];
}
mint perm(int n, int k) { return comb(n, k) * fact[k]; }
vector<int> prime, pvec;
void make_prime(int n) {
  prime.resize(n + 1);
  for (long long i = (2); (i) <= (n); (i)++) {
    if (prime[i]) continue;
    for (int j = i; j <= n; j += i) prime[j] = i;
  }
  for (long long i = (2); (i) <= (n); (i)++)
    if (prime[i] == i) pvec.push_back(i);
}
bool exceed(long long x, long long y, long long m) { return x >= m / y + 1; }
void mark() { cout << "*" << endl; }
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
long long sgn(long long x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long digitnum(long long x, long long b = 10) {
  long long ret = 0;
  for (; x; x /= b) ret++;
  return ret;
}
long long digitsum(long long x, long long b = 10) {
  long long ret = 0;
  for (; x; x /= b) ret += x % b;
  return ret;
}
string lltos(long long x) {
  string ret;
  for (; x; x /= 10) ret += x % 10 + '0';
  reverse(ret.begin(), ret.end());
  return ret;
}
long long stoll(string& s) {
  long long ret = 0;
  for (auto c : s) ret *= 10, ret += c - '0';
  return ret;
}
template <typename T>
void uniq(T& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
template <class S, class T>
pair<S, T>& operator+=(pair<S, T>& s, const pair<S, T>& t) {
  s.first += t.first, s.second += t.second;
  return s;
}
template <class S, class T>
pair<S, T>& operator-=(pair<S, T>& s, const pair<S, T>& t) {
  s.first -= t.first, s.second -= t.second;
  return s;
}
template <class S, class T>
pair<S, T> operator+(const pair<S, T>& s, const pair<S, T>& t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T>& s, const pair<S, T>& t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T>& deq) {
  for (int i = 0; i < deq.size(); i++)
    os << deq[i] << (i + 1 == deq.size() ? "" : " ");
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
  for (typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end();
       itr++) {
    os << "(" << itr->first << ", " << itr->second << ")";
    itr++;
    if (itr != map_var.end()) os << ",";
    itr--;
  }
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
  for (typename set<T>::iterator itr = set_var.begin(); itr != set_var.end();
       itr++) {
    os << *itr;
    ++itr;
    if (itr != set_var.end()) os << " ";
    itr--;
  }
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, multiset<T>& set_var) {
  for (typename multiset<T>::iterator itr = set_var.begin();
       itr != set_var.end(); itr++) {
    os << *itr;
    ++itr;
    if (itr != set_var.end()) os << " ";
    itr--;
  }
  return os;
}
template <typename T>
void outa(T a[], long long s, long long t) {
  for (long long i = (s); (i) <= (t); (i)++) {
    cout << a[i];
    if (i < t) cout << " ";
  }
  cout << endl;
}
void dump_func() { cout << endl; }
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail) > 0) cout << " ";
  dump_func(std::move(tail)...);
}
struct BIT {
  long long Ident() { return 0; }
  long long ope(long long a, long long b) { return a + b; }
  int size;
  vector<long long> bit;
  BIT() { size = 0; }
  BIT(int s) {
    size = s;
    bit.resize(size + 2);
    init();
  }
  void init() {
    for (int i = 1; i <= size + 1; i++) bit[i] = Ident();
  }
  long long query(int i) {
    i++;
    long long ret = 0;
    while (i > 0) {
      ret = ope(ret, bit[i]);
      i -= i & (-i);
    }
    return ret;
  }
  long long query(int l, int r) { return query(r) - query(l - 1); }
  void add(int i, long long x) {
    i++;
    while (i <= size + 1) {
      bit[i] = ope(bit[i], x);
      i += i & (-i);
    }
  }
};
struct LazySegTree {
  int size;
  vector<long long> seg;
  vector<long long> delay;
  LazySegTree() {}
  LazySegTree(int size) {
    this->size = size;
    seg.resize(1 << (size + 1));
    delay.resize(1 << (size + 1));
  }
  long long Ident() { return -1e18; }
  long long ope(long long a, long long b) { return max(a, b); }
  void init() {
    for (int i = 0; i < (1 << (size + 1)); i++) {
      seg[i] = Ident();
      delay[i] = 0;
    }
  }
  void eval(int l, int r, int k) {
    if (delay[k]) {
      seg[k] += delay[k];
      if (l < r) {
        delay[k * 2] += delay[k];
        delay[k * 2 + 1] += delay[k];
      }
      delay[k] = 0;
    }
  }
  void update(int i, long long val) {
    int l = 0, r = (1 << size) - 1, k = 1;
    eval(l, r, k);
    for (int j = size - 1; j >= 0; j--) {
      k <<= 1;
      if (i & (1 << j)) {
        k++;
        l = (l + r) / 2 + 1;
      } else
        r = (l + r) / 2;
      eval(l, r, k);
    }
    seg[i + (1 << size)] = val;
    l = i, r = i, k = i + (1 << size);
    for (int j = 0; j < size; j++) {
      k /= 2, l &= ~(1 << j), r |= 1 << j;
      eval(l, (l + r) / 2, k * 2), eval((l + r) / 2 + 1, r, k * 2 + 1);
      seg[k] = ope(seg[k * 2], seg[k * 2 + 1]);
    }
  }
  void add(int a, int b, int k, int l, int r, long long val) {
    eval(l, r, k);
    if (b < l || r < a) return;
    if (a <= l && r <= b) {
      delay[k] += val;
      eval(l, r, k);
      return;
    }
    add(a, b, k * 2, l, (l + r) / 2, val);
    add(a, b, k * 2 + 1, (l + r) / 2 + 1, r, val);
    seg[k] = ope(seg[k * 2], seg[k * 2 + 1]);
  }
  void add(int a, int b, long long val) {
    if (a > b) return;
    add(a, b, 1, 0, (1 << size) - 1, val);
  }
  long long query(int a, int b, int k, int l, int r) {
    eval(l, r, k);
    if (b < l || r < a) return Ident();
    if (a <= l && r <= b) return seg[k];
    long long lval = query(a, b, k * 2, l, (l + r) / 2);
    long long rval = query(a, b, k * 2 + 1, (l + r) / 2 + 1, r);
    return ope(lval, rval);
  }
  long long query(int a, int b) {
    if (a > b) return Ident();
    return query(a, b, 1, 0, (1 << size) - 1);
  }
};
long long long long;
long long n, m;
long long x[200005], y[200005], p[200005];
BIT bit(200005);
long long get(long long x) {
  long long ub = 200000, lb = 0, mid;
  while (ub - lb > 1) {
    mid = (ub + lb) / 2;
    if (bit.query(mid) >= x)
      ub = mid;
    else
      lb = mid;
  }
  return ub;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  make_fact(600005);
  for (long long i = (1); (i) <= (200000); (i)++) bit.add(i, 1);
  cin >> long long;
  while (long long --) {
    cin >> n >> m;
    for (long long i = (1); (i) <= (m); (i)++) cin >> x[i] >> y[i];
    set<long long> S;
    vector<long long> vec;
    for (long long i = (m); (i) >= (1); (i)--) {
      long long p = get(y[i]), q = get(y[i] + 1);
      bit.add(p, -1);
      S.insert(q);
      vec.push_back(p);
    }
    for (auto x : vec) bit.add(x, 1);
    mint ans = comb(2 * n - 1 - ((long long)(S).size()), n);
    cout << ans << "\n";
  }
  return 0;
}
