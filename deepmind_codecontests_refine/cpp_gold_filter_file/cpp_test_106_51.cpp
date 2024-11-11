#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1 << 30;
constexpr long long llinf = 1LL << 62;
constexpr int mod = 1000000007;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
inline int popcount(ll x) { return __builtin_popcountll(x); }
inline int div2num(ll x) { return __builtin_ctzll(x); }
inline bool bit(ll x, int b) { return (x >> b) & 1; }
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
string to_string(T s);
template <class S, class T>
string to_string(pair<S, T> p);
string to_string(char c) { return string(1, c); }
string to_string(string s) { return s; }
string to_string(const char s[]) { return string(s); }
template <class T>
string to_string(T v) {
  if (v.empty()) return "{}";
  string ret = "{";
  for (auto x : v) ret += to_string(x) + ",";
  ret.back() = '}';
  return ret;
}
template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + ":" + to_string(p.second) + "}";
}
void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}
template <class T>
vector<T> makev(int n, T v) {
  return vector<T>(n, v);
}
struct IO {
  std::string separator = " ";
  template <class T>
  inline void read(T& x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c != '-' && (c < '0' || '9' < c));
    bool minus = 0;
    if (c == '-') {
      minus = 1;
      c = getchar_unlocked();
    }
    x = 0;
    while ('0' <= c && c <= '9') {
      x *= 10;
      x += c - '0';
      c = getchar_unlocked();
    }
    if (minus) x = -x;
  }
  inline void read(std::string& x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c == ' ' || c == '\n');
    x.clear();
    do {
      x += c;
      c = getchar_unlocked();
    } while (c != ' ' && c != '\n' && c != EOF);
  }
  template <class T>
  inline void read(std::vector<T>& v) {
    for (auto& x : v) read(x);
  }
  template <class S, class T>
  inline void read(std::pair<S, T>& p) {
    read(p.first);
    read(p.second);
  }
  template <class Head, class... Tail>
  inline void read(Head& head, Tail&... tail) {
    read(head);
    read(tail...);
  }
  template <class T>
  inline void write(T x) {
    char buf[32];
    int p = 0;
    if (x < 0) {
      x = -x;
      putchar_unlocked('-');
    }
    if (x == 0) putchar_unlocked('0');
    while (x > 0) {
      buf[p++] = (x % 10) + '0';
      x /= 10;
    }
    while (p) {
      putchar_unlocked(buf[--p]);
    }
  }
  inline void write(std::string x) {
    for (char c : x) putchar_unlocked(c);
  }
  inline void write(const char s[]) {
    for (int i = 0; s[i] != 0; ++i) putchar_unlocked(s[i]);
  }
  template <class T>
  inline void write(std::vector<T> v) {
    if (v.empty()) return;
    for (auto itr = v.begin(); itr + 1 != v.end(); ++itr) {
      write(*itr);
      write(separator);
    }
    write(v.back());
  }
  template <class Head, class... Tail>
  inline void write(Head head, Tail... tail) {
    write(head);
    write(separator);
    write(tail...);
  }
  template <class Head, class... Tail>
  inline void writeln(Head head, Tail... tail) {
    write(head, tail...);
    write("\n");
  }
  void set_separator(std::string s) { separator = s; }
} io;
struct Prime {
  int n;
  vector<int> table;
  vector<int> primes;
  Prime(int _n = 100000) {
    n = _n + 1;
    table.resize(n, -1);
    table[0] = 0;
    table[1] = -1;
    for (int i = 2; i * i < n; ++i) {
      if (table[i] == -1) {
        for (int j = i * i; j < n; j += i) {
          table[j] = i;
        }
      }
    }
  }
  void enumerate_primes() {
    primes.clear();
    for (int i = 2; i < n; ++i) {
      if (table[i] == -1) primes.push_back(i);
    }
  }
  vector<pair<long long, int>> prime_factor(long long x) {
    map<long long, int> mp;
    long long div = 2;
    int p = 0;
    while (n <= x && div * div <= x) {
      if (x % div == 0) {
        mp[div]++;
        x /= div;
      } else {
        if (p + 1 < primes.size()) {
          div = primes[++p];
        } else {
          div++;
        }
      }
    }
    if (x < n) {
      while (table[x] != -1) {
        mp[table[x]]++;
        x /= table[x];
      }
    }
    if (x > 1) mp[x]++;
    vector<pair<long long, int>> ret;
    for (auto p : mp) ret.push_back(p);
    return ret;
  }
};
template <int MOD = 1000000007>
struct Math {
  vector<long long> fact, factinv, inv;
  Math(int n = 100000) {
    fact.resize(n + 1);
    factinv.resize(n + 1);
    inv.resize(n + 1);
    fact[0] = fact[1] = 1;
    factinv[0] = factinv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      factinv[i] = factinv[i - 1] * inv[i] % MOD;
    }
  }
  long long C(int n, int r) {
    if (n < r || n < 0 || r < 0) {
      return 0;
    } else {
      return fact[n] * (factinv[r] * factinv[n - r] % MOD) % MOD;
    }
  }
  long long P(int n, int r) {
    if (n < r || n < 0 || r < 0) {
      return 0;
    } else {
      return fact[n] * factinv[n - r] % MOD;
    }
  }
  long long H(int n, int r) { return C(n + r - 1, r); }
};
struct UnionFind {
  vector<int> data;
  vector<vector<int>> groups;
  UnionFind(int n) : data(n, -1) {}
  int root(int v) { return data[v] < 0 ? v : data[v] = root(data[v]); }
  bool unite(int u, int v) {
    if ((u = root(u)) == (v = root(v))) {
      return 1;
    } else {
      if (-data[u] < -data[v]) swap(u, v);
      data[u] += data[v];
      data[v] = u;
      return 0;
    }
  }
  int size(int v) { return -data[root(v)]; }
  void make_groups() {
    map<int, vector<int>> mp;
    for (int i = 0; i < data.size(); ++i) mp[root(i)].push_back(i);
    groups.clear();
    for (auto p : mp) groups.push_back(p.second);
  }
};
namespace phc {
long long modpow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
long long modinv(long long a) {
  long long b = mod, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= mod;
  if (u < 0) u += mod;
  return u;
}
long long gcd(long long a, long long b) { return b != 0 ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
}  // namespace phc
template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt& operator+=(const ModInt& p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt& operator-=(const ModInt& p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt& operator*=(const ModInt& p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt& operator/=(const ModInt& p) {
    *this *= p.inverse();
    return *this;
  }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream& operator<<(ostream& os, const ModInt& p) { return os << p.x; }
  friend istream& operator>>(istream& is, ModInt& a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int get_mod() { return mod; }
};
using modint = ModInt<mod>;
int main() {
  int t;
  io.read(t);
  Prime prime(20000);
  prime.enumerate_primes();
  while (t--) {
    int n;
    io.read(n);
    vector<int> ans;
    for (int i = 1; i < (int)n + 1; i++) ans.push_back(prime.primes[i]);
    io.writeln(ans);
  }
  return 0;
}
