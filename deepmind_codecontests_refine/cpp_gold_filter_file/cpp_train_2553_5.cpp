#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool umin(T1& x, const T2& y) {
  return (x > y ? (x = y, true) : false);
}
template <typename T1, typename T2>
bool umax(T1& x, const T2& y) {
  return (x < y ? (x = y, true) : false);
}
template <typename T>
void read(T& x) {
  char ch;
  T p = 1;
  x = 0;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') p = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= p;
}
void read(string& x) {
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  while (ch > ' ') x += ch, ch = getchar();
}
void read(char& x) {
  do {
    x = getchar();
  } while (x <= ' ');
}
template <typename T, typename... R>
void read(T& x, R&... y) {
  read(x);
  read(y...);
}
const int N = (int)1e6 + 3;
const int INF = (int)1e9 + 17;
const long long mod = (long long)1e9 + 7;
const long long LLINF = (long long)1e18 + 17;
const long double pi = (long double)acos(-1.0);
int n, k, q;
int res;
int cnt[N];
int binpow(int x, int y) {
  int ret = 1;
  while (y > 0) {
    if (y % 2 != 0) ret = 1ll * ret * x % mod;
    x = 1ll * x * x % mod;
    y /= 2;
  }
  return ret;
}
int phi[N];
int fact[N];
int invfact[N];
int calcPhi(int n) {
  int ret = n;
  for (int d = 2; d * d <= n; ++d) {
    if (n % d != 0) continue;
    while (n % d == 0) n /= d;
    ret -= ret / d;
  }
  if (n > 1) ret -= ret / n;
  return ret;
}
void prepare() {
  fact[0] = 1;
  invfact[0] = 1;
  for (int i = (1); i < (N); i++) {
    phi[i] = calcPhi(i);
    fact[i] = 1ll * fact[i - 1] * i % mod;
    invfact[i] = binpow(fact[i], mod - 2);
  }
}
int C(int n, int k) {
  if (n < k) return 0;
  return (1ll * fact[n] * invfact[k]) % mod * invfact[n - k] % mod;
}
void add(int x) {
  auto update = [&](int div) {
    res = (res - 1ll * phi[div] * C(cnt[div], k) % mod + mod) % mod;
    ++cnt[div];
    res = (res + 1ll * phi[div] * C(cnt[div], k)) % mod;
  };
  for (int d = 1; d * d <= x; ++d) {
    if (x % d != 0) continue;
    update(d);
    if (x / d != d) update(x / d);
  }
}
int main() {
  prepare();
  read(n, k, q);
  while (n-- > 0) {
    int x;
    read(x);
    add(x);
  }
  while (q-- > 0) {
    int x;
    read(x);
    add(x);
    printf("%d\n", res);
  }
  return 0;
}
