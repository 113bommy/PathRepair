#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  return b == 0 ? a : gcd(b, a % b);
}
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
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long qp(long long a, long long b, long long mod) {
  long long ans = 1;
  if (b == 0) {
    return ans % mod;
  }
  while (b) {
    if (b % 2 == 1) {
      b--;
      ans = ans * a % mod;
    }
    a = a * a % mod;
    b = b / 2;
  }
  return ans % mod;
}
long long qpn(long long a, long long b, long long p) {
  long long ans = 1;
  a %= p;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % p;
      --b;
    }
    a = (a * a) % p;
    b >>= 1;
  }
  return ans % p;
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
      r = (r + v) % p;
      r = (r + p) % p;
    }
    v <<= 1;
    v = (v + p) % p;
    b >>= 1;
  }
  return r % p;
}
long long pow_mod(long long x, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = mult(res, x, mod);
    x = mult(x, x, mod);
    n >>= 1;
  }
  return res;
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
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  long long ans = exgcd(b, a % b, y, x);
  y -= (a / b) * x;
  return ans;
}
long long INV(long long a, long long b) {
  long long x, y;
  return exgcd(a, b, x, y), (x % b + b) % b;
}
long long crt(long long x, long long p, long long mod) {
  return INV(p / mod, mod) * (p / mod) * x;
}
long long FAC(long long x, long long a, long long b) {
  if (!x) return 1;
  long long ans = 1;
  for (long long i = 1; i <= b; i++)
    if (i % a) ans *= i, ans %= b;
  ans = pow_mod(ans, x / b, b);
  for (long long i = 1; i <= x % b; i++)
    if (i % a) ans *= i, ans %= b;
  return ans * FAC(x / a, a, b) % b;
}
long long C(long long n, long long m, long long a, long long b) {
  long long N = FAC(n, a, b), M = FAC(m, a, b), Z = FAC(n - m, a, b), sum = 0,
            i;
  for (i = n; i; i = i / a) sum += i / a;
  for (i = m; i; i = i / a) sum -= i / a;
  for (i = n - m; i; i = i / a) sum -= i / a;
  return N * pow_mod(a, sum, b) % b * INV(M, b) % b * INV(Z, b) % b;
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
long long H(long long x, long long p) {
  long long ans = 0;
  if (x == 0) return 1;
  x = x % (2 * p);
  if (x == 0) x = 2 * p;
  for (long long i = 2; i <= x; ++i)
    ans = (ans * i + (i % 2 == 0 ? 1 : -1)) % p;
  return (ans + p) % p;
}
signed main() {
  long long n;
  read(n);
  long long pre = n;
  long long cnt = 0;
  long long cur;
  if (n == 0) {
    printf("0\n");
    return 0;
  }
  for (long long i = 1; i <= n; i++) {
    cur = (1ll) * sqrt(n * n - i * i);
    if (pre > cur) {
      cnt = cnt + pre - cur;
    } else {
      cnt++;
    }
    pre = cur;
  }
  printf("%lld\n", cnt * 4);
  return 0;
}
