#include <bits/stdc++.h>
using namespace std;
const long long INF(0x3f3f3f3f3f3f3f3fll);
const long long inf(0x3f3f3f3f);
template <typename T>
void read(T &res) {
  bool flag = false;
  char ch;
  while (!isdigit(ch = getchar())) (ch == '-') && (flag = true);
  for (res = ch - 48; isdigit(ch = getchar());
       res = (res << 1) + (res << 3) + ch - 48)
    ;
  flag && (res = -res);
}
template <typename T>
void Out(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) Out(x / 10);
  putchar(x % 10 + '0');
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long pow_mod(long long x, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long fact_pow(long long n, long long p) {
  long long res = 0;
  while (n) {
    n /= p;
    res += n;
  }
  return res;
}
long long mult(long long a, long long b, long long p) {
  a %= p;
  b %= p;
  long long r = 0, v = a;
  while (b) {
    if (b & 1) {
      r += v;
      if (r > p) r -= p;
    }
    v <<= 1;
    if (v > p) v -= p;
    b >>= 1;
  }
  return r;
}
long long quick_pow(long long a, long long b, long long p) {
  long long r = 1, v = a % p;
  while (b) {
    if (b & 1) r = mult(r, v, p);
    v = mult(v, v, p);
    b >>= 1;
  }
  return r;
}
bool CH(long long a, long long n, long long x, long long t) {
  long long r = quick_pow(a, x, n);
  long long z = r;
  for (long long i = 1; i <= t; i++) {
    r = mult(r, r, n);
    if (r == 1 && z != 1 && z != n - 1) return true;
    z = r;
  }
  return r != 1;
}
bool Miller_Rabin(long long n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (!(n & 1)) return false;
  long long x = n - 1, t = 0;
  while (!(x & 1)) {
    x >>= 1;
    t++;
  }
  srand(time(NULL));
  long long o = 8;
  for (long long i = 0; i < o; i++) {
    long long a = rand() % (n - 1) + 1;
    if (CH(a, n, x, t)) return false;
  }
  return true;
}
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, x, y);
  long long t = x;
  x = y, y = t - (a / b) * y;
}
long long inv(long long a, long long b) {
  long long x, y;
  return exgcd(a, b, x, y), (x % b + b) % b;
}
long long crt(long long x, long long p, long long mod) {
  return inv(p / mod, mod) * (p / mod) * x;
}
long long fac(long long x, long long a, long long b) {
  if (!x) return 1;
  long long ans = 1;
  for (long long i = 1; i <= b; i++)
    if (i % a) ans *= i, ans %= b;
  ans = pow_mod(ans, x / b, b);
  for (long long i = 1; i <= x % b; i++)
    if (i % a) ans *= i, ans %= b;
  return ans * fac(x / a, a, b) % b;
}
long long C(long long n, long long m, long long a, long long b) {
  long long N = fac(n, a, b), M = fac(m, a, b), Z = fac(n - m, a, b), sum = 0,
            i;
  for (i = n; i; i = i / a) sum += i / a;
  for (i = m; i; i = i / a) sum -= i / a;
  for (i = n - m; i; i = i / a) sum -= i / a;
  return N * pow_mod(a, sum, b) % b * inv(M, b) % b * inv(Z, b) % b;
}
long long exlucas(long long n, long long m, long long p) {
  long long t = p, ans = 0, i;
  for (i = 2; i * i <= p; i++) {
    long long k = 1;
    while (t % i == 0) {
      k *= i, t /= i;
    }
    ans += crt(C(n, m, i, k), p, k), ans %= p;
  }
  if (t > 1) ans += crt(C(n, m, t, t), p, t), ans %= p;
  return ans % p;
}
const long long N = 2e5 + 10;
char ans[N];
signed main() {
  std::ios::sync_with_stdio(false);
  for (long long i = 1; i <= 300; i++) ans[i] = 'a';
  long long cnta, cntb, t = 1;
  for (long long i = 1; i <= 300; i++) cout << 'a';
  cout << '\n';
  cin >> cnta;
  cnta = 300 - cnta;
  for (long long i = 1; i <= 300; i++) cout << 'b';
  cout << '\n';
  cin >> cntb;
  cntb = 300 - cntb;
  if (!cnta) {
    for (long long i = 1; i <= cntb; i++) cout << 'b';
    return cout << '\n', 0;
  } else if (!cntb) {
    for (long long i = 1; i <= cnta; i++) cout << 'a';
    return cout << '\n', 0;
  }
  long long n = cnta + cntb;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) i == j ? cout << 'b' : cout << ans[j];
    cout << '\n';
    cout.flush();
    long long x;
    cin >> x;
    if (x < cntb)
      ans[i] = 'b';
    else
      ans[i] = 'a';
    if (!x) return cout << '\n', 0;
  }
  return 0;
}
