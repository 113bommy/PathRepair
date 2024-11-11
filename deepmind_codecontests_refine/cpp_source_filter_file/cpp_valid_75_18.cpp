#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000005;
const long long SQRTN = 1003;
const long long LOGN = 22;
const double PI = acos(-1);
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long FMOD = 998244353;
const double eps = 1e-9;
void __print(long long x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  long long f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
long long add(long long a, long long b, long long c = MOD) {
  long long res = a + b;
  return (res >= c ? res % c : res);
}
long long sub(long long a, long long b, long long c = MOD) {
  long long res;
  if (abs(a - b) < c)
    res = a - b;
  else
    res = (a - b) % c;
  return (res < 0 ? res + c : res);
}
long long mul(long long a, long long b, long long c = MOD) {
  long long res = (long long)a * b;
  return (res >= c ? res % c : res);
}
long long muln(long long a, long long b, long long c = MOD) {
  long long res = (long long)a * b;
  return ((res % c) + c) % c;
}
long long mulmod(long long a, long long b, long long m = MOD) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T>
T binpow(T e, T n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T binpow2(T e, T n, T m = MOD) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mul(x, p, m);
    p = mul(p, p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b) {
    T q = a / b, t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}
template <typename T>
T mod_inverse(T a, T n = MOD) {
  T x, y, z = 0;
  T d = extended_euclid(a, n, x, y);
  return (d > 1 ? -1 : sub(x, z, n));
}
const long long FACSZ = 1e4;
long long fact[FACSZ], ifact[FACSZ];
void precom(long long c = MOD) {
  fact[0] = 1;
  for (long long i = 1; i < FACSZ; i++) fact[i] = mul(fact[i - 1], i, c);
  ifact[FACSZ - 1] = mod_inverse(fact[FACSZ - 1], c);
  for (long long i = FACSZ - 1 - 1; i >= 0; i--) {
    ifact[i] = mul(i + 1, ifact[i + 1], c);
  }
}
vector<long long> primes;
void prime_precom() {
  primes.push_back(2);
  for (long long x = 3; primes.size() <= MAXN; x += 2) {
    bool isPrime = true;
    for (auto p : primes) {
      if (x % p == 0) {
        isPrime = false;
        break;
      }
      if (p * p > x) {
        break;
      }
    }
    if (isPrime) {
      primes.push_back(x);
    }
  }
}
long long ncr(long long n, long long k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long ncr_modp(long long n, long long k, long long c = MOD) {
  if (n < k) return 0;
  if (k == 0) return 1;
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res = mul(res, n - i, c);
    res = mul(res, binpow2(i + 1, c - 2, c), c);
  }
  return res;
}
vector<long long> factors;
void factorize(long long a) {
  factors.clear();
  for (long long i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      factors.push_back(i);
      factors.push_back(a / i);
    }
  }
  sort(factors.begin(), factors.end());
}
long long ncr_precom(long long n, long long r, long long c = MOD) {
  return mul(mul(ifact[r], ifact[n - r], c), fact[n], c);
}
long long ceil(long long a, long long b) { return (a + b - 1) / b; }
bool is_prime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
bool diophantine_checker(long long a, long long b, long long n) {
  for (long long i = 0; i * a <= n; i++) {
    if ((n - (i * a)) % b == 0) {
      return true;
    }
  }
  return false;
}
long long count_divisors(long long n) {
  long long c;
  long long ans = 1;
  for (long long i = 2; i * i <= n; i++) {
    c = 0;
    while (n % i == 0) {
      c++;
      n /= i;
    }
    ans *= (c + 1);
  }
  if (n > 2) {
    return ans * 2;
  }
  return ans;
}
string to_binary(long long n) {
  string r;
  while (n != 0) {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n /= 2;
  }
  return r;
}
bool ispower2(long long x) { return x && (!(x & (x - 1))); }
unsigned long long mulmodBitwise(unsigned long long a, unsigned long long b,
                                 unsigned long long p) {
  a %= p;
  b %= p;
  if (a <= 0xFFFFFFF && b <= 0xFFFFFFF) {
    return (a * b) % p;
  }
  if (b > a) {
    swap(a, b);
  }
  unsigned long long result = 0;
  while (a > 0 && b > 0) {
    if (b & 1) {
      result += a;
      result %= p;
    }
    a <<= 1;
    a %= p;
    b >>= 1;
  }
  return result;
}
unsigned long long mulmod2(unsigned long long a, unsigned long long b,
                           unsigned long long p) {
  a %= p;
  b %= p;
  if (a <= 0xFFFFFFF && b <= 0xFFFFFFF) {
    return (a * b) % p;
  }
  unsigned long long zeros = 0;
  unsigned long long m = p;
  while ((m & 0x8000000000000000ULL) == 0) {
    zeros++;
    m <<= 1;
  }
  unsigned long long mask = (1 << zeros) - 1;
  unsigned long long result = 0;
  while (a > 0 && b > 0) {
    result += (b & mask) * a;
    result %= p;
    b >>= zeros;
    a <<= zeros;
    a %= p;
  }
  return result;
}
unsigned long long powmod(unsigned long long base, unsigned long long exponent,
                          unsigned long long p) {
  unsigned long long result = 1;
  while (exponent > 0) {
    if (exponent & 1) {
      result = mulmod2(result, base, p);
    }
    base = mulmod2(base, base, p);
    exponent >>= 1;
  }
  return result;
}
vector<long long> spf;
void sieve() {
  spf.resize(MAXN);
  spf[1] = 1;
  for (long long i = 2; i < MAXN; i++) {
    spf[i] = i;
  }
  for (long long i = 4; i < MAXN; i += 2) {
    spf[i] = 2;
  }
  for (long long i = 3; i * i <= MAXN; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j < MAXN; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}
void pfactor(long long x, vector<long long> &ret) {
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
}
void solvethetestcase() {
  long long n;
  cin >> n;
  vector<vector<long long> > v(n);
  map<long long, vector<long long> > make_pair;
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    long long mx = -1;
    for (long long j = 0; j < k; j++) {
      long long x;
      cin >> x;
      v[i].push_back(x);
      mx = max(mx, x);
    }
    make_pair[mx].push_back(i);
  };
  vector<long long> id;
  for (auto x : make_pair) {
    for (auto z : x.second) {
      id.push_back(z);
    }
  }
  vector<vector<long long> > order;
  for (auto x : id) {
    order.push_back(v[x]);
  };
  long long l = 0, r = 1e12;
  while (r - l > 3) {
    long long md = (l + r) / 2;
    long long cur = md;
    bool b = 1;
    for (auto x : order) {
      for (auto z : x) {
        if (z >= cur) {
          b = 0;
          break;
        } else {
          cur++;
        }
      }
      if (!b) {
        break;
      }
    }
    if (b) {
      r = md;
    } else {
      l = md + 1;
    }
  }
  for (long long i = l; i <= r; i++) {
    bool b = 1;
    long long cur = i;
    for (auto x : order) {
      for (auto z : x) {
        if (z >= cur) {
          b = 0;
          break;
        } else {
          cur++;
        }
      }
      if (!b) {
        break;
      }
    }
    if (b) {
      cout << i << "\n";
      return;
    }
  }
}
signed main() {
  cout << fixed << setprecision(12);
  ;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long testcase = 1; testcase < t + 1; testcase++) {
    solvethetestcase();
  }
}
