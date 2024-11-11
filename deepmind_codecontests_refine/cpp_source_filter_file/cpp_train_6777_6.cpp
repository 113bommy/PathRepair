#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("sse3", "sse2", "sse")
#pragma GCC target("avx", "sse4", "sse4.1", "sse4.2", "ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", \
                     "no-stack-protector")
using namespace std;
const int block_size = 320;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
const long double eps = 1e-9;
const double PI = atan(1) * 4;
template <typename T>
inline int sign(const T &a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
template <typename T, typename S>
inline bool upmin(T &a, const S &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool upmax(T &a, const S &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline void in(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
long long twop(int x) { return 1LL << x; }
template <typename A, typename B>
inline void in(A &x, B &y) {
  in(x);
  in(y);
}
template <typename A, typename B, typename C>
inline void in(A &x, B &y, C &z) {
  in(x);
  in(y);
  in(z);
}
template <typename A, typename B, typename C, typename D>
inline void in(A &x, B &y, C &z, D &d) {
  in(x);
  in(y);
  in(z);
  in(d);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
namespace SOLVE {
void main() {}
}  // namespace SOLVE
long long num[510];
bool decom[510];
map<long long, long long> cnt;
long long getSqrt(long long x) {
  long long s = sqrt(x);
  for (long long i = s - 10; i < s + 10; i++) {
    if (i > 0)
      if (i * i == x) return i;
  }
  return -1;
}
void EratosthenesSieve(const int n, vector<int> &primes) {
  vector<int> numbers(n + 1);
  for (long long i = 2; i <= n; i++) {
    if (!numbers[i]) {
      primes.push_back(i);
      for (long long j = i * i; j <= n; j += i) numbers[j] = 1;
    }
  }
}
long long mul(long long a, long long b, long long n) {
  return (a * b - (long long)(a / (long double)n * b + 1e-3) * n + n) % n;
}
long long pow(long long a, long long b, long long n) {
  long long d = 1;
  a %= n;
  while (b) {
    if (b & 1) d = mul(d, a, n);
    a = mul(a, a, n);
    b >>= 1;
  }
  return d;
}
bool check(long long a, long long n) {
  long long m = n - 1, x, y;
  int i, j = 0;
  while (!(m & 1)) m >>= 1, j++;
  x = pow(a, m, n);
  for (i = 1; i <= j; x = y, i++) {
    y = pow(x, 2, n);
    if ((y == 1) && (x != 1) && (x != n - 1)) return 1;
  }
  return y != 1;
}
bool miller_rabin(int times, long long n) {
  long long a;
  if (n == 1) return 0;
  if (n == 2) return 1;
  if (!(n & 1)) return 0;
  while (times--)
    if (check(rand() % (n - 1) + 1, n)) return 0;
  return 1;
}
int main() {
  vector<int> primes;
  EratosthenesSieve(1000000, primes);
  int n;
  in(n);
  for (long long i = 0; i < n; i++) {
    in(num[i]);
    for (auto j : primes) {
      if (num[i] % j == 0) {
        while (num[i] % j == 0) {
          num[i] /= j;
          cnt[j]++;
          decom[i] = 1;
        }
      }
    }
    if (num[i] == 1) continue;
    long long root = getSqrt(num[i]);
    if (root != -1) {
      cnt[root] += 2;
      num[i] = 1;
      decom[i] = 1;
      continue;
    }
    if (decom[i]) {
      cnt[num[i]]++;
      num[i] = 1;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      long long g = gcd(num[i], num[j]);
      if (g != 1 && g != num[i]) {
        cnt[num[i] / g]++;
        cnt[g]++;
        num[i] = 1;
        cnt[num[j] / g]++;
        cnt[g]++;
        num[j] = 1;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    if (num[i] != 1) {
      map<long long, long long> tmp;
      for (auto f : cnt) {
        if (num[i] % f.first == 0) {
          tmp[num[i] / f.first]++;
          tmp[f.first]++;
          num[i] = 1;
        }
      }
      for (auto i : tmp) cnt[i.first] += i.second;
    }
  }
  map<long long, long long> pr;
  for (long long i = 0; i < n; i++)
    if (num[i] != 1) pr[num[i]]++;
  long long ans = 1;
  for (auto i : pr) {
    if (i.first == 1) continue;
    ans *= ((i.second + 1) * (i.second + 1));
    ans %= 998244353;
  }
  for (auto i : cnt) {
    if (i.first == 1) continue;
    ans *= i.second + 1;
    ans %= 998244353;
  }
  cout << ans;
  return 0;
}
