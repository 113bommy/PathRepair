#include <bits/stdc++.h>
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline void sub(long long &a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
}
inline void add(long long &a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
template <typename T>
inline T const &MAX(T const &a, T const &b) {
  return a > b ? a : b;
}
template <typename T>
inline T const &MIN(T const &a, T const &b) {
  return a < b ? a : b;
}
inline long long mul(long long a, long long b, long long c) {
  return (a * b - (long long)((long double)a * b / c) * c + c) % c;
}
inline long long qp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    a = a * a % 1000000007, b >>= 1;
  }
  return ans;
}
inline long long qp(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a, c);
    a = mul(a, a, c), b >>= 1;
  }
  return ans;
}
using namespace std;
const long double pi = acos(-1);
const unsigned long long ba = 233;
const double eps = 1e-5;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 200000 + 10, maxn = 2000000 + 10, inf = 0x3f3f3f3f;
long long a[N], f[N], inv[N], po[N];
long long c(int a, int b) {
  if (a < 0 || a < b) return 0;
  return f[a] * inv[b] % 1000000007 * inv[a - b] % 1000000007;
}
int main() {
  f[0] = inv[0] = po[0] = 1;
  for (int i = 1; i < N; i++)
    f[i] = f[i - 1] * i % 1000000007,
    inv[i] = inv[i - 1] * qp(i, 1000000007 - 2) % 1000000007,
    po[i] = po[i - 1] * 2 % 1000000007;
  int n;
  long long t;
  scanf("%d%lld", &n, &t);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += a[i - 1];
  long long ans = 0, now = 1, k = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > t)
      break;
    else if (a[i] + i <= t) {
      add(ans, 1);
      now = now * 2 % 1000000007, sub(now, c(i - 1, ++k));
    } else {
      long long x = t - a[i];
      now = now * 2 % 1000000007;
      sub(now, c(i - 1, ++k));
      while (k > x) sub(now, c(i, k--));
      while (k < x) sub(now, c(i, ++k));
      add(ans, now * qp(po[i], 1000000007 - 2) % 1000000007);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
