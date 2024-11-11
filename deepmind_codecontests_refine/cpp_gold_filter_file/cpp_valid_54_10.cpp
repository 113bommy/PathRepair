#include <bits/stdc++.h>
using namespace std;
const int maxn = 400010;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
const double Pi = acos(-1.0);
int n, m, k, t;
long long fact[maxn], invFact[maxn];
int dir[][2] = {{0, 0},  {0, 1},   {-1, 0}, {0, -1}, {1, 0},
                {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
inline void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
inline int gcd(int x, int y) {
  if (!x) return y;
  return gcd(y % x, x);
}
inline long long power(long long x, long long k, long long p) {
  long long res = 1;
  for (; k; k >>= 1, x = (long long)x * x % p)
    if (k & 1) res = (long long)res * x % p;
  return res;
}
long long A(int n, int k) {
  if (k > n) {
    return 0;
  }
  return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}
void solve() {
  n = read();
  k = read();
  fact[0] = invFact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (fact[i - 1]) * i % mod;
    invFact[i] = power(fact[i], mod - 2, mod);
  }
  long long ji = 0, ou = 0;
  for (int i = 0; i <= n; ++i) {
    if (i % 2) {
    } else {
      ou = (ou + A(n, i)) % mod;
    }
  }
  long long nn = power(2, n, mod);
  long long ans = 0;
  if (n % 2 == 1)
    ans++;
  else
    ou--;
  ans = (ans + ou) % mod;
  long long now = power(ans, k, mod);
  if (n % 2 == 0) {
    for (int i = k; i >= 1; --i) {
      now += power(nn, i - 1, mod) * power(ans, k - i, mod);
      now %= mod;
    }
  }
  printf("%lld\n", now);
  return;
}
int main() {
  t = read();
  while (t--) {
    solve();
  }
  return 0;
}
