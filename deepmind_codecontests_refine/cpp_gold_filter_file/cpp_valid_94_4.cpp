#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
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
  int f = 0;
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
const int N = 2e5 + 1;
long long fact[N], inv[N], invfact[N];
vector<int> primes, lpf;
void sieve(int n) {
  primes.assign(1, 2);
  lpf.assign(n + 1, 2);
  for (int x = 3; x <= n; x += 2) {
    if (lpf[x] == 2) primes.push_back(lpf[x] = x);
    for (int i = 0;
         i < primes.size() && primes[i] <= lpf[x] && primes[i] * x <= n; ++i)
      lpf[primes[i] * x] = primes[i];
  }
}
long long mul(long long a, long long b, const long long MOD = 1000000007) {
  long long res = 0;
  for (a %= MOD; b > 0; a <<= 1, b >>= 1) {
    if (a >= MOD) a -= MOD;
    if (b & 1) {
      res += a;
      if (res >= MOD) res -= MOD;
    }
  }
  return res;
}
long long power(long long x, long long n, const long long MOD = 1000000007) {
  long long res = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) res = mul(res, x, MOD);
    x = mul(x, x, MOD);
  }
  return res;
}
bool mr_test(long long n, int a, long long d, int s) {
  long long x = power(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (int r = 1; r < s; ++r) {
    x = mul(x, x, n);
    if (x == n - 1) return false;
  }
  return true;
}
bool miller_rabin(long long n, int k = 5) {
  if (n < 4) return n == 2 || n == 3;
  if (n % 2 == 0 || n % 3 == 0) return false;
  int s = __builtin_ctz(n - 1);
  long long d = (n - 1) >> s;
  for (int it = 1; it <= 5; ++it) {
    int a = 2 + rand() % (n - 3);
    if (mr_test(n, a, d, s)) return false;
  }
  return true;
}
bool isPrime(long long n) {
  if (n < 2) return false;
  if (n < lpf.size()) return lpf[n] == n;
  return miller_rabin(n);
}
long long div(long long n) {
  long long ans = 1;
  for (int i = 0; i < primes.size(); i++) {
    if (primes[i] * primes[i] * primes[i] > n) break;
    long long cnt = 1;
    while (n % primes[i] == 0) {
      n /= primes[i];
      cnt++;
    }
    ans = ans * cnt;
  }
  long long x = round(sqrt(n));
  if (isPrime(n))
    ans *= 2;
  else if (x * x == n) {
    if (isPrime(x)) ans *= 3;
  } else
    ans *= 4;
  return ans;
}
int log_(int a, int b) { return (a > b - 1) ? 1 + log_(a / b, b) : 0; }
long long add(long long a, long long b, long long Mod = 1000000007) {
  if ((a += b) >= Mod)
    a -= Mod;
  else if (a < 0)
    a += Mod;
  return a;
}
long long nCr(int n, int r) {
  if (r > n) return 0;
  return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
void factInverse() {
  fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
  for (long long i = 2; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
    inv[i] = 1000000007 - (inv[1000000007 % i] * (1000000007 / i) % 1000000007);
    invfact[i] = (inv[i] * invfact[i - 1]) % 1000000007;
  }
}
void solve(int K) {
  long long n, m, q, z, k;
  long long ans = 0, cnt = 0;
  long long a, b, c;
  long long x, y;
  long long l{-1}, r{-1};
  string s;
  string t;
  cin >> n;
  if (n < 10) {
    cout << n - 1 << "\n";
    return;
  }
  bitset<11> bit;
  s = to_string(n);
  m = s.size();
  long long tmp = 1;
  y = bit.to_ullong();
  z = 1LL << (m - 2);
  reverse((s).begin(), (s).end());
  while (1) {
    tmp = 1;
    ;
    if (y == (z)) break;
    for (int i = m - 2; i >= 0; i -= 2) {
      if (i == 0 || i == 1) {
        if (bit[i]) {
          tmp *= (9 - (s[i] - '0'));
        } else {
          tmp *= (s[i] - '0' + 1);
        }
        break;
      }
      if (bit[i - 2]) {
        if (bit[i]) {
          tmp *= (9 - (s[i] - '0') + 1);
        } else
          tmp *= (s[i] - '0');
      } else {
        if (bit[i]) {
          tmp *= (9 - (s[i] - '0'));
        } else
          tmp *= (s[i] - '0' + 1);
      }
    }
    for (int i = m - 1; i >= 0; i -= 2) {
      if (i == 0 || i == 1) {
        if (bit[i]) {
          tmp *= (9 - (s[i] - '0'));
        } else {
          tmp *= (s[i] - '0' + 1);
        }
        break;
      }
      if (bit[i - 2]) {
        if (bit[i]) {
          tmp *= (9 - (s[i] - '0') + 1);
        } else
          tmp *= (s[i] - '0');
      } else {
        if (bit[i]) {
          tmp *= (9 - (s[i] - '0'));
        } else
          tmp *= (s[i] - '0' + 1);
      };
    };
    ans += tmp;
    y++;
    bit = y;
  };
  cout << ans - 2 << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, k;
  k = 1;
  t = 1;
  cin >> t;
  while (t--) {
    solve(k);
    k++;
  }
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  cout << flush;
  return 0;
}
